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
		else if (MB_CUR_MAX == 1 && *str > 0x7F)
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

void	ft_putwchar_in_char(wchar_t chr, char **str, int i)
{
	unsigned int	v;

	v = chr;
	if (chr <= 0x7F * 2)
		*((*str) + 0 + i) = chr;
	else if (chr <= 0x7FF)
	{
		*((*str) + 0 + i) = (MASK >> 8) | (((v >> 6) << 27) >> 27);
		*((*str) + 1 + i) = ((MASK << 24) >> 24) | ((v << 26) >> 26);
	}
	else if (chr <= 0xFFFF)
	{
		*((*str) + 0 + i) = (MASK2 >> 16) | (((v >> 12) << 28) >> 28);
		*((*str) + 1 + i) = ((MASK2 << 16) >> 24) | ((v >> 6) << 26) >> 26;
		*((*str) + 2 + i) = ((MASK2 << 24) >> 24) | ((v << 26) >> 26);
	}
	else if (chr <= 0x10FFFF )
	{
		*((*str) + 0 + i) = (MASK3 >> 24) | (((v >> 18) << 29) >> 29);
		*((*str) + 1 + i) = ((MASK3 << 8) >> 24) | (((v >> 12) << 26) >> 26);
		*((*str) + 2 + i) = ((MASK3 << 16) >> 24) | (((v >> 6) << 26) >> 26);
		*((*str) + 3 + i) = ((MASK3 << 24) >> 24) | ((v << 26) >> 26);
	}
}
