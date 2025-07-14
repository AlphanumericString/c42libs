/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 16:24:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 16:24:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

// we set bit 0-7 to true one by one
// nb increases by one one shift and pipes 1 on the lsb so
// nb should be == whatever bitset is at
static int	incremental_position_check(void)
{
	t_bitset		*bitset;
	unsigned char	nb;
	size_t			i;

	bitset = ft_bs_new(8);
	if (!bitset)
		return (10);
	i = 0;
	nb = 0b00000000;
	while (i < 8)
	{
		ft_bs_set(bitset, i, true);
		nb = nb << 1 | 0b00000001;
		if (ft_bs_get_raw(bitset, 0) != nb)
			return (ft_bs_free(&bitset), 11);
		i++;
	}
	return (ft_bs_free(&bitset), 0);
}

int	tb_set(void)
{
	t_bitset	*bitset;

	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	if (!ft_bs_set(bitset, 0, true) || !ft_bs_set(bitset, 7, true)
		|| !ft_bs_set(bitset, 8, true) || !ft_bs_set(bitset, 15, true))
		return (ft_bs_free(&bitset), 2);
	if (ft_bs_get_raw(bitset, 0) != 0b10000001
		|| ft_bs_get_raw(bitset, 1) != 0b10000001)
		return (ft_bs_free(&bitset), 3);
	if (!ft_bs_set(bitset, 0, false) || !ft_bs_set(bitset, 7, false))
		return (ft_bs_free(&bitset), 4);
	if (ft_bs_get_raw(bitset, 0) != 0
		|| ft_bs_get_raw(bitset, 1) != 0b10000001)
		return (ft_bs_free(&bitset), 5);
	if (ft_bs_set(bitset, 16, true) != false
		|| ft_bs_set(bitset, 100, true) != false
		|| ft_bs_set(NULL, 0, true) != false)
		return (ft_bs_free(&bitset), 6);
	ft_bs_free_inner(bitset);
	if (ft_bs_set(bitset, 2, false) != false)
		return (ft_bs_free(&bitset), 7);
	return (ft_bs_free(&bitset), incremental_position_check());
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
