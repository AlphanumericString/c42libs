/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2025/06/20 21:08:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_args.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/tests.h"

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

static const t_module	*get_tests(void)
{
	static const t_module	tests[] = {
	{"linked list", "list", tests_lists, 0},
	{"string", "str", tests_string, 0},
	{"vector", "vec", tests_vector, 0},
	{"hashmaps", "map", tests_map, 0},
	{"optional", "opt", tests_optional, 0},
	{"arguments", "arg", tests_args, 0},
	{"math", "math", tests_math, 0},
	{"pair", "pair", tests_pair, 0},
	{"bitset", "bs", tests_bitset, 0},
	{NULL, NULL, NULL, 0}
	};

	return (tests);
}

// setup stuff for tests
static void	setup(const char *av[], const char **target)
{
	size_t	it;

	ft_setup_prog((char const *const *)av);
	if (SRAND_OK)
		srand(time(NULL));
	tverbose_set(VERBOSE);
	ft_set_gnu_alloc();
	talloc_wrapper_setup();
	talloc_set_failpoint(INT_MAX);
	talloc_set_currentpoint(0);
	it = 1;
	if (av[it] && (!ft_strcmp(av[it], "--verbose") || !ft_strcmp(av[it], "-v")))
	{
		it++;
		if (av[it] && ft_str_isdigit(av[it]))
			tverbose_set(ft_atoi(av[it++]));
	}
	if (av[it] == NULL || (av[it] && !ft_strcmp(av[it], "all")))
		*target = "all";
	else
		*target = av[it++];
}

int	run_module(t_module module, int depth)
{
	const char	*r_s[] = {" \033[32mOK\033[0m", " \033[31mKO\033[0m"};
	const char	*md_type[] = {"main ", "\tsub-", "\t\tnested sub-"};
	const char	*_md;
	int			collect;

	if (depth > 1)
		_md = md_type[2];
	else
		_md = md_type[depth];
	if (tverbose() == VER_ALL || tverbose() == VER_MODULES
		|| tverbose() == VER_SUB_MODULES)
		ft_print_fd(STDOUT_FILENO, "\n%smodule %s\n", _md, module.full_name);
	collect = module.test(depth + 1);
	ft_print_fd(STDOUT_FILENO, "%smodule:: %s ", _md, module.full_name);
	ft_putendl_fd(r_s[collect != 0], STDOUT_FILENO);
	module.res = collect;
	return (collect);
}

//we only use putstr_fd and putendl_fd to avoid any error in the test
//	infrastructure itself
static int	print_help_tests(const t_module *tests)
{
	size_t	i;

	i = 0;
	ft_print_fd(STDOUT_FILENO, "Usage: %s [module_name]\n", ft_progname());
	ft_print_fd(STDOUT_FILENO, "Available modules are:\n");
	while (tests[i].full_name)
		ft_print_fd(STDOUT_FILENO, " - '%s'\n", tests[i++].short_name);
	ft_putendl_fd("Or use 'all' to run all tests", STDOUT_FILENO);
	ft_putendl_fd("If no argument is passed, all tests will be run",
		STDOUT_FILENO);
	ft_putendl_fd("Use -h to display this help", STDOUT_FILENO);
	return (EXIT_SUCCESS);
}

// by default, run all tests
// otherwise, run the tests for the module passed as argument
int	main(int ac, const char *av[])
{
	int				collect;
	size_t			i;
	const char		*target;
	const t_module	*tests = get_tests();
	const char		*res_str[2] = {"\033[32mAll tests passed\033[0m",
		"\033[31mSome tests failed\033[0m"};

	i = 0;
	collect = 0;
	setup(av, &target);
	if (ac > 1 && !ft_strcmp(av[1], "-h"))
		return (print_help_tests(tests), EXIT_SUCCESS);
	while (tests[i].full_name)
	{
		if (!ft_strcmp(target, "all")
			|| (!ft_strcmp(target, tests[i].short_name)
				|| !ft_strcmp(target, tests[i].full_name)))
			collect += run_module(tests[i], 0);
		i++;
	}
	return (ft_putendl_fd(res_str[collect != 0], STDOUT_FILENO),
		collect != 0);
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
