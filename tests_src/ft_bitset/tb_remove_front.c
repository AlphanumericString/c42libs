/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_remove_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

int	tb_remove_front(void)
{
	t_bitset	*bitset;

	bitset = ft_bs_new(16);
	ft_bs_set_raw(bitset, 0, 0b11110000);
	ft_bs_set_raw(bitset, 1, 0b01010101);
	ft_bs_remove_front(bitset, 1);
	if (!bitset || ft_bs_get_raw(bitset, 0) != 0b01010101)
		return (ft_bs_free(&bitset), 2);
	ft_bs_free(&bitset);
	bitset = ft_bs_new(8);
	ft_bs_remove_front(bitset, 1);
	if (!bitset || bitset->bits != NULL || bitset->_capacity != 0)
		return (ft_bs_free(&bitset), 4);
	ft_bs_free(&bitset);
	bitset = ft_bs_new(4);
	ft_bs_remove_front(bitset, 10);
	if (!bitset || bitset->bits != NULL || bitset->_capacity != 0)
		return (ft_bs_free(&bitset), 6);
	ft_bs_free(&bitset);
	bitset = ft_bs_new(8);
	ft_bs_remove_front(bitset, 0);
	if (!bitset || bitset->_capacity == 0 || bitset->bits == NULL)
		return (ft_bs_free(&bitset), 8);
	return (ft_bs_remove_front(NULL, 4), ft_bs_free(&bitset), 0);
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
