/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workls.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:05:42 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 17:05:44 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_line_pap(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;

	nstr = ft_strnew(flags->ap + 1);
	i = -1;
	size = ft_strlen(*str);
	if (size > flags->ap)
		while (++i < flags->ap)
			nstr[i] = *((*str) + i);
	else
		while (++i < size)
			nstr[i] = *((*str) + i);
	nstr[flags->ap] = '\0';
	free_locate(str);
	*str = ft_strnew(flags->ap);
	ft_strcpy(*str, nstr);
	free_locate(&nstr);
}

int		wstr_to_str(wchar_t *str, char **temp, t_flags *flags)
{
	int		i;
	size_t	strlen;

	i = 0;
	while (*str)
	{
		if (MB_CUR_MAX == 1 && *str > 0xFF)
			free_locate(temp);
		if (MB_CUR_MAX == 1 && *str > 0xFF)
			return (-1);
		if (*str <= 0x7F)
			strlen = 1;
		else if (*str <= 0x7FF)
			strlen = 2;
		else if (*str <= 0xFFFF)
			strlen = 3;
		else if (*str <= 0x10FFFF)
			strlen = 4;
		if (flags->ap != 0 && (flags->ap < (int)(ft_strlen(*temp) + strlen)))
			break ;
		ft_putwchar_in_char(*str, temp, i);
		str++;
		i += strlen;
	}
	return (0);
}

int		copy_c_line(t_flags *flags, char ***res, int **p, char c)
{
	char	*str;
	int		size;

	str = ft_strnew(3);
	str[0] = c;
	if (str[0] == 0)
	{
		flags->bp--;
		flags->space = 0;
		operate_s_line(&str, flags, 0);
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

void	operate_ss_line(char **str, t_flags *flags)
{
	if (flags->space > 0)
		d_line_space(str, flags, 1);
	if (flags->p == 1 && flags->ap == 0)
	{
		free_locate(str);
		*str = ft_strnew(1);
	}
	if (flags->bp > 0 && flags->minus == 0 && flags->zero == 1)
		s_line_zbp(str, flags);
	else if (flags->bp > 0 && flags->minus == 0)
		s_line_bp(str, flags);
	else if (flags->bp > 0 && flags->minus == 1)
		s_line_mbp(str, flags);
}

int		ss_line(va_list *valist, t_flags *flags, char ***res)
{
	wchar_t	*str;
	char	*temp;
	int		strlen;
	int		size;

	str = va_arg(*valist, wchar_t *);
	strlen = ft_wstrlen(str);
	if (strlen == -1)
	{
		str = NULL;
		return (0);
	}
	temp = ft_strnew(strlen + 1);
	if (str == NULL)
		str = L"(null)";
	if (wstr_to_str(str, &temp, flags) == -1)
		return (-1);
	operate_ss_line(&temp, flags);
	resize_res(res, ft_strlen(temp), temp);
	size = ft_strlen(temp);
	free(temp);
	str = NULL;
	temp = NULL;
	return (size);
}
