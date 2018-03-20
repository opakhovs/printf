/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   works.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:31:33 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:33:31 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_line_zbp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;

	nstr = ft_strnew(flags->bp);
	i = -1;
	size = ft_strlen(*str);
	if ((int)ft_strlen(*str) < flags->bp)
	{
		while (++i < flags->bp - size)
			nstr[i] = 48;
		i--;
		while (++i < flags->bp)
			nstr[i] = *((*str) + i - (flags->bp - size));
		nstr[flags->bp] = '\0';
		free_locate(str);
		*str = ft_strnew(flags->bp);
		ft_strncpy(*str, nstr, flags->bp);
	}
	free_locate(&nstr);
}

void	s_line_bp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;

	nstr = ft_strnew(flags->bp + 1);
	i = -1;
	size = ft_strlen(*str);
	if (size < flags->bp)
	{
		while (++i < flags->bp - size)
			nstr[i] = 32;
		i--;
		while (++i < flags->bp)
			nstr[i] = *((*str) + i - (flags->bp - size));
		nstr[flags->bp] = '\0';
		free_locate(str);
		*str = ft_strnew(flags->bp + 1);
		ft_strcpy(*str, nstr);
	}
	free_locate(&nstr);
}

void	s_line_mbp(char **str, t_flags *flags)
{
	char	*nstr;
	int		size;
	int		i;

	nstr = ft_strnew(flags->bp + 1);
	i = -1;
	size = ft_strlen(*str);
	if ((int)ft_strlen(*str) <= flags->bp)
	{
		while (++i < size)
			nstr[i] = *((*str) + i);
		i--;
		while (++i < flags->bp)
			nstr[i] = 32;
		nstr[flags->bp] = '\0';
		free_locate(str);
		*str = ft_strnew(flags->bp + 1);
		ft_strcpy(*str, nstr);
	}
	free_locate(&nstr);
}

void	operate_s_line(char **str, t_flags *flags, int check)
{
	if (flags->space > 0 && check == 1)
		d_line_space(str, flags, check);
	if (flags->p == 1 && flags->ap == 0)
	{
		free_locate(str);
		*str = ft_strnew(1);
	}
	else if (flags->p == 1 && flags->ap != 0)
		s_line_pap(str, flags);
	if (flags->bp > 0 && flags->minus == 0 && flags->zero == 1)
		s_line_zbp(str, flags);
	else if (flags->bp > 0 && flags->minus == 0)
		s_line_bp(str, flags);
	else if (flags->bp > 0 && flags->minus == 1)
		s_line_mbp(str, flags);
}

int		s_line(va_list *valist, t_flags *flags, char ***res)
{
	char	*str;
	char	*temp;
	int		size;

	temp = va_arg(*valist, char *);
	if (!temp)
	{
		str = ft_strnew(7);
		ft_strcpy(str, "(null)");
	}
	else if (*temp != '\0')
	{
		str = ft_strnew(ft_strlen(temp));
		ft_strncpy(str, temp, ft_strlen(temp));
	}
	else
		str = ft_strnew(1);
	operate_s_line(&str, flags, 1);
	resize_res(res, ft_strlen(str), str);
	size = ft_strlen(str);
	free_locate(&str);
	return (size);
}
