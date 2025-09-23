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

	bitset = ft_bs_new_from_mem("01bin", 5);
	if (!bitset || ft_bs_get_raw(bitset, 0) != '0'
		|| ft_bs_get_raw(bitset, 1) != '1' || ft_bs_get_raw(bitset, 2) != 'b'
		|| ft_bs_get_raw(bitset, 3) != 'i' || ft_bs_get_raw(bitset, 4) != 'n')
		return (1);
	ft_bs_free(&bitset);
	bitset = ft_bs_new_from_mem("11111111", 4);
	if (!bitset || bitset->_capacity != 4)
		return (ft_bs_free(&bitset), 2);
	ft_bs_free(&bitset);
	bitset = ft_bs_new_from_mem("1010", 8);
	if (!bitset || bitset->_capacity != 8
		|| ft_bs_get_raw(bitset, 0) != '1' || ft_bs_get_raw(bitset, 1) != '0'
		|| ft_bs_get_raw(bitset, 2) != '1' || ft_bs_get_raw(bitset, 3) != '0'
		|| ft_bs_get_raw(bitset, 4) != 0 || ft_bs_get_raw(bitset, 5) != 0
		|| ft_bs_get_raw(bitset, 6) != 0 || ft_bs_get_raw(bitset, 7) != 0)
		return (ft_bs_free(&bitset), 3);
	ft_bs_free(&bitset);
	if (ft_bs_new_from_mem(NULL, 8) != NULL)
		return (4);
	if (ft_bs_new_from_mem("10101010", 0) != NULL)
		return (5);
	return (EXIT_SUCCESS);
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
