/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_and_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:39:27 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:39:31 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_flags	new_flags(void)
{
	t_flags flags;

	flags.plus = 0;
	flags.minus = 0;
	flags.bp = 0;
	flags.p = 0;
	flags.ap = 0;
	flags.space = 0;
	flags.zero = 0;
	flags.z = 0;
	flags.j = 0;
	flags.l = 0;
	flags.ll = 0;
	flags.h = 0;
	flags.hh = 0;
	flags.hash = 0;
	return (flags);
}

int		is_correct_flag(const char *fo, int *i, t_flags *flags)
{
	if (flags1(fo, i, flags) == 1)
		return (1);
	if (flags2(fo, i, flags) == 1)
		return (1);
	if (flags3(fo, i, flags) == 1)
		return (1);
	if (flags4(fo, i, flags) == 1)
		return (1);
	return (0);
}

t_flags	check_flags(const char *format, int *i)
{
	t_flags	flags;

	flags = new_flags();
	(*i)++;
	while ((int)ft_strlen(format) > *i
		&& is_correct_flag(format, i, &flags) == 1)
		(*i)++;
	return (flags);
}

void	print(char **res, int *p)
{
	int		i;
	int		j;
	int		size;
	int		k;

	i = -1;
	j = 0;
	size = 0;
	while (res[j++])
		size++;
	j = 0;
	while (p[j++] != 0)
		size++;
	j = 0;
	k = 0;
	while (++i < size)
	{
		if (i + 1 == p[j])
		{
			write(1, "\0", 1);
			j++;
		}
		else
			ft_putstr(res[k++]);
	}
}

int		free_res(char ***res, int **p, char **str)
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
	free(*res);
	free(*p);
	free(*str);
	*p = NULL;
	*str = NULL;
	*res = NULL;
	return (1);
}
