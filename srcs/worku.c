/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   worku.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:19:01 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 17:19:03 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	operate_u_line(char **str, t_flags *flags, int check, uintmax_t num)
{
	if (flags->space > 0)
		d_line_space(str, flags, check);
	if (flags->p == 1 && flags->ap != 0)
		d_line_pap(str, flags);
	else if (flags->p == 1 && flags->ap == 0 && num == 0)
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

int		u_line(va_list *valist, t_flags *flags, char ***res)
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
	str = u_putnbr(num);
	operate_u_line(&str, flags, 1, num);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}

int		uu_line(va_list *valist, t_flags *flags, char ***res)
{
	uintmax_t	num;
	char		*str;
	int			size;

	num = va_arg(*valist, unsigned long);
	str = u_putnbr(num);
	operate_u_line(&str, flags, 1, num);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}
