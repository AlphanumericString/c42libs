/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/30 07:28:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/vector_tests.h"
#include "tests/tests__all_modules_tests.h"

int	tests_vector(int depth)
{
	int				collect;
	const t_test	tests[] = {
	{"add", tv_add}, {"apply", tv_apply}, {"at", tv_at},
	{"cat", tv_cat}, {"clear", tv_clear},
	{"destroy", tv_destroy}, {"filter", tv_filter},
	{"map", tv_map}, {"new", tv_new}, {"pop", tv_pop},
	{"from_size", tv_from_size}, {"from_array", tv_from_array},
	{"convert_alloc_array", tv_convert_alloc_array},
	{"remove", tv_remove}, {"remove_if", tv_remove_if},
	{"reserve", tv_reserve}, {"reverse", tv_reverse},
	{"shift", tv_shift}, {"sort", tv_sort},
	{"shrink", tv_shrink}, {"swap", tv_swap},
	{"get", tv_get}, {"to_array", tv_to_array},
	{NULL, NULL}
	};

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
