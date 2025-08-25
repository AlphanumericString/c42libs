/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:53:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 13:56:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/pair_tests.h"
#include "ft_allocator__dev.h"
#include "tests/tests.h"

static const t_fnamed	*tp_tests(void)
{
	static const t_fnamed	tests[] = {
	{"set", tp_set}, {"new", tp_new},
	{"first", tp_first}, {"second", tp_second},
	{"cmp", tp_cmp}, {"cmp_first", tp_cmp_first},
	{"cmp_second", tp_cmp_second},
	{"destroy", tp_destroy}, {"destroy_sep", tp_destroy_sep},
	{NULL, NULL}
	};

	return (tests);
}

t_module	*tests_pair(void)
{
	int				i;
	const t_fnamed	*funcs = tp_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "pair", "pairs module.");
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
