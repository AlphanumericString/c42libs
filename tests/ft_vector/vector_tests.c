/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:38:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/vector_tests.h"
#include "tests/tests__all_modules_tests.h"

int	tests_vector(void)
{
	int				collect;
	const t_test	tests[] = {
	{"add", test_vec_add}, {"apply", test_vec_apply}, {"at", test_vec_at}, \
	{"cat", test_vec_cat}, {"clear", test_vec_clear}, \
	{"destroy", test_vec_destroy}, {"filter", test_vec_filter}, \
	{"map", test_vec_map}, {"new", test_vec_new}, {"pop", test_vec_pop}, \
	{"from_size", test_vec_from_size}, {"from_array", test_vec_from_array}, \
	{"convert_alloc_array", test_vec_convert_alloc_array}, \
	{"remove", test_vec_remove}, {"remove_if", test_vec_remove_if}, \
	{"reserve", test_vec_reserve}, {"reverse", test_vec_reverse}, \
	{"shift", test_vec_shift}, {"sort", test_vec_sort}, \
	{"shrink", test_vec_shrink}, {"swap", test_vec_swap}, \
	{"get", test_vec_get}, {"to_array", test_vec_to_array}, \
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
