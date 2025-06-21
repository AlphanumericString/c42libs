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

#include "tests/tests.h"
#include "tests/map_tests.h"

// see with --leak-check=full
int	tests_map(void)
{
	int				collect;
	const t_test	test[] = {
	{"create", tm_create},
	{"destroy", tm_destroy}, // here
	{"destroy_free", tm_destroy_free},
	{"clear", tm_clear}, // here
	{"set", tm_set},
	{"set_cmp", tm_set_cmp},
	{"set_hash", tm_set_hash},
	{"get", tm_get},
	{"size", tm_size},
	{"capacity", tm_capacity},
	{"remove", tm_remove}, // here
	{"hash", tm_hash},
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
