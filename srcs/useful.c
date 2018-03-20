/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 17:16:59 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 17:17:00 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	free_locate(char **str)
{
	free(*str);
	*str = NULL;
}

int		freew(wchar_t **str)
{
	free(*str);
	*str = NULL;
	return (1);
}

void	freestr(char ***res)
{
	int		j;
	int		k;

	j = 0;
	k = 0;
	while (*((*res) + k))
		k++;
	while (j < k)
	{
		free(*((*res) + j));
		*((*res) + j) = NULL;
		j++;
	}
	free((*res));
	(*res) = NULL;
}

int		ft_strcount(char ***res)
{
	int		size;

	size = 0;
	while ((*res)[size])
		size++;
	return (size);
}

int		ft_strlenl(wchar_t *str)
{
	int		i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}
