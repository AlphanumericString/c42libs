/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:36:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/21 00:20:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

#include <unistd.h>

int	tests_string(int depth)
{
	size_t			i;
	int				collect;
	const t_module	modules[] = {
	{"characters", "char", char_tests, 0},
	{"memory", "mem", mem_tests, 0},
	{"string", "str", str_tests, 0},
	{"growable strings", "t_string", t_string_tests, 0},
	{"string output", "put", put_tests, 0},
	{"number conversions", "num", num_conv_tests, 0},
	{NULL, NULL, NULL, 0}
	};

	i = 0;
	collect = 0;
	while (modules[i].test)
		collect += run_module(modules[i++], depth);
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
