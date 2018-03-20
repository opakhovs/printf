/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   workx_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/18 18:28:40 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/18 18:28:43 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	x_line_hash(char **str)
{
	char	*nstr;
	int		size;
	int		i;

	if (ft_strcmp(*str, "0") != 0)
	{
		size = ft_strlen(*str);
		nstr = ft_strnew(size + 2);
		i = -1;
		nstr[0] = '0';
		nstr[1] = 'x';
		while (++i < size)
			nstr[i + 2] = *((*str) + i);
		nstr[size + 2] = '\0';
		free_locate(str);
		*str = ft_strnew(ft_strlen(nstr));
		ft_strncpy(*str, nstr, (size + 2));
		free_locate(&nstr);
	}
}

void	xx_line_hash(char **str)
{
	char	*nstr;
	int		size;
	int		i;

	if (ft_strcmp(*str, "0") != 0)
	{
		size = ft_strlen(*str);
		nstr = ft_strnew(ft_strlen(*str) + 2);
		i = -1;
		nstr[0] = '0';
		nstr[1] = 'X';
		while (++i < size)
			nstr[i + 2] = *((*str) + i);
		nstr[size + 2] = '\0';
		free_locate(str);
		*str = ft_strnew(ft_strlen(nstr));
		ft_strncpy(*str, nstr, (size + 2));
		free_locate(&nstr);
	}
}
