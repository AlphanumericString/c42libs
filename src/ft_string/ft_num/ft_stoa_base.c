/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:51:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>

#include "ft_string.h"
#include "ft_math.h"

char	*ft_stoa_base(size_t nbr, const char *base)
{
	t_uint	blen;
	t_uint	nblen;
	char	*res;

	if (!base || ft_base_valid(base) != true)
		return (NULL);
	blen = ft_strlen(base);
	nblen = ft_unbrlen_base(nbr, blen);
	res = ft_calloc((nblen + 1), sizeof(char));
	if (!res)
		return (res);
	if (!nbr)
		return (res[0] = base[0], res);
	res[--nblen] = base[nbr % blen];
	nbr /= blen;
	while (nbr)
	{
		res[--nblen] = base[nbr % blen];
		nbr /= blen;
	}
	return (res);
}

static void	loop(ssize_t nbr, const char *base, t_uint pass[2], char *res)
{
	while (nbr)
	{
		res[--pass[1]] = base[ft_mod(nbr, pass[0])];
		nbr /= pass[0];
	}
}

char	*ft_sstoa_base(ssize_t nbr, const char *base)
{
	t_uint	blen;
	t_uint	nblen;
	char	*res;

	if (!base || ft_base_valid(base) != true)
		return (NULL);
	blen = ft_strlen(base);
	nblen = ft_nbrlen_base(nbr, blen);
	res = ft_calloc((nblen + 1), sizeof(char));
	if (!res)
		return (res);
	if (!nbr)
		return (res[0] = base[0], res);
	res[--nblen] = base[ft_mod(nbr, blen)];
	nbr /= blen;
	if (nbr < 0)
	{
		nbr = -nbr;
		res[0] = '-';
	}
	loop(nbr, base, (t_uint [2]){blen, nblen}, res);
	return (res);
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
