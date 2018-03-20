/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:39:56 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:39:58 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	resize_res(char ***res, int length, char *str)
{
	char	**temp;
	int		size;
	int		i;

	size = ft_strcount(res);
	i = -1;
	temp = (char **)malloc(sizeof(char *) * (size + 1));
	while (++i < size)
	{
		temp[i] = ft_strnew(ft_strlen((*res)[i]));
		ft_strcpy(temp[i], (*res)[i]);
	}
	temp[i] = NULL;
	freestr(res);
	(*res) = (char **)malloc(sizeof(char *) * (size + 2));
	i = -1;
	while (++i < size)
	{
		(*res)[i] = ft_strnew(ft_strlen(temp[i]));
		ft_strcpy((*res)[i], temp[i]);
	}
	(*res)[i] = ft_strnew(length);
	ft_strcpy((*res)[i], str);
	(*res)[i + 1] = NULL;
	freestr(&temp);
}

void	resize_dog(char ***res, int **p)
{
	int		j;
	int		i;
	int		size;
	int		*temp;

	size = ft_strcount(res);
	i = 0;
	j = -1;
	while ((*p)[i] != 0)
		i++;
	temp = (int *)malloc(sizeof(int) * (i + 2));
	while ((*p)[++j] != 0)
		temp[j] = (*p)[j];
	temp[j] = size + i + 1;
	temp[j + 1] = 0;
	free(*p);
	*p = NULL;
	*p = (int *)malloc(sizeof(int) * (i + 2));
	j = -1;
	while (temp[++j] != 0)
		(*p)[j] = temp[j];
	(*p)[j] = 0;
	free(temp);
	temp = NULL;
}

char	*ft_min(void)
{
	char	*str;

	str = ft_strnew(21);
	ft_strcpy(str, "-9223372036854775808");
	return (str);
}

size_t	ft_greater(size_t strlen, t_flags *flags)
{
	if (!flags->bp)
	{
		if ((size_t)flags->bp > strlen)
			return (flags->bp);
		return (strlen);
	}
	else
	{
		if ((size_t)flags->ap > strlen)
			return (flags->ap);
		return (strlen);
	}
}

int		ft_atoii(const char *format, int *i)
{
	int		res;

	res = 0;
	while (format[*i] >= '0' && format[*i] <= '9')
	{
		res = (res * 10) + (format[*i] - 48);
		(*i)++;
	}
	(*i)--;
	return (res);
}
