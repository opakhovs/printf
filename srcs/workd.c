/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:57:18 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 16:57:20 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	d_line_mbp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;

	nstr = ft_strnew(flags->bp + 1);
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
		str_2(str, &nstr, flags);
	}
	free_locate(&nstr);
}

void	d_line_plus(char **str)
{
	char	*nstr;
	int		size;
	int		i;

	if (ft_strcmp(*str, "") != 0 && *(*str) != '-')
	{
		size = ft_strlen(*str);
		nstr = ft_strnew(size + 1);
		i = -1;
		nstr[0] = '+';
		while (++i < size)
			nstr[i + 1] = *((*str) + i);
		nstr[size + 1] = '\0';
		free_locate(str);
		*str = ft_strnew(ft_strlen(nstr));
		ft_strcpy(*str, nstr);
		free_locate(&nstr);
	}
}

void	operate_d_line(char **str, t_flags *flags, int check, int zero)
{
	if (flags->plus == 1)
		d_line_plus(str);
	else if (flags->space > 0)
		d_line_space(str, flags, check);
	if (flags->p == 1 && flags->ap != 0)
		d_line_pap(str, flags);
	else if (flags->p == 1 && flags->ap == 0 && zero == 0)
	{
		free_locate(str);
		*str = ft_strnew(1);
	}
	if (flags->bp > 0 && flags->minus == 0 && flags->zero == 1 && flags->p == 0)
		d_line_zbp(str, flags);
	else if (flags->bp > 0 && flags->minus == 0)
		d_line_bp(str, flags);
	else if (flags->bp > 0 && flags->minus == 1)
		d_line_mbp(str, flags);
}

int		d_line(va_list *valist, t_flags *flags, char ***res)
{
	long long int	num;
	char			*str;
	int				size;

	if (flags->l == 1)
		num = va_arg(*valist, long int);
	else if (flags->ll == 1)
		num = va_arg(*valist, long long int);
	else if (flags->j == 1)
		num = va_arg(*valist, intmax_t);
	else if (flags->z == 1)
		num = va_arg(*valist, size_t);
	else
		num = va_arg(*valist, int);
	if (flags->hh == 1 && CHECK)
		num = (signed char)num;
	else if (flags->h == 1 && CHECK)
		num = (short int)num;
	str = putnbr(num);
	(num == 0) ? operate_d_line(&str, flags, 0, 0) :
	operate_d_line(&str, flags, 0, 1);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}

int		dd_line(va_list *valist, t_flags *flags, char ***res)
{
	long long int	num;
	char			*str;
	int				size;

	num = va_arg(*valist, long int);
	str = putnbr(num);
	(num == 0) ? operate_d_line(&str, flags, 0, 0) :
	operate_d_line(&str, flags, 0, 1);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}
