/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_set_raw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

int	tb_set_raw(void)
{
	t_bitset	*bitset;

	bitset = ft_bs_new(4 * 8);
	if (!bitset)
		return (1);
	if (!ft_bs_set_raw(bitset, 0, 170) || !ft_bs_set_raw(bitset, 1, 240)
		|| !ft_bs_set_raw(bitset, 2, 255) || !ft_bs_set_raw(bitset, 3, 0))
		return (ft_bs_free(&bitset), 2);
	if (ft_bs_get_raw(bitset, 0) != 170 || ft_bs_get_raw(bitset, 1) != 240
		|| ft_bs_get_raw(bitset, 2) != 255 || ft_bs_get_raw(bitset, 3) != 0)
		return (ft_bs_free(&bitset), 3);
	if ((!ft_bs_set_raw(bitset, 0, 0b10100000) || ft_bs_set(bitset, 7, true))
		&& ft_bs_get_raw(bitset, 0) != 160)
		return (3);
	if (ft_bs_set_raw(bitset, 99, 42) || ft_bs_set_raw(bitset, 100, 42))
		return (ft_bs_free(&bitset), 4);
	ft_bs_free_inner(bitset);
	if (ft_bs_set_raw(NULL, 0, 42) || ft_bs_set_raw(bitset, 0, 42))
		return (ft_bs_free(&bitset), 5);
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
