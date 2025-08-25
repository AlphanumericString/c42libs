/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:27:46 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/map_tests.h"

static const t_fnamed	*tmap_tests(void)
{
	static const t_fnamed	tests[] = {
	{"create", tmap_create},
	{"destroy", tmap_destroy}, // here
	{"destroy_free", tmap_destroy_free},
	{"clear", tmap_clear}, // here
	{"set", tmap_set},
	{"set_cmp", tmap_set_cmp},
	{"set_hash", tmap_set_hash},
	{"get", tmap_get},
	{"size", tmap_size},
	{"capacity", tmap_capacity},
	{"remove", tmap_remove}, // here
	{"hash", tmap_hash},
	{NULL, NULL}
	};

	return (tests);
}

// see with --leak-check=full
t_module	*tests_map(void)
{
	int				i;
	const t_fnamed	*funcs = tmap_tests();
	t_module		*args;

	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "map", "hash maps handling module.");
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
