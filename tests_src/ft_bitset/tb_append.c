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
#include "tests/bitset_tests.h"
#include "tests/fixtures.h"
#include "types/ft_bitset_types.h"
#include <stddef.h>

static int	mt_bsappend(void)
{
	t_bitset	*b1;
	t_bitset	*b2;
	const int	fp = *talloc_get_failpoint();
	int			r;

	b1 = ft_bs_new(8);
	ft_bs_set_raw(b1, 0, 0xDE);
	b2 = ft_bs_new(8);
	ft_bs_set_raw(b2, 0, 0xAD);
	r = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	if (ft_bs_append(b1, b2) != false)
		r = 1;
	talloc_set_failpoint(fp);
	ft_bs_free(&b1);
	ft_bs_free(&b2);
	return (r);
}

static void	reset_bitsets(t_bitset **b1, t_bitset **b2)
{
	if (*b1)
		ft_bs_free(b1);
	if (*b2)
		ft_bs_free(b2);
	*b1 = ft_bs_new(8);
	*b2 = ft_bs_new(8);
	ft_bs_set_raw(*b1, 0, 0b10000001);
	ft_bs_set_raw(*b2, 0, 0b01111110);
	return ;
}

int	tb_append(void)
{
	t_bitset	*bitset1;
	t_bitset	*bitset2;

	bitset1 = NULL;
	bitset2 = NULL;
	reset_bitsets(&bitset1, &bitset2);
	ft_bs_append(bitset1, bitset2);
	if (ft_bs_get_raw(bitset1, 0) != 0b10000001
		|| ft_bs_get_raw(bitset1, 1) != 0b01111110)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 1);
	reset_bitsets(&bitset1, &bitset2);
	ft_bs_set_raw(bitset1, 0, 0b00001001);
	ft_bs_append(bitset1, bitset2);
	if (ft_bs_get(bitset1, 0) != true || ft_bs_get(bitset1, 3) != true)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 2);
	reset_bitsets(&bitset1, &bitset2);
	ft_bs_set_raw(bitset2, 0, 0b00001111);
	ft_bs_append(bitset1, bitset2);
	if (ft_bs_get_raw(bitset1, 1) != 0b00001111)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 3);
	if (ft_bs_append(bitset1, NULL) != false
		|| ft_bs_append(NULL, bitset1) != false
		|| ft_bs_append(NULL, NULL) != false)
		return (ft_bs_free(&bitset1), ft_bs_free(&bitset2), 4);
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
