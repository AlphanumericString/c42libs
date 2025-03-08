/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:27:46 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:40:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/map_tests.h"

// see with --leak-check=full
int	tests_map(void)
{
	int				collect;
	const t_test	test[] = {
	{"create", test_map_create},
	{"destroy", test_map_destroy}, // here
	{"destroy_free", test_map_destroy_free},
	{"clear", test_map_clear}, // here
	{"set", test_map_set},
	{"set_cmp", test_map_set_cmp},
	{"set_hash", test_map_set_hash},
	{"get", test_map_get},
	{"size", test_map_size},
	{"capacity", test_map_capacity},
	{"remove", test_map_remove}, // here
	{"hash", test_map_hash},
	{NULL, NULL}
	};

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
