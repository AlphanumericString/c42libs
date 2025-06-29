/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_toggle_raw.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

int	tb_toggle_raw(void)
{
	t_bitset	*bitset;
	bool		result;

	// Test 1: Create bitset and test toggling raw values from 0
	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);

	// Toggle first byte from 0 to 255 (all bits)
	if (!ft_bs_toggle_raw(bitset, 0))
		return (ft_bs_free(&bitset), 2);

	// Test 2: Toggle first byte back to 0
	if (!ft_bs_toggle_raw(bitset, 0))
		return (ft_bs_free(&bitset), 3);

	// Test 3: Set specific pattern and toggle
	ft_bs_set_raw(bitset, 0, 0xAA); // 0b10101010 (170)

	// Toggle to 0b01010101 (85)
	if (!ft_bs_toggle_raw(bitset, 0))
		return (ft_bs_free(&bitset), 4);

	// Test 4: Toggle second byte
	if (!ft_bs_toggle_raw(bitset, 1))
		return (ft_bs_free(&bitset), 5);

	// Test 5: Test out-of-bounds access (should return false)
	result = ft_bs_toggle_raw(bitset, 2);
	if (result != false)
		return (ft_bs_free(&bitset), 6);

	result = ft_bs_toggle_raw(bitset, 100);
	if (result != false)
		return (ft_bs_free(&bitset), 7);

	// Test 6: Test with NULL bitset (should return false)
	result = ft_bs_toggle_raw(NULL, 0);
	if (result != false)
		return (ft_bs_free(&bitset), 8);

	// Test 7: Test multiple toggles
	// Set to 0xAA, toggle to 0x55, toggle back to 0xAA
	ft_bs_set_raw(bitset, 0, 0xAA);
	if (!ft_bs_toggle_raw(bitset, 0))
		return (ft_bs_free(&bitset), 9);
	if (!ft_bs_toggle_raw(bitset, 0))
		return (ft_bs_free(&bitset), 10);

	ft_bs_free_inner(bitset);
	if (ft_bs_toggle_raw(bitset, 0) != false)
		return (ft_bs_free(&bitset), 11);

	return (ft_bs_free(&bitset), 0);
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
