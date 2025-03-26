/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:36:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:45:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"

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
	const t_test	*tests = load_submodules_tests();

	i = 0;
	collect = 0;
	while (tests[i].name)
	{
		prev = collect;
		ft_putendl_fd("\nTesting::", STDOUT_FILENO);
		ft_putendl_fd(tests[i].name, STDOUT_FILENO);
		collect += tests[i++].test();
		ft_putstr_fd("\nTesting sub-module ", STDOUT_FILENO);
		ft_putstr_fd(tests[i - 1].name, STDOUT_FILENO);
		if (prev != collect)
			ft_putendl_fd(" \033[31mKO\033[0m", STDOUT_FILENO);
		else
			ft_putendl_fd(" \033[32mOK\033[0m", STDOUT_FILENO);
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
