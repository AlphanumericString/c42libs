/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "internal/debug_defs.h"
#include "tests/bitset_tests.h"

int	tb_set(void)
{
	t_bitset	*bitset;
	bool		result;

	// Test 1: Create bitset and test setting bits to true
	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	// Set various bits to true
	if (!ft_bs_set(bitset, 0, true) || !ft_bs_set(bitset, 7, true)
		|| !ft_bs_set(bitset, 8, true) || !ft_bs_set(bitset, 15, true))
		return (ft_bs_free(&bitset), 2);
	// Test 2: Set bits to false
	if (!ft_bs_set(bitset, 0, false) || !ft_bs_set(bitset, 7, false))
		return (ft_bs_free(&bitset), 3);
	// Test 3: Test out-of-bounds access (should return false)
	result = ft_bs_set(bitset, 16, true);
	if (result != false)
		return (ft_bs_free(&bitset), 4);
	result = ft_bs_set(bitset, 100, false);
	if (result != false)
		return (ft_bs_free(&bitset), 5);
	// Test 4: Test with NULL bitset (should return false)
	result = ft_bs_set(NULL, 0, true);
	if (result != false)
		return (ft_bs_free(&bitset), 6);
	// Test 5: Test setting all bits in a byte
	for (size_t i = 0; i < 8; i++)
		if (!ft_bs_set(bitset, i, true))
			return (ft_bs_free(&bitset), 7);
	ft_bs_free_inner(bitset);
	result = ft_bs_set(bitset, 2, false);
	if (result != false)
		return (ft_bs_free(&bitset), 8);
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
