/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_toggle.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

int	tb_toggle(void)
{
	t_bitset	*bitset;
	int			i;
	int			j;

	// Test 1: Create bitset and test toggling bits from false to true
	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	// Toggle bits from false to true
	if (!ft_bs_toggle(bitset, 0) || !ft_bs_toggle(bitset, 7)
		|| !ft_bs_toggle(bitset, 8) || !ft_bs_toggle(bitset, 15))
		return (ft_bs_free(&bitset), 2);

	// Test 2: Toggle bits from true to false
	if (!ft_bs_toggle(bitset, 0) || !ft_bs_toggle(bitset, 7))
		return (ft_bs_free(&bitset), 3);
	// Verify bits are still true
	if (!ft_bs_get(bitset, 8) || !ft_bs_get(bitset, 15))
		return (ft_bs_free(&bitset), 4);

	// Test 3: Toggle back to true
	if ((!ft_bs_toggle(bitset, 0) || !ft_bs_toggle(bitset, 7))
		|| (!ft_bs_get(bitset, 0) || !ft_bs_get(bitset, 7)))
		return (ft_bs_free(&bitset), 5);

	// Test 4: Test out-of-bounds access (should return false)
	if (ft_bs_toggle(bitset, 16) || ft_bs_toggle(bitset, 100))
		return (ft_bs_free(&bitset), 6);

	// Test 5: Test with NULL bitset (should return false)
	if (ft_bs_toggle(NULL, 0) != false)
		return (ft_bs_free(&bitset), 7);

	// Test 6: Test toggling all bits multiple times
	i = 0;
	while (i < 8)
	{
		j = 0;
		while (j++ < 8)
			if (!ft_bs_toggle(bitset, i))
				return (ft_bs_free(&bitset), 8);
		i++;
	}
	ft_bs_free_inner(bitset);
	if (ft_bs_toggle(bitset, 12) != false)
		return (ft_bs_free(&bitset), 9);

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
