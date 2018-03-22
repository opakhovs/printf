/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/19 17:59:29 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/20 11:49:30 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		flags1(const char *fo, int *i, t_flags *flags)
{
	if (fo[*i] == '+')
	{
		(flags)->plus = 1;
		return (1);
	}
	if (fo[*i] == '-')
	{
		(flags)->minus = 1;
		return (1);
	}
	if (fo[*i] == '#')
	{
		(flags)->hash = 1;
		return (1);
	}
	if (fo[*i] == '0')
	{
		(flags)->zero = 1;
		return (1);
	}
	return (0);
}

int		flags2(const char *fo, int *i, t_flags *flags, va_list *valist)
{
	if (fo[*i] == '*')
	{
		(flags)->bp = va_arg(*valist, int);
		if ((flags)->bp < 0)
			(flags)->bp = 0;
		return (1);
	}
	if ((fo[*i] >= '1' && fo[*i] <= '9'))
	{
		(flags)->bp = ft_atoii(fo, i);
		return (1);
	}
	if (fo[*i] == '.' && (fo[(*i + 1)] >= '0' && fo[*i + 1] <= '9') && (*i)++)
	{
		(flags)->p = 1;
		(flags)->ap = ft_atoii(fo, i);
		return (1);
	}
	return (0);
}

int		flags3(const char *fo, int *i, t_flags *flags, va_list *valist)
{
	if (fo[*i] == '.')
	{
		if (fo[(*i + 1)] == '*' && (*i)++)
			(flags)->ap = va_arg(*valist, int);
		if ((flags)->ap < 0 || fo[(*i)] != '*')
			(flags)->ap = 0;
		(flags)->p = 1;
		return (1);
	}
	if (fo[*i] == 'h' && fo[*i + 1] == 'h' && (*i)++)
	{
		(flags)->hh = 1;
		return (1);
	}
	if (fo[*i] == 'h')
	{
		(flags)->h = 1;
		return (1);
	}
	return (0);
}

int		flags4(const char *fo, int *i, t_flags *flags)
{
	if (fo[*i] == 'l' && fo[*i + 1] == 'l' && (*i)++)
	{
		(flags)->ll = 1;
		return (1);
	}
	if (fo[*i] == 'l')
	{
		(flags)->l = 1;
		return (1);
	}
	if (fo[*i] == 'z')
	{
		(flags)->z = 1;
		return (1);
	}
	if (fo[*i] == 'j')
	{
		(flags)->j = 1;
		return (1);
	}
	if (fo[*i] == ' ' && ((flags)->space += 1))
		return (1);
	return (0);
}
