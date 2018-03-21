/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workls_other.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:40:53 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:40:55 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (MB_CUR_MAX == 1 && (*str > 0x7F || *str < -128))
			return (-1);
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

wchar_t	*ft_wstrnew(size_t size)
{
	wchar_t	*str;

	str = ft_memalloc(size + 1);
	if (str == NULL)
		return (NULL);
	return (str);
}

void	ft_putwchar_in_char(wchar_t ch, char **str, int i)
{
	unsigned int	v;

	v = ch;
	if (ch <= 0x7F)
		*((*str) + 0 + i) = (char)ch;
	else if (ch <= 0xFFFF)
	{
		*((*str) + 0 + i) = 0xE0 | ((ch >> 12) & 0x3F);
		*((*str) + 1 + i) = 0x80 | ((ch >> 6) & 0x3F);
		*((*str) + 2 + i) = 0x80 | (ch & 0x3F);
	}
	else if (ch <= 0x10FFFF)
	{
		*((*str) + 0 + i) = 0xF0 | ((ch >> 18) & 0x3F);
		*((*str) + 1 + i) = 0x80 | ((ch >> 12) & 0x3F);
		*((*str) + 2 + i) = 0x80 | ((ch >> 6) & 0x3F);
		*((*str) + 3 + i) = 0x80 | (ch & 0x3F);
	}
}
