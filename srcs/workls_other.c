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
		if (*str < (1 << 7))
			i++;
		else if (*str < (1 << 11))
			i += 2;
		else if (*str < (1 << 16))
			i += 3;
		else if (*str < (1 << 21))
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

void	ft_putwchar_in_char(wchar_t chr, char **str, int i)
{
	if (chr < (MB_CUR_MAX == 1 ? 0xFF : 0x7F))
		*((*str) + 0 + i) = chr;
	else if (chr < (1 << 11))
	{
		*((*str) + 0 + i) = ((chr >> 6) | 0xC0);
		*((*str) + 1 + i) = ((chr & 0x3F) | 0x80);
	}
	else if (chr < (1 << 16))
	{
		*((*str) + 0 + i) = (((chr >> 12)) | 0xE0);
		*((*str) + 1 + i) = (((chr >> 6) & 0x3F) | 0x80);
		*((*str) + 2 + i) = ((chr & 0x3F) | 0x80);
	}
	else if (chr < (1 << 21))
	{
		*((*str) + 0 + i) = (((chr >> 18)) | 0xF0);
		*((*str) + 1 + i) = (((chr >> 12) & 0x3F) | 0x80);
		*((*str) + 2 + i) = (((chr >> 6) & 0x3F) | 0x80);
		*((*str) + 3 + i) = ((chr & 0x3F) | 0x80);
	}
}
