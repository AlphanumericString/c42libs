/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_clear.c                                         :+:      :+:    :+:   */
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
#include "unistd.h"

#include <stdio.h>
#include <stdlib.h>

int	tb_clear(void)
{
	t_bitset	*bitset;
	size_t		i;
	int			rand_val;

	// Test 1: Create bitset and test initial state
	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	//// no need to test : we are not testing ft_bs_new ! gosh !
	// i = 0;
	// while(i < 16)
	// {
	// 	if (ft_bs_get(bitset, i++) != false)
	// 		return (ft_bs_free(&bitset), 2);
	// }

	// Test 2: Set some bits and then clear
	i = 0;
	while (i < 4)
	{
		rand_val = rand() % 16; // Random index between 0 and 15
		if (ft_bs_set(bitset, rand_val, true) != true)
			return (ft_bs_free(&bitset), 3);
		// what is the use case of checking this? we are not testing ft_bs_set nor ft_bs_get here!
		// if (ft_bs_get(bitset, rand_val) != true)
		// 	return (ft_bs_free(&bitset), 4);
		i++;
	}
	ft_bs_clear(bitset);
	i = 0;
	while(i < 16)
		if (ft_bs_get(bitset, i++) != false)
			return (ft_bs_free(&bitset), 5);


	// Test 3: Set all bits and clear
	//	wtf? have you looked at the function you are testing?
	//	it doesn't matter if the full bit is set or only a part....
	//	remove useless tests
	//
	// i = 0;
	// while(i < 16)
	// 	ft_bs_set(bitset, i++, true);
	// i = 0;
	// while(i < 16)
	// {
	// 	if (ft_bs_get(bitset, i++) != true)
	// 		return (ft_bs_free(&bitset), 6);
	// }
	// ft_bs_clear(bitset);
	// i = 0;
	// while(i < 16)
	// 	if (ft_bs_get(bitset, i++) != false)
	// 		return (ft_bs_free(&bitset), 7);

	// Test 4: Test with NULL bitset (should not crash)
	ft_bs_clear(NULL);

	// // Test 5: Test with raw values
	//  once again, this is not a test for ft_bs_set_raw nor ft_bs_get_raw...
	//  this is absolutely useless to test this here
	//
	// ft_bs_set_raw(bitset, 0, 0xFF); // Set first byte to all ones
	// ft_bs_set_raw(bitset, 1, 0xAA); // Set second byte to pattern
	// if (ft_bs_get_raw(bitset, 0) != 0xFF || ft_bs_get_raw(bitset, 1) != 0xAA)
	// 	return (ft_bs_free(&bitset), 8);
	// ft_bs_clear(bitset);
	// if (ft_bs_get_raw(bitset, 0) != 0 || ft_bs_get_raw(bitset, 1) != 0)
	// 	return (ft_bs_free(&bitset), 9);

	// Test 6: Test with larger bitset
	//   if the sole purpose of this test is larger bitsets, why not a copy
	//   paste of previously declared test with just a change on size?
	ft_bs_free(&bitset);
	bitset = ft_bs_new(64);
	if (!bitset)
		return (10);
	i = 0;
	while(i < 8)
	{
		ft_bs_set_raw(bitset, i, ((2 ^ 8 - 1) / (i + 1)));
		i++;
	}
	i = 0;
	while(i < 8)
	{
		if (ft_bs_get_raw(bitset, i) != ((2 ^ 8 - 1) / (i + 1)))
			return (ft_bs_free(&bitset), 11);
		i++;
	}
	ft_bs_clear(bitset);
	i = 0;
	while(i < 64)
		if (ft_bs_get(bitset, i++) != false)
			return (ft_bs_free(&bitset), 12);
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
