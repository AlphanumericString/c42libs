/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitset_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 01:31:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:02:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/bitset_tests.h"
#include "tests/tests.h"

// {"new", tb_new}, {"create", tb_create}, {"new_from_str", tb_new_from_str},
// {"clear", tb_clear}, {"free", tb_free}, {"free_inner", tb_free_inner},
// {"get_raw", tb_get_raw}, {"get", tb_get}, {"set_raw", tb_set_raw},
// {"set", tb_set}, {"toggle", tb_toggle}, {"toggle_raw", tb_toggle_raw},
// {"print", tb_print}, {"print_binary", tb_print_binary},
// {"print_hex", tb_print_hex}, {"print_decimal", tb_print_decimal},
// {"append", tb_append}, {"remove", tb_remove},
// {"remove_front", tb_remove_front}, {NULL, NULL}};
static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"new", tb_new}, {"create", tb_create}, {"new_from_mem", tb_new_from_mem},
	{"clear", tb_clear}, {"free", tb_free}, {"free_inner", tb_free_inner},
	{"get_raw", tb_get_raw}, {"get", tb_get}, {"set_raw", tb_set_raw},
	{"set", tb_set}, {"toggle", tb_toggle}, {"toggle_raw", tb_toggle_raw},
	{"print", tb_print}, {"print_binary", tb_print_binary},
	{"print_hex", tb_print_hex}, {"print_decimal", tb_print_decimal},
	{"append", tb_append}, {"remove", tb_remove},
	{"remove_front", tb_remove_front}, {NULL, NULL}};

	return (var);
}

int	tests_bitset(int depth)
{
	const t_test	*test = init_tests();
	int				collect;

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
