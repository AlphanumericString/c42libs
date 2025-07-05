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
#include "tests/tests.h"
#include "unistd.h"
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

// TODO: update tests files structure arboresence to reflect src
//	-done
//	-> modify tests fixture to have tests && modules in modules
//		eg: mem -> [ft_bzero, ... && [ft_arr [ft_aaply, ...], ft_arnea [...]]

static const t_module	*get_tests(void)
{
	static const t_module	tests[] = {
	{"linked list", "list", tests_lists},
	{"string", "str", tests_string},
	{"vector", "vec", tests_vector},
	{"hashmaps", "map", tests_map},
	{"optional", "opt", tests_optional},
	{"arguments", "arg", tests_args},
	{"math", "math", tests_math},
	{"pair", "pair", tests_pair},
	{"bitset", "bs", tests_bitset},
	{NULL, NULL, NULL}
	};

	return (tests);
}

// setup stuff for tests
static void	setup(const char *av[])
{
	ft_setup_prog((char const *const *)av);
	if (SRAND_OK)
		srand(time(NULL));
	ft_set_gnu_alloc();
	talloc_wrapper_setup();
	talloc_set_failpoint(INT_MAX);
	talloc_set_currentpoint(0);
}

int	run_module(const t_module module, int depth)
{
	const char	*r_s[] = {" \033[32mOK\033[0m", " \033[31mKO\033[0m"};
	const char	*md_type[] = {"main module", "sub-module", "nested sub-module"};
	const char	*_md;
	int			collect;

	if (depth > 1)
		_md = md_type[2];
	else
		_md = md_type[depth];
	if (depth <= VERBOSE)
		ft_print_fd(STDOUT_FILENO, "\n%s %s\n", _md, module.full_name);
	collect = module.test(depth + 1);
	ft_print_fd(STDOUT_FILENO, "%s:: %s ", _md, module.full_name);
	ft_putendl_fd(r_s[collect != 0], STDOUT_FILENO);
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
	setup(av);
	if (ac > 1 && !ft_strcmp(av[1], "-h"))
		return (print_help_tests(tests), EXIT_SUCCESS);
	if (ac < 2 || (av[1] && !ft_strcmp(av[1], "all")))
		target = "all";
	else
		target = av[1];
	while (tests[i].full_name)
	{
		if (ac < 2 || (!ft_strcmp(target, tests[i].short_name)
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
