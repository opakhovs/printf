/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putnbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 16:56:26 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 16:56:29 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*putnbr(long long int num)
{
	char			*str;
	int				dec;
	long long int	temp;
	int				sign;

	dec = 1;
	if (num == (-9223372036854775807 - 1))
		return (ft_min());
	sign = (num < 0) ? 1 : 0;
	temp = (num < 0) ? -num : num;
	while (temp > 9 && dec++)
		temp /= 10;
	dec = (sign == 1) ? dec + 1 : dec;
	str = ft_strnew(dec);
	str[dec] = '\0';
	temp = (num < 0) ? -num : num;
	while (temp > 9)
	{
		str[--dec] = (temp % 10) + 48;
		temp /= 10;
	}
	str[--dec] = temp + 48;
	if (sign == 1)
		str[0] = '-';
	return (str);
}

char	*u_putnbr(uintmax_t num)
{
	char		*str;
	int			dec;
	uintmax_t	temp;

	dec = 1;
	temp = num;
	while (temp > 9 && dec++)
		temp /= 10;
	str = ft_strnew(dec);
	str[dec] = '\0';
	temp = num;
	while (temp > 9)
	{
		str[--dec] = (temp % 10) + 48;
		temp /= 10;
	}
	str[--dec] = temp + 48;
	return (str);
}

char	*o_putnbr(uintmax_t num)
{
	char		*str;
	int			dec;
	uintmax_t	temp;

	dec = 1;
	temp = num;
	while (temp > 7 && dec++)
		temp /= 8;
	str = ft_strnew(dec + 1);
	str[dec] = '\0';
	temp = num;
	while (temp > 7)
	{
		str[--dec] = (temp % 8) + 48;
		temp /= 8;
	}
	str[--dec] = temp + 48;
	return (str);
}

char	*x_putnbr(uintmax_t num)
{
	char		*str;
	int			dec;
	uintmax_t	temp;

	dec = 1;
	temp = num;
	while (temp > 15 && dec++)
		temp /= 16;
	str = ft_strnew(dec + 1);
	str[dec] = '\0';
	temp = num;
	while (temp > 15)
	{
		if (temp % 16 > 9)
			str[--dec] = (temp % 16) + 87;
		else
			str[--dec] = (temp % 16) + 48;
		temp /= 16;
	}
	if (temp > 9)
		str[--dec] = (temp % 16) + 87;
	else
		str[--dec] = (temp % 16) + 48;
	return (str);
}

char	*xx_putnbr(uintmax_t num)
{
	char		*str;
	int			dec;
	uintmax_t	temp;

	dec = 1;
	temp = num;
	while (temp > 15 && dec++)
		temp /= 16;
	str = ft_strnew(dec + 1);
	str[dec] = '\0';
	temp = num;
	while (temp > 15)
	{
		if (temp % 16 > 9)
			str[--dec] = (temp % 16) + 55;
		else
			str[--dec] = (temp % 16) + 48;
		temp /= 16;
	}
	if (temp > 9)
		str[--dec] = (temp % 16) + 55;
	else
		str[--dec] = (temp % 16) + 48;
	return (str);
}
