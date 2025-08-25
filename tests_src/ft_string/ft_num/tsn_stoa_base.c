/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsn_stoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:31:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/16 17:48:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__num_tests.h"
#include "ft_defs.h"
#include "ft_string.h"
#include <limits.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>

static	bool	check(size_t nbr, const char *base, const char *exp)
{
	char	*s;

	s = ft_stoa_base(nbr, base);
	if (!s || ft_strcmp(s, exp) != 0)
		return (ft_free(s), false);
	return (ft_free(s), true);
}

static const char	**load_expected(void)
{
	static const char	*expected[] = {
		"0", "1", "9", "10", "99", "100", "999", "1000", "9999",
		"10000", "2147483647", "18446744073709551615",
		"0", "1", "9", "a", "63", "64", "3e7", "3e8", "270f", "2710",
		"7fffffff", "ffffffffffffffff",
		"0", "1", "1001", "1010", "1100011", "1100100", "1111100111",
		"1111101000", "10011100001111", "10011100010000",
		"1111111111111111111111111111111",
		"1111111111111111111111111111111111111111111111111111111111111111"};

	return (expected);
}

// TODO: function for nbr array gen + bases + expecteds
// even if we must tag a fold operation for the puts...
// its too line-hungry atm
//
int	tsn_stoa_base(void)
{
	const size_t	nbrs[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000,
		INT_MAX, SIZE_MAX};
	const char		*bases[] = {FT_DECBASE, FT_HEXBASE, FT_BINBASE};
	const char		**expected = (const char **)load_expected();
	size_t			i;
	size_t			j;

	j = 0;
	while (j < sizeof(bases) / sizeof(bases[0]))
	{
		i = 0;
		while (i < sizeof(nbrs) / sizeof(nbrs[0]))
		{
			if (check(nbrs[i], bases[j],
					expected[j * sizeof(nbrs) / sizeof(nbrs[0]) + i]) == false)
				return (i + j * 100);
			i++;
		}
		j++;
	}
	if (ft_stoa_base(SIZE_MAX, FT_DECBASE FT_DECBASE) != NULL
		|| ft_stoa_base(SIZE_MAX, NULL) != NULL)
		return (42);
	return (0);
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
