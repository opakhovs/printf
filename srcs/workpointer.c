/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workpointer.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 19:02:11 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 19:02:13 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	p_line_mbp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;

	nstr = ft_strnew(flags->bp);
	i = -1;
	size = ft_strlen(*str);
	if ((int)ft_strlen(*str) < flags->bp)
	{
		while (++i < size)
			nstr[i] = *((*str) + i);
		i--;
		while (++i < flags->bp)
			nstr[i] = 32;
		nstr[flags->bp] = '\0';
		free_locate(str);
		*str = ft_strnew(flags->bp);
		ft_strcpy(*str, nstr);
	}
	free_locate(&nstr);
}

void	p_rewrite(char **str)
{
	char	*nstr;
	int		size;
	int		i;
	int		j;

	i = 1;
	j = 0;
	size = ft_strlen(*str);
	nstr = ft_strnew(size + 6);
	nstr[0] = '0';
	nstr[1] = 'x';
	while (++i < size + 2)
		nstr[i] = (*((*str) + (j++)));
	nstr[i] = '\0';
	free_locate(str);
	*str = ft_strnew(ft_strlen(nstr));
	ft_strcpy(*str, nstr);
	free_locate(&nstr);
}

void	p_anrewrite(char **str)
{
	char	*nstr;
	int		size;
	int		i;
	int		j;

	i = 5;
	j = 8;
	size = ft_strlen(*str);
	nstr = ft_strnew(size + 6);
	nstr[0] = '0';
	nstr[1] = 'x';
	nstr[2] = '7';
	nstr[3] = 'f';
	nstr[4] = 'f';
	nstr[5] = 'f';
	while (++i < 14)
		nstr[i] = (*((*str) + (size - j--)));
	nstr[i] = '\0';
	free_locate(str);
	*str = ft_strnew(ft_strlen(nstr));
	ft_strcpy(*str, nstr);
	free_locate(&nstr);
}

void	operate_p_line(char **str, t_flags *flags)
{
	if (ft_strlen(*str) < 14 && *(*str + 1) != 'x')
		p_rewrite(str);
	else if (ft_strlen(*str) > 14 && *(*str + 1) != 'x')
		p_anrewrite(str);
	if (flags->ap != 0)
		p_line_pap(str, flags);
	if (flags->bp > 0 && flags->minus == 0 && flags->zero == 1 && flags->p == 0)
		p_line_zbp(str, flags);
	else if (flags->bp > 0 && flags->minus == 0)
		p_line_bp(str, flags);
	else if (flags->bp > 0 && flags->minus == 1)
		p_line_mbp(str, flags);
}

int		p_line(va_list *valist, t_flags *flags, char ***res)
{
	char			*str;
	long long int	pointer;
	int				size;

	pointer = va_arg(*valist, long long int);
	if (pointer == 0 && flags->p == 1)
	{
		str = ft_strnew(3);
		ft_strcpy(str, "0x");
	}
	else if (pointer == 0)
	{
		str = ft_strnew(4);
		ft_strcpy(str, "0x0");
	}
	else
		str = x_putnbr(pointer);
	operate_p_line(&str, flags);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}
