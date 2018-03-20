/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workpercent.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:23:48 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 17:23:49 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	operate_per_line(char **str, t_flags *flags, int check)
{
	if (flags->space > 0 && check == 1)
		d_line_space(str, flags, check);
	if (flags->p == 1 && flags->ap != 0)
		s_line_pap(str, flags);
	if (flags->bp > 0 && flags->minus == 0 && flags->zero == 1)
		s_line_zbp(str, flags);
	else if (flags->bp > 0 && flags->minus == 0)
		s_line_bp(str, flags);
	else if (flags->bp > 0 && flags->minus == 1)
		s_line_mbp(str, flags);
}

int		per_line(t_flags *flags, char ***res)
{
	char	*str;
	int		size;

	str = ft_strnew(2);
	str[0] = '%';
	operate_per_line(&str, flags, 1);
	if (ft_strcmp(str, "") == 0)
		str[0] = '%';
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}
