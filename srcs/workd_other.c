/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workd_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:40:24 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:40:26 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_line_space(char **str, t_flags *flags, int check)
{
	char	*nstr;
	int		size;
	int		i;

	if (*(*str) != '-' && check != 1)
	{
		size = ft_strlen(*str);
		nstr = ft_strnew(size + 2);
		i = -1;
		if (flags->space > 0)
			nstr[++i] = ' ';
		while (++i < size + 2)
			nstr[i] = (*str)[i - 1];
		nstr[size + 2] = '\0';
		free_locate(str);
		*str = ft_strnew(ft_strlen(nstr));
		ft_strncpy(*str, nstr, size + 2);
		free_locate(&nstr);
	}
}

void	d_line_bp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;
	int		j;

	nstr = ft_strnew(flags->bp + 2);
	i = -1;
	size = ft_strlen(*str);
	if ((int)ft_strlen(*str) < flags->bp)
	{
		j = i;
		while (++i < flags->bp - size)
			nstr[i] = ' ';
		while (i < flags->bp)
			nstr[i++] = (*str)[++j];
		nstr[flags->bp] = '\0';
		str_2(str, &nstr, flags);
	}
	free_locate(&nstr);
}

void	d_line_pap(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;
	int		j;

	nstr = ft_strnew(flags->ap + 2);
	i = -1;
	if (*(*str + 1) == 'x')
		return (p_line_pap(str, flags));
	size = (*(*str) == '-' || *(*str) == '+' || *(*str) == ' ')
	? (ft_strlen(*str) - 1) : ft_strlen(*str);
	if (size < flags->ap)
	{
		if (*str[0] == '-' || *str[0] == '+' || *str[0] == ' ')
			nstr[0] = *str[++i];
		flags->ap = flags->ap + 1 + i;
		j = i;
		while (++i < flags->ap - size)
			nstr[i] = '0';
		while (i < flags->ap)
			nstr[i++] = (*str)[++j];
		nstr[flags->ap] = '\0';
		str_1(str, &nstr, flags);
	}
	free_locate(&nstr);
}

void	d_line_zbp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;
	int		j;

	nstr = ft_strnew(flags->bp + 2);
	size = ft_strlen(*str);
	if ((int)ft_strlen(*str) < flags->bp && (i = -1))
	{
		if (*(*str) == '0' && (*((*str) + 1) == 'x'
			|| *((*str) + 1) == 'X') && flags->bp--)
			while (++i < 2)
				nstr[i] = *((*str) + i);
		else if ((*(*str) == '-') || (*(*str) == '+')
			|| (*(*str) == ' ') || *(*str) == '0')
			nstr[0] = *str[++i];
		dcycle(flags, &i, &j);
		while (i < flags->bp - size)
			nstr[i++] = '0';
		while (i < flags->bp)
			nstr[i++] = (*str)[j++];
		nstr[flags->bp] = '\0';
		str_2(str, &nstr, flags);
	}
	free_locate(&nstr);
}
