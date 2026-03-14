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

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/list__ll_tests.h"

/*
TODOS for tests:
	- check dl

 * sorted list:

{"add_back", tll_add_back},
{"add_front", tll_add_front},
{"apply_range_node", tll_apply_range_node},
{"apply", tll_apply},
{"apply_range", tll_apply_range},
{"at", tll_at},
{"begin", tll_begin},
{"check_circular", tll_check_circular},
{"check_health", tll_check_health},
{"check_sorted", tll_check_sorted},
{"clear", tll_clear},
{"copy_list", tll_copy_list},
{"copy_node", tll_copy_node},
{"create", tll_create},
{"delete_range", tll_delete_range},
{"delete", tll_delete},
{"delone", tll_delone},
{"end", tll_end},
{"find", tll_find},
{"get_datas", tll_get_datas},
{"get_nodes", tll_get_nodes},
{"issort", tll_issort},
{"map", tll_map},
{"mid", tll_mid},
{"new", tll_new},
{"nsize", tll_nsize},
{"pop_back", tll_pop_back},
{"pop", tll_pop},
{"push_back", tll_push_back},
{"push", tll_push},
{"rev", tll_rev},
{"size_cmp", tll_size_cmp},
{"size_match", tll_size_match},
{"size", tll_size},
{"sort", tll_sort},
{"subrange", tll_subrange},
{"xtrct_max_node", tll_extract_max_node},
{"xtrct_max", tll_extract_max},
{"xtrct_min_node", tll_extract_min_node},
{"xtrct_min", tll_extract_min},

*/

static const t_fnamed	*ll_tests(void)
{
	static const t_fnamed	test[] = {
	{"add_back", tll_add_back}, {"add_front", tll_add_front},
	{"apply_range_node", tll_apply_range_node}, {"apply", tll_apply},
	{"apply_range", tll_apply_range}, {"at", tll_at}, {"begin", tll_begin},
	{"check_circular", tll_check_circular}, {"check_health", tll_check_health},
	{"check_sorted", tll_check_sorted}, {"clear", tll_clear},
	{"copy_list", tll_copy_list}, {"copy_node", tll_copy_node},
	{"create", tll_create}, {"delete_range", tll_delete_range},
	{"delete", tll_delete}, {"delone", tll_delone}, {"end", tll_end},
	{"find", tll_find}, {"get_datas", tll_get_datas},
	{"get_nodes", tll_get_nodes}, {"issort", tll_issort}, {"map", tll_map},
	{"mid", tll_mid}, {"new", tll_new}, {"nsize", tll_nsize},
	{"pop_back", tll_pop_back}, {"pop", tll_pop}, {"push_back", tll_push_back},
	{"push", tll_push}, {"rev", tll_rev}, {"size_cmp", tll_size_cmp},
	{"size_match", tll_size_match}, {"size", tll_size}, {"sort", tll_sort},
	{"subrange", tll_subrange}, {"xtrct_max_node", tll_extract_max_node},
	{"xtrct_max", tll_extract_max}, {"xtrct_min_node", tll_extract_min_node},
	{"xtrct_min", tll_extract_min}, {NULL, NULL}};

	return (test);
}

t_module	*tests_linked_list_all(void)
{
	int				i;
	const t_fnamed	*funcs = ll_tests();
	t_module		*args;

	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "ll", "linked lists handling module");
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
