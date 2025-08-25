/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "tests/str__num_tests.h"
#include "ft_string.h"

static int	test_base_resps(const char *base, const int *expected_results,
		const char **inputs)
{
	int	i;
	int	res;

	i = 0;
	while (inputs[i])
	{
		res = ft_atoi_base(inputs[i], base);
		if (res != expected_results[i])
			return (i + 1);
		i++;
	}
	return (EXIT_SUCCESS);
}

static int	test_spaces(void)
{
	if (ft_atoi_base(" 0", FT_DECBASE) != 0
		|| ft_atoi_base(" 1", FT_DECBASE) != 1
		|| ft_atoi_base(" 9", FT_DECBASE) != 9
		|| ft_atoi_base(" 10", FT_DECBASE) != 10
		|| ft_atoi_base(" 99", FT_DECBASE) != 99
		|| ft_atoi_base(" -99", FT_DECBASE) != -99
		|| ft_atoi_base(" -0", FT_DECBASE) != 0
		|| ft_atoi_base(" -1", FT_DECBASE) != -1
		|| ft_atoi_base(" -10", FT_DECBASE) != -10
		|| ft_atoi_base(" -99", FT_DECBASE) != -99)
		return (1);
	return (EXIT_SUCCESS);
}

static int	test_multi_sign(void)
{
	if (ft_atoi_base(" --99", FT_DECBASE) != 99
		|| ft_atoi_base(" -0", FT_DECBASE) != 0
		|| ft_atoi_base(" -++--1", FT_DECBASE) != -1
		|| ft_atoi_base(" -+--10", FT_DECBASE) != -10
		|| ft_atoi_base(" -+--99", FT_DECBASE) != -99)
		return (1);
	return (EXIT_SUCCESS);
}

int	tsn_atoi_base(void)
{
	const char	*bases[] = {FT_DECBASE, FT_BINBASE, FT_HEXBASE};
	const int	expected_results[][11] = {
	{0, 1, 9, 10, 99, 0, -1, -9, -10, -99},
	{0, 1, 2, 3, 4, 0, -1, -2, -3, -4},
	{0, 10, 15, 16, 153, 0, -10, -15, -16, -153}
	};
	const char	*strs[][12] = {
	{"0", "1", "9", "10", "99", "0", "-1", "-9", "-10", "-99", NULL},
	{"0", "1", "10", "11", "100", "0", "-1", "-10", "-11", "-100", NULL},
	{"0", "a", "f", "10", "99", "0", "-a", "-f", "-10", "-99", NULL}
	};

	if (test_base_resps(bases[0], expected_results[0], strs[0])
		|| test_base_resps(bases[1], expected_results[1], strs[1])
		|| test_base_resps(bases[2], expected_results[2], strs[2]))
		return (1);
	if (ft_atoi_base("23", "011") || ft_atoi_base("23", "0")
		|| ft_atoi_base("23", "1") || ft_atoi_base("23", "0123456789-")
		|| ft_atoi_base("23", "0123456789+") || ft_atoi_base("23", " 23"))
		return (2);
	if (test_spaces())
		return (3);
	if (test_multi_sign())
		return (4);
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
