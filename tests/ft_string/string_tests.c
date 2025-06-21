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

static const t_test	*load_submodules_tests(void)
{
	static const t_test	tests[] = {
	{"char", char_tests},
	{"mem", mem_tests},
	{"str", str_tests},
	{"t_string", t_string_tests},
	{NULL, NULL}
	};

	return (tests);
}

int	tests_string(void)
{
	size_t			i;
	int				collect;
	int				prev;
	const char		*sf_string[2] = {"\033[31mKO\033[0m", "\033[32mOK\033[0m"};
	const t_test	*tests = load_submodules_tests();

	i = 0;
	collect = 0;
	while (tests[i].name)
	{
		prev = collect;
		ft_print_fd(STDOUT_FILENO, "\nTesting sub-module::%s::\n",
			tests[i].name);
		collect += tests[i].test();
		ft_print_fd(STDOUT_FILENO, "Result sub-module::%s::\t%s",
			tests[i++].name, sf_string[prev == collect]);
	}
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
