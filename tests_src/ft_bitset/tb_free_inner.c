/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_free_inner.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

#include "ft_bitset.h"
#include "ft_mem.h"
#include "tests/bitset_tests.h"
#include "types/ft_bitset_types.h"

static	int	check_for_n(size_t	n)
{
	t_bitset	*bitset;

	bitset = ft_bs_new(n);
	if (!bitset)
		return (n != 0);
	ft_bs_free_inner(bitset);
	if (bitset->bits != NULL)
		return (ft_free(bitset), 2);
	ft_free(bitset);
	return (EXIT_SUCCESS);
}

int	tb_free_inner(void)
{
	t_bitset	*bitset;

	if (check_for_n(0))
		return (1);
	if (check_for_n(8) != EXIT_SUCCESS || check_for_n(16) != EXIT_SUCCESS)
		return (2);
	ft_bs_free_inner(NULL);
	bitset = ft_bs_new_from_mem("10101010", 8);
	if (!bitset)
		return (4);
	ft_bs_free_inner(bitset);
	if (bitset->bits != NULL)
		return (ft_free(bitset), 5);
	ft_free(bitset);
	if (check_for_n(100) != EXIT_SUCCESS || check_for_n(1000) != EXIT_SUCCESS
		|| check_for_n(10000) != EXIT_SUCCESS
		|| check_for_n(100000) != EXIT_SUCCESS)
		return (6);
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
