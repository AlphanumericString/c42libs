/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_remove_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "internal/debug_defs.h"
#include "tests/bitset_tests.h"

int	tb_remove_front(void)
{
	t_bitset	*bitset;

	// Test 1: Create bitset and remove one byte from front
	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	ft_bs_set_raw(bitset, 0, 0b11110000);
	ft_bs_set_raw(bitset, 1, 0b01010101);
	ft_bs_remove_front(bitset, 1);
	if (ft_bs_get_raw(bitset, 0) != 0b01010101)
		return (2);
	ft_bs_free(&bitset);
	// Test 2: Remove all bytes from the front
	bitset = ft_bs_new(8);
	if (!bitset)
		return (3);
	ft_bs_remove_front(bitset, 1);
	if (bitset->bits != NULL || bitset->_capacity != 0)
		return (4);
	ft_bs_free(&bitset);
	// Test 3: Remove more bits than available
	bitset = ft_bs_new(4);
	if (!bitset)
		return (5);
	ft_bs_remove_front(bitset, 10);
	if (bitset->bits != NULL || bitset->_capacity != 0)
		return (6);
	ft_bs_free(&bitset);
	// Test 4: Remove 0 bits (should do nothing)
	bitset = ft_bs_new(8);
	if (!bitset)
		return (7);
	ft_bs_remove_front(bitset, 0);
	if (bitset->_capacity == 0 || bitset->bits == NULL)
		return (8);
	ft_bs_free(&bitset);
	// Test 5: Test with NULL bitset (should not crash)
	ft_bs_remove_front(NULL, 4);
	return (0);
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
