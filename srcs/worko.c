/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worko.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:28:13 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 17:28:14 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	o_line_hash(char **str)
{
	char	*nstr;
	int		size;
	int		i;

	size = ft_strlen(*str);
	nstr = ft_strnew(size + 1);
	i = -1;
	nstr[0] = '0';
	while (++i < size)
		nstr[i + 1] = *((*str) + i);
	nstr[size + 1] = '\0';
	free_locate(str);
	*str = ft_strnew(ft_strlen(nstr));
	ft_strncpy(*str, nstr, size + 1);
	free_locate(&nstr);
}

void	operate_o_line(char **str, t_flags *flags, uintmax_t num)
{
	if (flags->hash == 1 && num != 0
		&& (((int)ft_strlen(*str) + 1 < flags->bp) || num != 0)
		&& (((int)ft_strlen(*str) + 1 < flags->ap) || num != 0))
	{
		o_line_hash(str);
		if (flags->p == 1 && flags->ap != 0 && flags->hash == 1)
			d_line_pap(str, flags);
	}
	else if (flags->p == 1 && flags->ap != 0)
		d_line_pap(str, flags);
	else if (flags->p == 1 && flags->ap == 0 && num == 0)
	{
		free_locate(str);
		*str = ft_strnew(1);
		if (flags->hash == 1)
			o_line_hash(str);
	}
	if (flags->bp > 0 && flags->minus == 0 && flags->zero == 1 && flags->p == 0)
		d_line_zbp(str, flags);
	else if (flags->bp > 0 && flags->minus == 0)
		d_line_bp(str, flags);
	else if (flags->bp > 0 && flags->minus == 1)
		d_line_mbp(str, flags);
}

int		o_line(va_list *valist, t_flags *flags, char ***res)
{
	uintmax_t	num;
	char		*str;
	int			size;

	if (flags->l == 1)
		num = va_arg(*valist, unsigned long int);
	else if (flags->ll == 1)
		num = va_arg(*valist, unsigned long long int);
	else if (flags->j == 1)
		num = va_arg(*valist, uintmax_t);
	else if (flags->z == 1)
		num = va_arg(*valist, size_t);
	else
		num = va_arg(*valist, unsigned int);
	if (flags->hh == 1)
		num = (unsigned char)num;
	else if (flags->h == 1)
		num = (unsigned short int)num;
	str = o_putnbr(num);
	operate_o_line(&str, flags, num);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}

int		oo_line(va_list *valist, t_flags *flags, char ***res)
{
	uintmax_t	num;
	char		*str;
	int			size;

	if (flags->l == 1)
		num = va_arg(*valist, unsigned long int);
	else if (flags->ll == 1)
		num = va_arg(*valist, unsigned long long int);
	else if (flags->j == 1)
		num = va_arg(*valist, uintmax_t);
	else if (flags->z == 1)
		num = va_arg(*valist, size_t);
	else
		num = va_arg(*valist, unsigned long int);
	str = o_putnbr(num);
	operate_o_line(&str, flags, num);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}
