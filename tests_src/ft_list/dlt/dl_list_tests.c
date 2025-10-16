/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2025/05/30 07:34:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/list__dl_tests.h"

static const t_fnamed	*dl_tests(void)
{
	static const t_fnamed	var[] = {
	{"add_front", tdl_add_front}, {"add_back", tdl_add_back},
	{"apply", tdl_apply}, {"apply_range", tdl_apply_range},
	{"apply_range_node", tdl_apply_range_node}, {"clear", tdl_clear},
	{"clear_range", tdl_clear_range}, {"create", tdl_create},
	{"copy_node", tdl_copy_node}, {"copy_list", tdl_copy_list},
	{"delete_self", tdl_delete_self}, {"delete_range", tdl_delete_range},
	{"delete", tdl_delete}, {"find", tdl_find},
	{"get_datas", tdl_get_datas}, {"get_nodes", tdl_get_nodes},
	{"at", tdl_at}, {"begin", tdl_begin}, {"end", tdl_end},
	{"map", tdl_map}, {"new", tdl_new}, {"pop", tdl_pop},
	{"pop_back", tdl_pop_back}, {"push", tdl_push},
	{"push_back", tdl_push_back}, {"rev", tdl_rev}, {"size", tdl_size},
	{"size_datais", tdl_size_datais}, {"size_datacmp", tdl_size_cmp},
	{"subrange", tdl_subrange}, {"check_circular", tdl_check_circular},
	{"check_sorted", tdl_check_sorted}, {"check_health", tdl_check_health},
	{"xtract_max", tdl_extract_max}, {"xtract_max_node", tdl_extract_max_node},
	{"xtract_min", tdl_extract_min}, {"xtract_min_node", tdl_extract_min_node},
	{"issort", tdl_issort}, {"sort", tdl_sort},
	{NULL, NULL}};

	return (var);
}

t_module	*tests_doubly_linked_list_all(void)
{
	int				i;
	const t_fnamed	*funcs = dl_tests();
	t_module		*args;

	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "dll", "doubly linked lists module.");
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
