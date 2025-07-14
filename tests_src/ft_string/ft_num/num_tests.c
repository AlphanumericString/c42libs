/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:10:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:10:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/str__num_tests.h"

static const t_test	*tsn_tests(void)
{
	static const t_test	tests[] = {
	{"itoa", tsn_itoa},
	{"utoa", tsn_utoa}, {"itoa_base", tsn_itoa_base},
	{"atoi", tsn_atoi}, {"atod", tsn_atod}, {"atol_base", tsn_atol_base},
	{"atoi_base", tsn_atoi_base}, {"atol", tsn_atol}, {"atoll", tsn_atoll},
	{"atol_base", tsn_atol_base},
	{NULL, NULL}};

	return (tests);
}

int	num_conv_tests(int depth)
{
	int				collect;
	const t_test	*tests = tsn_tests();

	collect = 0;
	run_test(tests, &collect, depth);
	return (collect);
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
