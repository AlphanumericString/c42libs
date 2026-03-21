/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator_tests.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:49:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 12:49:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/str__mem_tests.h"
#include "tests/tests.h"

/*
 * sorted list:

{"allocator_ctl", tmal_allocator},
{"calloc", tmal_calloc},
{"free", tmal_free},
{"malloc", tmal_malloc},
{"reallocarray", tmal_reallocarray},
{"realloc", tmal_realloc},

*/

static const t_fnamed	*tmal_tests(void)
{
	static const t_fnamed	tests[] = {
	{"allocator_ctl", tmal_allocator}, {"calloc", tmal_calloc},
	{"free", tmal_free}, {"malloc", tmal_malloc},
	{"reallocarray", tmal_reallocarray}, {"realloc", tmal_realloc},
	{NULL, NULL}};

	return (tests);
}

t_module	*allocator_module_tests(void)
{
	size_t			i;
	const t_fnamed	*funcs = tmal_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "allocator", "allocator functions.");
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
