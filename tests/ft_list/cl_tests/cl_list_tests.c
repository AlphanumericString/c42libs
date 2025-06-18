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
	{"add_front", t_cl_add_front}, {"add_back", t_cl_add_back},
	{"apply", t_cl_apply}, {"apply_range", t_cl_apply_range},
	{"apply_range_node", t_cl_apply_range_node},
	{"check_circular", t_cl_check_circular}, {"check_sorted", t_cl_check_sorted},
	{"check_health", t_cl_check_health},
	{"clear", t_cl_clear}, {"clear_range", t_cl_clear_range},
	{"create", t_cl_create}, {"copy_node", t_cl_copy_node},
	{"copy_list", t_cl_copy_list},
	{"delete", t_cl_delete}, {"delete_range", t_cl_delete_range},
	{"find", t_cl_find},
	{"get_datas", t_cl_get_datas}, {"get_nodes", t_cl_get_nodes},
	{"at", t_cl_at}, {"begin", t_cl_begin}, {"end", t_cl_end},
	{"map", t_cl_map},
	{"new", t_cl_new},
	{"push", t_cl_push}, {"push_back", t_cl_push_back},
	{"pop", t_cl_pop}, {"pop_back", t_cl_pop_back},
	{"rev", t_cl_rev},
	{"size", t_cl_size}, {"size_data_is", t_cl_size_data_is},
	{"size_cmp", t_cl_size_cmp},
	{"subrange", t_cl_subrange},
	{NULL, NULL}};

	return (var);
}

int	tests_circular_linked_list_all(void)
{
	int				collect;
	const t_test	*test = init_tests();

	collect = 0;
	run_test(test, &collect);
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
