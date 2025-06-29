/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:59:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"
#include "types/ft_bitset_types.h"

int	tb_get(void)
{
	t_bitset	*bs;

	bs = ft_bs_new(8);
	if (!bs)
		return (1);
	if (ft_bs_get(bs, 0) || ft_bs_get(bs, 1) || ft_bs_get(bs, 7))
		return (ft_bs_free(&bs), 2);
	ft_bs_set_raw(bs, 0, 0b11110110);
	if (ft_bs_get(bs, 0) != false && ft_bs_get(bs, 1) != true)
		return (ft_bs_free(&bs), 3);
	if (ft_bs_get(bs, 16) != false || ft_bs_get(bs, 100) != false)
		return (ft_bs_free(&bs), 4);
	ft_bs_free_inner(bs);
	if (ft_bs_get(NULL, 0) != 0 || ft_bs_get(bs, 0) != 0)
		return (ft_bs_free(&bs), 6);
	return (ft_bs_free(&bs), 0);
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
