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
	{"aapply", tca_aapply}, {"acat", tca_acat}, {"alcat", tca_alcat},
	{"aclear", tca_aclear}, {"acmp", tca_acmp}, {"acmpwith", tca_acmpwith},
	{"adup", tca_adup}, {"acpy", tca_acpy}, {"alcpy", tca_alcpy},
	{"afind", tca_afind}, {"afindwith", tca_afindwith}, {"afree", tca_afree},
	{"alen", tca_alen}, {"arfind", tca_arfind}, {"arfindwith", tca_arfindwith},
	{"atr", tca_atr}, {"amap", tca_amap}, {"anmap", tca_anmap},
	{"arena", tma_arena}, {"narena_alloc", tma_narena_alloc},
	{"narena_calloc", tma_narena_calloc}, {"narena_belong", tma_narena_belong},
	{"narena_free", tma_narena_free},
	{"fd_to_buff", tm_fd_to_buff}, {"bzero", tm_bzero},
	{"calloc", tm_calloc}, {"realloc", tm_realloc}, {"free", tm_free},
	{"free_clear", tm_freecl}, {"memchr", tm_memchr}, {"memcmp", tm_memcmp},
	{"memcpy", tm_memcpy}, {"memmap", tm_memmap}, {"memmove", tm_memmove},
	{"memset", tm_memset}, {"swap", tm_swap}, {"qsort", tm_qsort},
	{"allocator_ctl", tmal_allocator}, {"calloc", tmal_calloc},
	{"realloc", tmal_realloc}, {"reallocarray", tmal_reallocarray},
	{"malloc", tmal_malloc}, {"free", tmal_free},
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
