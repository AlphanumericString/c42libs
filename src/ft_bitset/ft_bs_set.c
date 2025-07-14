/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bs_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:59:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:21:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "types/ft_bitset_types.h"

bool	ft_bs_set_raw(t_bitset *bitset, size_t index, uint8_t value)
{
	if (!bitset || !bitset->bits)
		return (false);
	if (index >= bitset->_capacity)
		return (false);
	bitset->bits[index].raw = value;
	return (true);
}

	// mask = 0xFF & ~(1 << (index % 8));
	// if (value)
	// 	mask = 0x00 | (1 << (index % 8));
	// bitset->bits[index / 8].raw &= mask;
bool	ft_bs_set(t_bitset *bitset, size_t index, bool value)
{
	uint8_t		mask;

	(void) mask;
	if (!bitset || !bitset->bits)
		return (false);
	if (index >= bitset->_capacity * 8)
		return (false);
	if (index % 8 == 0)
		bitset->bits[index / 8].b0 = value;
	if (index % 8 == 1)
		bitset->bits[index / 8].b1 = value;
	if (index % 8 == 2)
		bitset->bits[index / 8].b2 = value;
	if (index % 8 == 3)
		bitset->bits[index / 8].b3 = value;
	if (index % 8 == 4)
		bitset->bits[index / 8].b4 = value;
	if (index % 8 == 5)
		bitset->bits[index / 8].b5 = value;
	if (index % 8 == 6)
		bitset->bits[index / 8].b6 = value;
	if (index % 8 == 7)
		bitset->bits[index / 8].b7 = value;
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
