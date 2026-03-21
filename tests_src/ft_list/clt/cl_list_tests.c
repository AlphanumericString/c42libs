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

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/list__cl_tests.h"

/*
 * todos:

 * Sorted list:

{"add_back", tcl_add_back},
{"add_front", tcl_add_front},
{"apply_range_node", tcl_apply_range_node},
{"apply_range", tcl_apply_range},
{"apply", tcl_apply},
{"at", tcl_at},
{"begin", tcl_begin},
{"check_circular", tcl_check_circular},
{"check_health", tcl_check_health},
{"check_sorted", tcl_check_sorted},
{"clear_range", tcl_clear_range},
{"clear", tcl_clear},
{"copy_list", tcl_copy_list},
{"copy_node", tcl_copy_node},
{"create", tcl_create},
{"delete_range", tcl_delete_range},
{"delete", tcl_delete},
{"end", tcl_end},
{"find", tcl_find},
{"get_datas", tcl_get_datas},
{"get_nodes", tcl_get_nodes},
{"issort", tcl_issort},
{"map", tcl_map},
{"mid", tcl_mid},
{"new", tcl_new},
{"pop_back", tcl_pop_back},
{"pop", tcl_pop},
{"push_back", tcl_push_back},
{"push", tcl_push},
{"rev", tcl_rev},
{"size_cmp", tcl_size_cmp},
{"size_data_is", tcl_size_data_is},
{"size", tcl_size},
{"sort", tcl_sort},
{"subrange", tcl_subrange},
{"xtract_max_node", tcl_extract_max_node},
{"xtract_max", tcl_extract_max},
{"xtract_min_node", tcl_extract_min_node},
{"xtract_min", tcl_extract_min},

*/

static const t_fnamed	*cl_tests(void)
{
	static const t_fnamed	var[] = {
	{"add_back", tcl_add_back}, {"add_front", tcl_add_front},
	{"apply_range_node", tcl_apply_range_node},
	{"apply_range", tcl_apply_range}, {"apply", tcl_apply}, {"at", tcl_at},
	{"begin", tcl_begin}, {"check_circular", tcl_check_circular},
	{"check_health", tcl_check_health}, {"check_sorted", tcl_check_sorted},
	{"clear_range", tcl_clear_range}, {"clear", tcl_clear},
	{"copy_list", tcl_copy_list}, {"copy_node", tcl_copy_node},
	{"create", tcl_create}, {"delete_range", tcl_delete_range},
	{"delete", tcl_delete}, {"end", tcl_end}, {"find", tcl_find},
	{"get_datas", tcl_get_datas}, {"get_nodes", tcl_get_nodes},
	{"issort", tcl_issort}, {"map", tcl_map}, {"mid", tcl_mid},
	{"new", tcl_new}, {"pop_back", tcl_pop_back}, {"pop", tcl_pop},
	{"push_back", tcl_push_back}, {"push", tcl_push}, {"rev", tcl_rev},
	{"size_cmp", tcl_size_cmp}, {"size_data_is", tcl_size_data_is},
	{"size", tcl_size}, {"sort", tcl_sort}, {"subrange", tcl_subrange},
	{"xtract_max_node", tcl_extract_max_node}, {"xtract_max", tcl_extract_max},
	{"xtract_min_node", tcl_extract_min_node}, {"xtract_min", tcl_extract_min},
	{NULL, NULL}};

	return (var);
}

t_module	*tests_circular_linked_list_all(void)
{
	int				i;
	const t_fnamed	*funcs = cl_tests();
	t_module		*args;

	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "cl", "circular linked lists handling module.");
	i = 0;
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
