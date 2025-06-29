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

#include "tests/tests.h"
#include "tests/str__mem_tests.h"

int	mem_tests(void)
{
	int				collect;
	const t_test	tests[] = {
	{"apply_2d", tca_apply_2d}, {"free_2d", tca_free_2d},
	{"len_2d", tca_len_2d},
	{"fd_to_buff", tm_fd_to_buff}, {"bzero", tm_bzero},
	{"calloc", tm_calloc}, {"realloc", tm_realloc}, {"free", tm_free},
	{"free_clear", tm_freecl}, {"memchr", tm_memchr}, {"memcmp", tm_memcmp},
	{"memcpy", tm_memcpy}, {"memmap", tm_memmap}, {"memmove", tm_memmove},
	{"memset", tm_memset}, {"swap", tm_swap}, {"qsort", tm_qsort},
	{"allocator_ctl", tmal_allocator}, {"calloc", tmal_calloc},
	{"realloc", tmal_realloc}, {"reallocarray", tmal_reallocarray},
	{"malloc", tmal_malloc}, {"free", tmal_free},
	{"arena", tma_arena}, {"narena", tma_narena},
	{NULL, NULL}};

	collect = 0;
	run_test(tests, &collect);
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
