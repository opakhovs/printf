/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:33:42 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/05 15:05:33 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		an_part1(va_list *va, t_flags fl, char ***r, int **p)
{
	int		l;
	int		c;
	char	*s;

	l = 0;
	s = ft_strnew(2);
	s[0] = ft_last_elem(r);
	if ((fl.l == 1 && s[0] == 's') || s[0] == 'S')
	{
		c = l;
		if (((c - 1) == (l = ss_line(va, &fl, r))) && (free_res(r, p, &s)))
			return (-1);
	}
	else if (s[0] == 's')
		l = s_line(va, &fl, r);
	else if (s[0] == 'C' || (fl.l == 1 && s[0] == 'c'))
	{
		c = l;
		if (((c - 1) == (l = cc_line(va, &fl, r, p))) && (free_res(r, p, &s)))
			return (-1);
	}
	else if (s[0] == 'c')
		l = c_line(va, &fl, r, p);
	free_locate(&s);
	return (l);
}

int		an_part2(char c, va_list *valist, t_flags flags, char ***res)
{
	if (c == 'p')
		return (p_line(valist, &flags, res));
	else if (c == 'i' || c == 'd')
		return (d_line(valist, &flags, res));
	else if (c == '%')
		return (per_line(&flags, res));
	else if (c == 'o')
		return (o_line(valist, &flags, res));
	else if (c == 'x')
		return (x_line(valist, &flags, res));
	else if (c == 'X')
		return (xx_line(valist, &flags, res));
	else if (c == 'u')
		return (u_line(valist, &flags, res));
	else if (c == 'U')
		return (uu_line(valist, &flags, res));
	else if (c == 'D')
		return (dd_line(valist, &flags, res));
	else if (c == 'O')
		return (oo_line(valist, &flags, res));
	//else if (c == 'n')
	else if (c != 's' && c != 'S' && c != 'c' && c != 'C')
		return (no_line(&flags, c, res));
	return (0);
}

int		cycle(va_list *valist, const char *format,
	char ***res, int **p)
{
	t_flags	flags;
	int		i;
	int		ch;
	int		len;

	i = -1;
	len = 0;
	while (format[++i])
	{
		if (format[i] == '%')
		{
			flags = check_flags(format, &(i), valist);
			if (!format[i])
				break ;
			ch = len;
			sym_add(res, format[i], len);
			if ((len += an_part1(valist, flags, res, p)) == ch - 1)
				return (-1);
			if (ch == len)
				len += an_part2(format[i], valist, flags, res);
		}
		else
			len = sym_add(res, format[i], len);
	}
	return (len);
}

int		analyser(va_list *valist, const char *format)
{
	int		length;
	char	*str;
	char	**res;
	int		*p;

	str = ft_strnew(2);
	res = (char **)malloc(sizeof(char *) * 1);
	res[0] = NULL;
	p = (int *)malloc(sizeof(int));
	*p = 0;
	length = cycle(valist, format, &res, &p);
	if (length == -1)
	{
		free(str);
		str = NULL;
		return (-1);
	}
	print(res, p);
	free_res(&res, &p, &str);
	return (length);
}

int		ft_printf(const char *format, ...)
{
	va_list	valist;
	size_t	length;

	length = 0;
	if (format)
	{
		va_start(valist, format);
		length = analyser(&valist, format);
		va_end(valist);
	}
	return (length);
}
