/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/14 23:11:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/str__mem_tests.h"

int	mem_tests(void)
{
	int				collect;
	const t_test	tests[] = {
	{"apply_2d", test_apply_2d}, {"free_2d", test_free_2d},
	{"len_2d", test_len_2d}, {"fd_to_buff", test_fd_to_buff},
	{"bzero", test_bzero},
	{"calloc", test_calloc}, {"realloc", test_realloc}, {"free", test_free},
	{"free_clear", test_freecl},
	{"memchr", test_memchr}, {"memcmp", test_memcmp},
	{"memcpy", test_memcpy}, {"memmap", test_memmap}, {"memmove", test_memmove},
	{"memset", test_memset}, {"swap", test_swap}, {"qsort", test_qsort},
	{NULL, NULL}
	};

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
