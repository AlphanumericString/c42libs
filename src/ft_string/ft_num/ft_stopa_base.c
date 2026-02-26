/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stopa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/25 22:39:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 00:27:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_string.h"
#include "sys/types.h"

#include <unistd.h>
#include <stddef.h>

// Size_t
// To
// Pointed Array
bool	ft_stopa_base(size_t nbr, const char *base, char *ptr, size_t max)
{
	t_uint	blen;
	t_uint	nblen;

	if (!base | !ptr | max <= 1 || ft_base_valid(base) == false)
		return (false);
	blen = ft_strlen(base);
	nblen = ft_unbrlen_base(nbr, blen);
	if (nblen + 1 > max)
		return (false);
	if (!nbr)
		return (ft_strlcpy(ptr, base, 2), true);
	ptr[nblen] = '\0';
	while (nbr)
	{
		ptr[--nblen] = base[nbr % blen];
		nbr /= blen;
	}
	return (true);
}

bool	ft_sstopa_base(ssize_t nbr, const char *base, char *ptr, size_t max)
{
	t_uint	blen;
	t_uint	nblen;
	char	hold;

	if (!base | !ptr | max <= 1 || ft_base_valid(base) == false)
		return (false);
	blen = ft_strlen(base);
	nblen = ft_nbrlen_base(nbr, blen);
	if (nblen + 1 > max)
		return (false);
	if (nbr >= 0)
		return (ft_stopa_base((size_t)nbr, base, ptr, max));
	ptr[0] = '-';
	ptr[nblen] = '\0';
	hold = base[ft_mod(nbr, blen)];
	nbr = (nbr / blen) * -1;
	ft_stopa_base(nbr, base, ptr + 1, max - 1);
	ptr[--nblen] = hold;
	return (true);
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
