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
#include "ft_allocator__dev.h"
#include "tests/tests.h"

/*
 * todos:
	TODO: check if for new_from_mem we can tjust use a memcmp to be clearer

 * sorted list:

{"append", tb_append},
{"clear", tb_clear},
{"create", tb_create},
{"free_inner", tb_free_inner},
{"free", tb_free},
{"get_raw", tb_get_raw},
{"get", tb_get},
{"new_from_mem", tb_new_from_mem},
{"new", tb_new},
{"print_binary", tb_print_binary},
{"print_decimal", tb_print_decimal},
{"print_hex", tb_print_hex},
{"print", tb_print},
{"remove_front", tb_remove_front}
{"remove", tb_remove},
{"set_raw", tb_set_raw},
{"set", tb_set},
{"toggle_raw", tb_toggle_raw},
{"toggle", tb_toggle},

*/
static const t_fnamed	*tb_tests(void)
{
	static const t_fnamed	var[] = {
	{"append", tb_append}, {"clear", tb_clear}, {"create", tb_create},
	{"free_inner", tb_free_inner}, {"free", tb_free}, {"get_raw", tb_get_raw},
	{"get", tb_get}, {"new_from_mem", tb_new_from_mem}, {"new", tb_new},
	{"print_binary", tb_print_binary}, {"print_decimal", tb_print_decimal},
	{"print_hex", tb_print_hex}, {"print", tb_print},
	{"remove_front", tb_remove_front}, {"remove", tb_remove},
	{"set_raw", tb_set_raw}, {"set", tb_set}, {"toggle_raw", tb_toggle_raw},
	{"toggle", tb_toggle}, {NULL, NULL}};

	return (var);
}

t_module	*tests_bitset(void)
{
	int				i;
	const t_fnamed	*funcs = tb_tests();
	t_module		*args;

	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "bitset", "bitset handling module");
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
