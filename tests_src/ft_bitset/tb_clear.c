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
#include "tests/bitset_tests.h"

#include <stdlib.h>

int	tb_clear(void)
{
	t_bitset	*bitset;
	size_t		i;

	bitset = ft_bs_new(16);
	if (!bitset)
		return (1);
	ft_bs_set_raw(bitset, 0, rand() % 256);
	ft_bs_set_raw(bitset, 1, rand() % 256);
	ft_bs_clear(bitset);
	if (ft_bs_get_raw(bitset, 0) != 0 || ft_bs_get_raw(bitset, 1) != 0)
		return (ft_bs_free(&bitset), 2);
	ft_bs_free(&bitset);
	ft_bs_clear(NULL);
	bitset = ft_bs_new(64);
	i = 0;
	while (i < 8)
		ft_bs_set_raw(bitset, i++, rand() % 256);
	ft_bs_clear(bitset);
	i = 0;
	while (i < 8)
		if (ft_bs_get_raw(bitset, i++) != 0)
			return (ft_bs_free(&bitset), 11);
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
