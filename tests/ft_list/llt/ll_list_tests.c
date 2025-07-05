/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:17:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/30 07:41:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/ll_tests.h"

int	tests_linked_list_all(int depth)
{
	int				collect;
	const t_test	test[] = {
	{"add_front", t_ll_add_front}, {"add_back", t_ll_add_back},
	{"apply", t_ll_apply},	{"apply_range", t_ll_apply_range},
	{"apply_range_node", t_ll_apply_range_node}, {"begin", t_ll_begin},
	{"clear", t_ll_clear}, {"create", t_ll_create},
	{"copy_node", t_ll_copy_node}, {"copy_list", t_ll_copy_list},
	{"delone", t_ll_delone}, {"delete_range", t_ll_delete_range},
	{"delete", t_ll_delete}, {"find", t_ll_find},
	{"get_datas", t_ll_get_datas}, {"get_nodes", t_ll_get_nodes},
	{"end", t_ll_end}, {"at", t_ll_at}, {"map", t_ll_map}, {"new", t_ll_new},
	{"push", t_ll_push}, {"push_back", t_ll_push_back}, {"pop", t_ll_pop},
	{"pop_back", t_ll_pop_back}, {"rev", t_ll_rev}, {"size", t_ll_size},
	{"size_match", t_ll_size_match}, {"size_cmp", t_ll_size_cmp},
	{"subrange", t_ll_subrange}, {"check_circular", t_ll_check_circular},
	{"check_sorted", t_ll_check_sorted}, {"check_health", t_ll_check_health},
	{NULL, NULL}};

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
