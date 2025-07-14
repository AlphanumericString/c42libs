/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_get_raw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"

int	tb_get_raw(void)
{
	t_bitset	*bitset;

	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	if (ft_bs_get_raw(bitset, 0) != 0 || ft_bs_get_raw(bitset, 1) != 0)
		return (ft_bs_free(&bitset), 2);
	ft_bs_set_raw(bitset, 0, 0xDE);
	ft_bs_set_raw(bitset, 1, 0xAD);
	if (ft_bs_get_raw(bitset, 0) != 0xDE || ft_bs_get_raw(bitset, 1) != 0xAD)
		return (ft_bs_free(&bitset), 3);
	if (ft_bs_get_raw(bitset, 2) != 0 || ft_bs_get_raw(bitset, 100) != 0)
		return (ft_bs_free(&bitset), 4);
	ft_bs_free_inner(bitset);
	if (ft_bs_get_raw(NULL, 0) != 0 || ft_bs_get_raw(bitset, 0) != 0)
		return (ft_bs_free(&bitset), 6);
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
