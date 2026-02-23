/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/30 07:28:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/vector_tests.h"

// TODO: pure tests for already implemented functions:
//
// TODO: maybe add iterators for :{max min last first} ?
// TODO: tv_fold (doesn't take initial value)
// TODO: tv_reduce (takes initial value)
//
static const t_fnamed	*tv_tests(void)
{
	static const t_fnamed	tests[] = {
	{"add", tv_add}, {"apply", tv_apply}, {"at", tv_at}, {"cat", tv_cat},
	{"clear", tv_clear}, {"convert_alloc_array", tv_convert_alloc_array},
	{"create", tv_create}, {"delete", tv_delete}, {"destroy", tv_destroy},
	{"dup", tv_dup}, {"filter-out", tv_filterout}, {"filter", tv_filter},
	{"find", tv_find}, {"from_array", tv_from_array},
	{"from_size", tv_from_size}, {"inuse", tv_inuse}, {"insert", tv_insert},
	{"map", tv_map}, {"new", tv_new}, {"pop", tv_pop},
	{"remove", tv_remove}, {"nremove", tv_nremove},
	{"reserve", tv_reserve}, {"reverse", tv_reverse}, {"shift", tv_shift},
	{"shrink", tv_shrink}, {"sort", tv_sort}, {"swap", tv_swap},
	{"to_array", tv_to_array}, {NULL, NULL}
	};

	return (tests);
}

t_module	*tests_vector(void)
{
	int				i;
	const t_fnamed	*funcs = tv_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "vector", "vectors module.");
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
