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

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/str__num_tests.h"

/*
 * sorted lists:

{"atod", tsn_atod},
{"atoi_base", tsn_atoi_base},
{"atoi", tsn_atoi},
{"atol_base", tsn_atol_base},
{"atol_base", tsn_atol_base},
{"atoll", tsn_atoll},
{"atol", tsn_atol},
{"base_valid", tsn_base_valid},
{"itoa_base", tsn_itoa_base},
{"itoa", tsn_itoa},
{"sstoa_base", tsn_sstoa_base},
{"sstopa_base", tsn_sstopa_base},
{"stoa_base", tsn_stoa_base},
{"stopa_base", tsn_stopa_base},
{"utoa", tsn_utoa},

*/

static const t_fnamed	*tsn_tests(void)
{
	static const t_fnamed	tests[] = {
	{"atod", tsn_atod}, {"atoi_base", tsn_atoi_base}, {"atoi", tsn_atoi},
	{"atol_base", tsn_atol_base}, {"atol_base", tsn_atol_base},
	{"atoll", tsn_atoll}, {"atol", tsn_atol}, {"base_valid", tsn_base_valid},
	{"itoa_base", tsn_itoa_base}, {"itoa", tsn_itoa},
	{"sstoa_base", tsn_sstoa_base}, {"sstopa_base", tsn_sstopa_base},
	{"stoa_base", tsn_stoa_base}, {"stopa_base", tsn_stopa_base},
	{"utoa", tsn_utoa}, {NULL, NULL}};

	return (tests);
}

t_module	*num_conv_tests(void)
{
	int				i;
	const t_fnamed	*funcs = tsn_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "num", "numerical strings conversion functions module.");
	while (funcs[i].name)
	{
		add_test_f(args, funcs[i].test, funcs[i].name);
		i++;
	}
	return (args);
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
