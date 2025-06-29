/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:54:08 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 21:16:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "internal/debug_defs.h"
#include "tests/bitset_tests.h"
#include "tests/tests.h"

static int	mt_bsnew(void)
{
	const int	fp = *talloc_get_failpoint();
	t_bitset	bitset;

	talloc_set_failpoint(0);
	bitset = ft_bs_create(12);
	if (bitset.bits)
		return (1 + 10);
	talloc_set_failpoint(fp);
	return (0);
}

int	tb_create(void)
{
	t_bitset	bitset;

	bitset = ft_bs_create(64);
	if (bitset._capacity != 64 / 8)
		return (1);
	if (!bitset.bits)
		return (2);
	ft_bs_free_inner(&bitset);
	bitset = ft_bs_create(0);
	if (bitset._capacity != 0 || bitset.bits != NULL)
		return (3);
	return (mt_bsnew());
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
