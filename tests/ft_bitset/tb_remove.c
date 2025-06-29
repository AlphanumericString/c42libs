/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_remove.c                                        :+:      :+:    :+:   */
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

int	tb_remove(void)
{
	t_bitset	*bitset;

	// Test 1: Create bitset and remove some bits
	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	ft_bs_set_raw(bitset, 0, 0b10000001);
	ft_bs_set_raw(bitset, 1, 0b10111101);
	ft_bs_remove(bitset, 1);
	if (ft_bs_get_raw(bitset, 0) != 0b10000001 || ft_bs_get_raw(bitset, 1) != 0)
		return (ft_bs_free(&bitset), 2);
	ft_bs_free(&bitset);

	// Test 2: Remove all bits
	bitset = ft_bs_new(8);
	if (!bitset)
		return (5);
	ft_bs_set_raw(bitset, 0, 0b10000001);
	ft_bs_remove(bitset, 1);

	ft_bs_free(&bitset);

	// Test 3: Remove more bits than available
	bitset = ft_bs_new(4);
	if (!bitset)
		return (6);

	ft_bs_set(bitset, 0, true);
	ft_bs_set(bitset, 3, true);

	ft_bs_remove(bitset, 10);

	// bitset should be empty or have minimal size
	// This might depend on implementation

	ft_bs_free(&bitset);

	// Test 4: Remove 0 bits (should do nothing)
	bitset = ft_bs_new(8);
	if (!bitset)
		return (7);

	ft_bs_set(bitset, 0, true);
	ft_bs_set(bitset, 7, true);

	ft_bs_remove(bitset, 0);

	// bitset should remain unchanged
	if (ft_bs_get(bitset, 0) != true || ft_bs_get(bitset, 7) != true)
	{
		ft_bs_free(&bitset);
		return (8);
	}

	ft_bs_free(&bitset);

	// Test 5: Test with NULL bitset (should not crash)
	ft_bs_remove(NULL, 4);

	// Test 6: Test with larger bitset
	bitset = ft_bs_new(32);
	if (!bitset)
		return (9);

	// Set alternating bits
	for (size_t i = 0; i < 32; i += 2)
	{
		ft_bs_set(bitset, i, true);
	}

	// Remove 16 bits from the end
	ft_bs_remove(bitset, 2);

	// Verify first 16 bits remain (alternating pattern)
	for (size_t i = 0; i < 16; i++)
	{
		bool expected = (i % 2 == 0);
		if (ft_bs_get(bitset, i) != expected)
		{
			ft_bs_free(&bitset);
			return (10);
		}
	}

	ft_bs_free(&bitset);

	// Test 7: Test removing exactly one byte
	bitset = ft_bs_new(16);
	if (!bitset)
		return (11);

	// Set bits in first byte
	for (size_t i = 0; i < 8; i++)
	{
		ft_bs_set(bitset, i, true);
	}

	// Set one bit in second byte
	ft_bs_set(bitset, 8, true);

	// Remove 8 bits (one byte)
	ft_bs_remove(bitset, 1);

	// Verify first 8 bits remain set
	for (size_t i = 0; i < 8; i++)
	{
		if (ft_bs_get(bitset, i) != true)
		{
			ft_bs_free(&bitset);
			return (12);
		}
	}

	ft_bs_free(&bitset);

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
