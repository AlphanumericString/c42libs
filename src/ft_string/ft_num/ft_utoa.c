/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 14:54:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:36:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	loc_getlen(unsigned long long nbr)
{
	size_t	nbr_len;

	nbr_len = 0;
	if (nbr == 0)
		return (1);
	while (nbr)
	{
		nbr_len++;
		nbr /= 10;
	}
	return (nbr_len);
}

char	*ft_utoa(unsigned int nbr)
{
	char				*ret;
	size_t				off;
	unsigned long long	srcnbr;
	const int			nbrlen = loc_getlen((unsigned long long)nbr);

	srcnbr = (unsigned long long)nbr;
	ret = ft_calloc(sizeof(char), (nbrlen + 1));
	if (!ret)
		return (NULL);
	if (srcnbr == 0)
		ret[0] = '0';
	off = 0;
	while (srcnbr)
	{
		ret[nbrlen - ++off] = "0123456789"[srcnbr % 10];
		srcnbr /= 10;
	}
	return (ret);
}
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
