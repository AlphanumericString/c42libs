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

static const t_test	*tm_tests(void)
{
	static const t_test	tests[] = {
	{"fd_to_buff", tm_fd_to_buff}, {"bzero", tm_bzero},
	{"calloc", tm_calloc}, {"realloc", tm_realloc}, {"free", tm_free},
	{"free_clear", tm_freecl}, {"memchr", tm_memchr}, {"memcmp", tm_memcmp},
	{"memcpy", tm_memcpy}, {"memmap", tm_memmap}, {"memmove", tm_memmove},
	{"memset", tm_memset}, {"swap", tm_swap}, {"qsort", tm_qsort},
	{NULL, NULL}};

	return (tests);
}

int	mem_tests(int depth)
{
	size_t			i;
	int				prev;
	int				collect;
	const t_module	sb[] = {
	{"c-style array", "arr", arr_module_tests, 0},
	{"memory arena", "arena", arena_module_tests, 0},
	{"memory allocator", "allocator", allocator_module_tests, 0},
	{NULL, NULL, NULL, 0}};
	const t_test	*tests = tm_tests();

	i = 0;
	collect = 0;
	while (sb[i].test)
		collect += run_module(sb[i++], depth);
	prev = 0;
	run_test(tests, &prev, depth);
	return (collect + prev);
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
