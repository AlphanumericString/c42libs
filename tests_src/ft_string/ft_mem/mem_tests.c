/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 17:29:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include "tests/str__mem_tests.h"
#include "unistd.h"
#include <stddef.h>

static const t_fnamed	*tm_tests(void)
{
	static const t_fnamed	tests[] = {
	{"fd_to_buff", tm_fd_to_buff}, {"bzero", tm_bzero},
	{"calloc", tm_calloc}, {"realloc", tm_realloc}, {"free", tm_free},
	{"free_clear", tm_freecl}, {"memchr", tm_memchr}, {"memcmp", tm_memcmp},
	{"memcpy", tm_memcpy}, {"memmap", tm_memmap}, {"memmove", tm_memmove},
	{"memset", tm_memset}, {"swap", tm_swap}, {"qsort", tm_qsort},
	{NULL, NULL}};

	return (tests);
}

t_module	*mem_tests(void)
{
	size_t					i;
	const t_mod_constructor	sbm[] = {arr_module_tests,
		arena_module_tests, allocator_module_tests, NULL};
	const t_fnamed			*funcs = tm_tests();
	t_module				*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "memory", "memory manipulation functions module.");
	while (funcs[i].name)
	{
		add_test_f(args, funcs[i].test, funcs[i].name);
		i++;
	}
	i = 0;
	while (sbm[i])
		add_submodule(args, sbm[i++]());
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
