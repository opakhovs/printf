/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adittion_pr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 14:55:42 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/19 15:20:07 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_last_line(char ***res)
{
	char	**temp;
	int		size;
	int		i;

	size = ft_strcount(res);
	i = 0;
	temp = (char **)malloc(sizeof(char *) * (size));
	while (i < size - 1)
	{
		temp[i] = ft_strnew(ft_strlen((*res)[i]));
		ft_strcpy(temp[i], (*res)[i]);
		i++;
	}
	temp[i] = NULL;
	freestr(res);
	(*res) = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (i < size - 1)
	{
		(*res)[i] = ft_strnew(ft_strlen(temp[i]));
		ft_strcpy((*res)[i], temp[i]);
		i++;
	}
	(*res)[i] = NULL;
	freestr(&temp);
}

char	ft_last_elem(char ***res)
{
	int		i;
	char	c;

	i = 0;
	while (*((*res) + i))
		i++;
	c = (**((*res) + i - 1));
	free_last_line(res);
	return (c);
}

int		sym_add(char ***res, char c, int length)
{
	char	*str;

	str = ft_strnew(2);
	(str)[0] = c;
	(str)[1] = '\0';
	resize_res(res, 2, str);
	free_locate(&str);
	return (length + 1);
}
