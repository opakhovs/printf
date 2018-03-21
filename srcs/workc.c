/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workc.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:22:25 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 17:22:26 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_rewrite(char **temp, int size)
{
	int		count;
	char	*str;

	count = 0;
	str = ft_strnew(size + 1);
	ft_strncpy(str, *temp, size);
	free_locate(temp);
	*temp = ft_strnew(size + 1);
	ft_strcpy(*temp, str);
	free_locate(&str);
}

int		c_line(va_list *valist, t_flags *flags, char ***res, int **p)
{
	char	*str;
	int		size;

	str = ft_strnew(2);
	str[0] = va_arg(*valist, int);
	str[1] = '\0';
	if (str[0] == 0)
	{
		flags->bp--;
		flags->space = 0;
		operate_s_line(&str, flags, 0);
		if (flags->minus == 1)
			resize_dog(res, p);
		resize_res(res, ft_strlen(str), str);
		if (flags->minus == 0)
			resize_dog(res, p);
		size = ft_strlen(str);
		free_locate(&str);
		return (1 + size);
	}
	operate_s_line(&str, flags, 0);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}

int		cc_line(va_list *valist, t_flags *flags, char ***res, int **p)
{
	wchar_t	*str;
	size_t	strlen;
	char	*temp;
	int		size;
	char	c;

	str = ft_wstrnew(2);
	str[0] = va_arg(*valist, int);
	str[1] = '\0';
	strlen = (ft_wstrlen(str) == 0 && str[0] == 0) ? 1 : ft_wstrlen(str);
	if (((strlen == 0) || (MB_CUR_MAX == 1 && str[0] > 255)) && (freew(&str)))
		return (-1);
	if (strlen == 1)
		c = str[0];
	if (strlen == 1 && freew(&str))
		return (copy_c_line(flags, res, p, c));
	temp = ft_strnew(strlen + 1);
	ft_putwchar_in_char(*str, &temp, 0);
	operate_s_line(&temp, flags, 0);
	resize_res(res, ft_strlen(temp), temp);
	size = ft_strlen(temp);
	freew(&str);
	free_locate(&temp);
	return (size);
}
