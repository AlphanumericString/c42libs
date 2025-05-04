/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:03:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/24 13:56:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_math.h"
#include <stdlib.h>
#include <sys/types.h>
#include "ft_math.h"

char	*ft_itoa_base(int nbr, const char *base)
{
	return (ft_stoa_base((ssize_t)nbr, base));
}

char	*ft_stoa_base(ssize_t nbr, const char *base)
{
	char		*ret;
	size_t		off;
	long long	srcnbr;
	size_t		blen;
	int			nbrlen;

	srcnbr = (long long)nbr;
	if (!ft_base_valid(base))
		return (NULL);
	blen = ft_strlen(base);
	nbrlen = ft_nbrlen_base(nbr, blen);
	ret = ft_calloc(sizeof(char), (nbrlen + 1));
	if (!ret)
		return (NULL);
	if (srcnbr <= 0)
	{
		ret[0] = (srcnbr == 0) * '0' + (srcnbr < 0) * '-';
		srcnbr *= -1;
	}
	off = 0;
	while (srcnbr)
	{
		ret[nbrlen - ++off] = base[srcnbr % blen];
		srcnbr /= blen;
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
