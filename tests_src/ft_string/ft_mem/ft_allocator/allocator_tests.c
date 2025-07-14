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

#include "tests/str__mem_tests.h"
#include "tests/tests.h"

static const t_test	*tmal_tests(void)
{
	static const t_test	tests[] = {
	{"allocator_ctl", tmal_allocator}, {"calloc", tmal_calloc},
	{"realloc", tmal_realloc}, {"reallocarray", tmal_reallocarray},
	{"malloc", tmal_malloc}, {"free", tmal_free}, {NULL, NULL}};

	return (tests);
}

int	allocator_module_tests(int depth)
{
	int				collect;
	const t_test	*tests = tmal_tests();

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
