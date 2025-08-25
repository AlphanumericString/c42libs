/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsn_sstoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:43:54 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/16 17:48:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bits/posix1_lim.h"
#include "ft_string.h"
#include "tests/str__num_tests.h"
#include "ft_defs.h"

#include <stdint.h>
#include <limits.h>
#include <stdio.h>

static bool	check(ssize_t nbr, const char *base, const char *exp)
{
	char	*res;

	res = ft_sstoa_base(nbr, base);
	if (!res || ft_strcmp(res, exp) != 0)
		return (ft_free(res), false);
	return (ft_free(res), true);
}

static const char	**load_expecteds(void)
{
	static const char		*expected[] = {
		"0", "23", "42", "99", "2147483647", "9223372036854775807",
		"-2147483648", "-9223372036854775808",
		"0", "17", "2a", "63", "7fffffff", "7fffffffffffffff", "-80000000",
		"-8000000000000000",
		"0", "10111", "101010", "1100011", "1111111111111111111111111111111",
		"111111111111111111111111111111111111111111111111111111111111111",
		"-10000000000000000000000000000000",
		"-1000000000000000000000000000000000000000000000000000000000000000"};

	return ((const char **)expected);
}

// TODO: function for nbr array gen + bases + expecteds
// even if we must tag a fold operation for the puts...
// its too line-hungry atm
//
int	tsn_sstoa_base(void)
{
	const ssize_t	nbrs[] = {0, 23, 42, 99, INT_MAX, SSIZE_MAX, INT_MIN,
		SSIZE_MIN};
	const char		*bases[] = {FT_DECBASE, FT_HEXBASE, FT_BINBASE};
	const char		**expected = (const char **)load_expecteds();
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
				return (i + j * 100 + 1);
			i++;
		}
		j++;
	}
	if (ft_sstoa_base(SIZE_MAX, FT_DECBASE FT_DECBASE) != NULL
		|| ft_sstoa_base(SIZE_MAX, NULL) != NULL)
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
