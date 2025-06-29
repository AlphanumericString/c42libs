/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_new_from_mem.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

int	tb_new_from_mem(void)
{
	t_bitset	*bitset;

	// Test 1: Create bitset from simple string
	bitset = ft_bs_new_from_mem("10101010", 8);
	if (!bitset)
		return (1);
	ft_bs_free(&bitset);

	// Test 2: Create bitset from all ones
	bitset = ft_bs_new_from_mem("11111111", 8);
	if (!bitset)
		return (2);
	ft_bs_free(&bitset);

	// Test 3: Create bitset from all zeros
	bitset = ft_bs_new_from_mem("00000000", 8);
	if (!bitset)
		return (3);
	ft_bs_free(&bitset);

	// Test 4: Create bitset from mixed pattern
	bitset = ft_bs_new_from_mem("11001100", 8);
	if (!bitset)
		return (4);
	ft_bs_free(&bitset);

	// Test 5: Create bitset with size less than string length
	bitset = ft_bs_new_from_mem("11111111", 4);
	if (!bitset)
		return (5);
	ft_bs_free(&bitset);

	// Test 6: Create bitset with size greater than string length
	bitset = ft_bs_new_from_mem("1010", 8);
	if (!bitset)
		return (6);
	ft_bs_free(&bitset);

	// Test 7: Test with NULL string (should return NULL)
	bitset = ft_bs_new_from_mem(NULL, 8);
	if (bitset != NULL)
		return (7);

	// Test 8: Test with size 0 (should return NULL)
	bitset = ft_bs_new_from_mem("1010", 0);
	if (bitset != NULL)
		return (8);

	// Test 9: Test with single bit
	bitset = ft_bs_new_from_mem("1", 1);
	if (!bitset)
		return (9);
	ft_bs_free(&bitset);

	// Test 10: Test with larger bitset
	bitset = ft_bs_new_from_mem("1010101010101010", 16);
	if (!bitset)
		return (10);
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
