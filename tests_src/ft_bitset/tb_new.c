/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 03:46:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bitset.h"
#include "tests/bitset_tests.h"
#include "tests/fixtures.h"
#include "types/ft_bitset_types.h"

static int	mt_bsnew(void)
{
	const int	fp = *talloc_get_failpoint();
	t_bitset	*bs;

	talloc_set_failpoint(0);
	bs = ft_bs_new(12);
	if (bs)
		return (1);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	bs = ft_bs_new(12);
	if (bs)
		return (2);
	talloc_set_failpoint(fp);
	return (0);
}

int	tb_new(void)
{
	t_bitset	*bs;

	bs = ft_bs_new(64);
	if (!bs)
		return (1);
	if (bs->_capacity != 64 / 8)
		return (2);
	ft_bs_free(&bs);
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
