/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_append.c                                        :+:      :+:    :+:   */
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
#include "tests/tests.h"
#include "types/ft_bitset_types.h"
#include <stddef.h>

static int	mt_bsappend(void)
{
	t_bitset	*b1;
	t_bitset	*b2;
	const int	fp = *talloc_get_failpoint();

	b1 = ft_bs_new(8);
	ft_bs_set_raw(b1, 0, 0xDE);
	b2 = ft_bs_new(8);
	ft_bs_set_raw(b2, 0, 0xAD);
	talloc_set_failpoint(0);
	if (ft_bs_append(b1, b2) != false)
		return (1);
	talloc_set_failpoint(fp);
	ft_bs_free(&b1);
	ft_bs_free(&b2);
	return (0);
}

int	tb_append(void)
{
	t_bitset	*bitset1;
	t_bitset	*bitset2;
	size_t		i;

	// Test 1: Create two bitsets and append
	bitset1 = ft_bs_new(8);
	bitset2 = ft_bs_new(8);
	if (!bitset1 || !bitset2)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 1);

	// Set some bits in first bitset
	// Set some bits in second bitset
	ft_bs_set_raw(bitset1, 0, 0b10000001);
	ft_bs_set_raw(bitset2, 0, 0b10001001);
	// Append bitset2 to bitset1
	ft_bs_append(bitset1, bitset2);

	// Verify the result: bitset1 should now have 16 bits
	// First 8 bits should be from original bitset1
	if (ft_bs_get(bitset1, 0) != true || ft_bs_get(bitset1, 7) != true)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 2);

	// Bits 1-6 should be false
	i = 0;
	while (i < 16)
	{
		if ((i && i < 7) || (i > 8 && i < 11) || (i > 11 && i != 15))
		{
			if (ft_bs_get(bitset1, i) != false)
				return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 3);
		}
		else if (ft_bs_get(bitset1, i) != true)
			return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 3);
		i++;
	}
	(ft_bs_free(&bitset1), ft_bs_free(&bitset2));

	// Test 2: Append empty bitset
	bitset1 = ft_bs_new(4);
	bitset2 = ft_bs_new(1);
	if (!bitset1 || !bitset2)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 6);

	ft_bs_set(bitset1, 0, true);
	ft_bs_set(bitset1, 3, true);

	ft_bs_append(bitset1, bitset2);

	// bitset1 should remain unchanged
	if (ft_bs_get(bitset1, 0) != true || ft_bs_get(bitset1, 3) != true)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 7);

	(ft_bs_free(&bitset1), ft_bs_free(&bitset2));

	// Test 3: Append to empty bitset
	bitset1 = ft_bs_new(1);
	bitset2 = ft_bs_new(4);
	if (!bitset1 || !bitset2)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 8);
	ft_bs_set(bitset2, 1, true);
	ft_bs_set(bitset2, 2, true);
	ft_bs_append(bitset1, bitset2);
	// bitset1 should now contain bitset2's content
	if (ft_bs_get(bitset1, 1 + 8) != true || ft_bs_get(bitset1, 2 + 8) != true)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 9);

	// Other bits should be false
	if (ft_bs_get(bitset1, 1) != false || ft_bs_get(bitset1, 3) != false)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 10);

	(ft_bs_free(&bitset1), ft_bs_free(&bitset2));

	// Test 4: Test with NULL parameters (should not crash)
	bitset1 = ft_bs_new(4);
	if (!bitset1)
		return (11);

	ft_bs_append(bitset1, NULL);
	ft_bs_append(NULL, bitset1);
	ft_bs_append(NULL, NULL);

	ft_bs_free(&bitset1);

	// Test 5: Test multiple appends
	bitset1 = ft_bs_new(2);
	bitset2 = ft_bs_new(2);
	if (!bitset1 || !bitset2)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 12);

	ft_bs_set(bitset1, 0, true);
	ft_bs_set(bitset2, 1, true);

	ft_bs_append(bitset1, bitset2);

	// bitset1 should now have 4 bits: 0000 0010, 0000 0001
	// eg bit 0 true - bit 9 true
	if (ft_bs_get(bitset1, 0) != true || ft_bs_get(bitset1, 9) != true)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 13);
	return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), mt_bsappend());
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
