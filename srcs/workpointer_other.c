/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workpointer_other.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:35:46 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:35:48 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	n_line(va_list *valist, int size)
{
	int		*num;

	if (!(num = va_arg(*valist, void *)))
		return ;
	if (!num)
		return ;
	*num = size;
}

void	p_line_pap(char **str, t_flags *flags)
{
	int		size;
	int		i;
	int		j;
	char	*nstr;

	nstr = ft_strnew(flags->ap + 2);
	i = -1;
	size = (*(*str + 1) == 'x') ? (ft_strlen(*str) - 2) : ft_strlen(*str);
	if (size < flags->ap)
	{
		nstr[0] = '0';
		nstr[1] = 'x';
		i += 2;
		flags->ap = flags->ap + 1 + i;
		j = i;
		while (++i < flags->ap - size)
			nstr[i] = '0';
		while (i < flags->ap)
			nstr[i++] = (*str)[++j];
		nstr[flags->ap] = '\0';
		free_locate(str);
		*str = ft_strnew(flags->ap);
		ft_strncpy(*str, nstr, flags->ap);
	}
	free_locate(&nstr);
}

void	p_line_zbp(char **str, t_flags *flags)
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

void	p_line_bp(char **str, t_flags *flags)
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
		free_locate(str);
		*str = ft_strnew(flags->bp);
		ft_strcpy(*str, nstr);
	}
	free_locate(&nstr);
}
