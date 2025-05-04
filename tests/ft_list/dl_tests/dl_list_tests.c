/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl_list_tests.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:37:03 by iron              #+#    #+#             */
/*   Updated: 2025/04/06 16:04:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/dl_tests.h"

static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"add_front", t_dl_add_front}, {"add_back", t_dl_add_back}, \
	{"apply", t_dl_apply}, {"apply_range", t_dl_apply_range}, \
	{"apply_range_node", t_dl_apply_range_node}, {"clear", t_dl_clear}, \
	{"clear_range", t_dl_clear_range}, {"create", t_dl_create}, \
	{"copy_node", t_dl_copy_node}, {"copy_list", t_dl_copy_list}, \
	{"delete_self", t_dl_delete_self}, {"delete_range", t_dl_delete_range}, \
	{"delete", t_dl_delete}, {"find", t_dl_find}, \
	{"get_datas", t_dl_get_datas}, {"get_nodes", t_dl_get_nodes}, \
	{"at", t_dl_at}, {"begin", t_dl_begin}, {"end", t_dl_end}, \
	{"map", t_dl_map}, {"new", t_dl_new}, {"pop", t_dl_pop}, \
	{"pop_back", t_dl_pop_back}, {"push", t_dl_push}, \
	{"push_back", t_dl_push_back}, {"rev", t_dl_rev}, {"size", t_dl_size}, \
	{"size_datais", t_dl_size_datais}, {"size_datacmp", t_dl_size_cmp}, \
	{"subrange", t_dl_subrange}, {"check_circular", t_dl_check_circular}, \
	{"check_sorted", t_dl_check_sorted}, {"check_health", t_dl_check_health}, \
	{NULL, NULL}};

	return (var);
}

int	tests_doubly_linked_list_all(void)
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
