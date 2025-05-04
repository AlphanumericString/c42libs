/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_atol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 22:55:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests__all_modules_tests.h"
#include "ft_string.h"

int	test_atol(void)
{
	size_t		i;
	const int	t_cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000, \
	-1, -9, -10, -99, -100, -999, -1000, -9999, -10000};
	const char	*t_str[] = {"0", "1", "9", "10", "99", "100", "999", "1000", \
	"9999", "10000", "-1", "-9", "-10", "-99", "-100", "-999", "-1000", \
	"-9999", "-10000"};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		if (ft_atol(t_str[i]) != t_cases[i])
			return (i + 1);
		i++;
	}
	if (ft_atol(" --99") != 99 || ft_atol(" -0") != 0 || \
	ft_atol(" -++--1") != -1)
		return (30);
	if (ft_atol("toto") != 0 || ft_atol("-toto") != 0 || ft_atol("toto-") \
	!= 0 || ft_atol("a") != 0 || ft_atol("01234\t56789") != 1234)
		return (31);
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
