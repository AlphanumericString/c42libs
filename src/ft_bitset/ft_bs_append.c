/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_append.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 16:20:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 17:48:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_bitset_types.h"
#include "ft_bitset.h"
#include "ft_string.h"
#include <stddef.h>

bool	ft_bs_append(t_bitset *bitset, t_bitset *to_append)
{
	t_bitset8	*bs8;

	if (!bitset || !to_append)
		return (false);
	bs8 = ft_calloc(sizeof(t_bitset8),
			bitset->_capacity + to_append->_capacity);
	if (!bs8)
		return (false);
	ft_memcpy(bs8, bitset->bits, bitset->_capacity);
	ft_memcpy(bs8 + bitset->_capacity, to_append->bits, to_append->_capacity);
	bitset->_capacity += to_append->_capacity;
	ft_free(bitset->bits);
	bitset->bits = bs8;
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
