/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:49:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 12:47:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/cl_tests.h"

static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"add_front", tcl_add_front}, {"add_back", tcl_add_back},
	{"apply", tcl_apply}, {"apply_range", tcl_apply_range},
	{"apply_range_node", tcl_apply_range_node},
	{"check_circular", tcl_check_circular}, {"check_sorted", tcl_check_sorted},
	{"check_health", tcl_check_health}, {"clear", tcl_clear},
	{"clear_range", tcl_clear_range}, {"create", tcl_create},
	{"copy_node", tcl_copy_node}, {"copy_list", tcl_copy_list},
	{"delete", tcl_delete}, {"delete_range", tcl_delete_range},
	{"find", tcl_find}, {"get_datas", tcl_get_datas},
	{"get_nodes", tcl_get_nodes}, {"at", tcl_at}, {"begin", tcl_begin},
	{"end", tcl_end}, {"map", tcl_map}, {"new", tcl_new}, {"push", tcl_push},
	{"push_back", tcl_push_back}, {"pop", tcl_pop},
	{"pop_back", tcl_pop_back}, {"rev", tcl_rev}, {"size", tcl_size},
	{"size_data_is", tcl_size_data_is}, {"size_cmp", tcl_size_cmp},
	{"subrange", tcl_subrange},
	{NULL, NULL}};

	return (var);
}

int	tests_circular_linked_list_all(int depth)
{
	int				collect;
	const t_test	*test = init_tests();

	collect = 0;
	run_test(test, &collect, depth);
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
