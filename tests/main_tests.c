/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2025/06/18 12:54:14 by bgoulard         ###   ########.fr       */
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
/* Target:
 ┌─ ft_math
 ├─ ft_pair
 ├─ ft_optional
 │     ┌─ ft_stris
 │  ┌─ ft_str
 │  ├─ ft_chr
 │  ├─ ft_string
 │  │  ┌─ processors
 │  ├─ ft_put
 │  ├─ ft_num
 │  │  ┌─ ft_arr
 │  │  ├─ ft_arena
 │  │  ├─ ft_allocator
 │  ├─ ft_mem
 ├─ ft_string
 │  ┌─ ft_parse_args
 │  ├─ ft_set
 ├─ ft_args
 ├─ ft_map
 ├─ ft_vector
 ├─ ft_bitset
 │  ┌─ ft_dl
 │  ├─ ft_cl
 │  ├─ ft_ll
 ├─ ft_list
 tests
*/

static const t_module	*get_tests(void)
{
	static const t_module	tests[] = {
	{"string", "str", tests_string},
	{"vector", "vec", tests_vector},
	{"hashmaps", "map", tests_map},
	{"simply linked lists", "sll", tests_linked_list_all},
	{"doubly linked lists", "dll", tests_doubly_linked_list_all},
	{"circular linked lists", "cll", tests_circular_linked_list_all},
	{"optional", "opt", tests_optional},
	{"arguments", "arg", tests_args},
	{"math", "math", tests_math},
	{"pair", "pair", tests_pair},
	{NULL, NULL, NULL}
	};

	return (tests);
}

#if defined(true_random)
# if defined(__linux__)
#  define SRAND_OK true
# else
#  define SRAND_OK false
# endif
#else
# define SRAND_OK false
#endif

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

static int	run_module(const t_module module)
{
	const char	*r_s[] = {" \033[32mOK\033[0m", " \033[31mKO\033[0m"};
	int			collect;

	collect = 0;
	ft_putstr_fd("\n\nTesting ", STDOUT_FILENO);
	ft_putendl_fd(module.full_name, STDOUT_FILENO);
	collect = module.test();
	ft_putstr_fd("\nModule:: ", STDOUT_FILENO);
	ft_putstr_fd(module.full_name, STDOUT_FILENO);
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
	const t_module	*tests = get_tests();

	i = 0;
	collect = 0;
	setup(av);
	if (ac > 1 && !ft_strcmp(av[1], "-h"))
		return (print_help_tests(tests), EXIT_SUCCESS);
	if (ac > 1 && !ft_strcmp(av[1], "all"))
		av[1] = NULL;
	while (tests[i].full_name)
	{
		if (ac < 2 || (!ft_strcmp(av[1], tests[i].short_name) || \
!ft_strcmp(av[1], tests[i].full_name)))
			collect += run_module(tests[i]);
		i++;
	}
	if (collect == 0)
		return (ft_putendl_fd("\033[32mAll tests passed\033[0m",
				STDOUT_FILENO), EXIT_SUCCESS);
	return (ft_putendl_fd("\033[31mSome tests failed\033[0m", STDOUT_FILENO),
		EXIT_FAILURE);
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
