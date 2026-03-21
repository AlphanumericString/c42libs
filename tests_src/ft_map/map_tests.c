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

/*
 * todos:

 * sorted list

{"capacity", tmap_capacity},
{"clear", tmap_clear}, // *
{"create", tmap_create},
{"destroy_free", tmap_destroy_free},
{"destroy", tmap_destroy}, // *
{"get", tmap_get},
{"hash", tmap_hash},
{"remove", tmap_remove}, // *
{"set_cmp", tmap_set_cmp},
{"set_hash", tmap_set_hash},
{"set", tmap_set},
{"size", tmap_size},

 *
*/

static const t_fnamed	*tmap_tests(void)
{
	static const t_fnamed	tests[] = {
	{"capacity", tmap_capacity}, {"clear", tmap_clear},
	{"create", tmap_create}, {"destroy_free", tmap_destroy_free},
	{"destroy", tmap_destroy}, {"get", tmap_get}, {"hash", tmap_hash},
	{"remove", tmap_remove}, {"set_cmp", tmap_set_cmp},
	{"set_hash", tmap_set_hash}, {"set", tmap_set}, {"size", tmap_size},
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
