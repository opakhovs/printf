/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_no_mat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:41:29 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:41:31 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	dcycle(t_flags *flags, int *i, int *j)
{
	flags->bp = flags->bp + 1 + *i;
	*i = ((*i == -1) || (*i == 0)) ? *i + 1 : *i;
	*j = *i;
}

void	str_1(char **str, char **nstr, t_flags *flags)
{
	free_locate(str);
	*str = ft_strnew(flags->ap);
	ft_strcpy(*str, *nstr);
}

void	str_2(char **str, char **nstr, t_flags *flags)
{
	free_locate(str);
	*str = ft_strnew(flags->bp);
	ft_strcpy(*str, *nstr);
}

int		no_line(t_flags *flags, char c, char ***res)
{
	char	*str;
	char	*ch;
	int		size;

	ch = ft_strnew(2);
	if (--flags->bp > 0)
		str = ft_strnew(flags->bp);
	else if (flags->ap > 0)
		str = ft_strnew(flags->ap);
	else
		str = ft_strnew(1);
	operate_s_line(&str, flags, 1);
	ch[0] = c;
	ch[1] = '\0';
	if (flags->minus == 1)
		resize_res(res, ft_strlen(ch), ch);
	resize_res(res, ft_strlen(str), str);
	if (flags->minus == 0)
		resize_res(res, ft_strlen(ch), ch);
	size = 1 + ft_strlen(str);
	free_locate(&str);
	free_locate(&ch);
	return (size);
}
