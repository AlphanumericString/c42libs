/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 20:33:46 by iron              #+#    #+#             */
/*   Updated: 2025/09/29 11:29:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_args.h"
#include "tests_fxtr.h"
#include "tests/fixtures.h"
#include "tests/tests.h"

#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

static t_mod_constructor	*get_tests(void)
{
	static t_mod_constructor	tests[] = {
		tests_vector,
		tests_lists, tests_string, tests_map, tests_optional,
		tests_args, tests_math, tests_pair, tests_bitset,
		NULL};

	return (tests);
}

// setup stuff for tests
//	printf("seed used for tests: %u\n", seed);
static void	setup(const char *av[])
{
	const unsigned int	seed = time(NULL);

	(void)av;
	srand(seed);
	ft_set_gnu_alloc();
	talloc_wrapper_setup();
	talloc_set_failpoint(INT_MAX);
	talloc_set_currentpoint(0);
}

//we only use putstr_fd and putendl_fd to avoid any error in the test
//	infrastructure itself
// by default, run all tests
// otherwise, run the tests for the module passed as argument
int	main(int ac, const char *av[])
{
	size_t				i;
	t_module			*root;
	t_mod_constructor	*sbm;

	(void)ac;
	root = ft_calloc(sizeof(*root), 1);
	init_module(root, "ft", "root");
	sbm = get_tests();
	i = 0;
	while (sbm[i])
		add_submodule(root, sbm[i++]());
	setup(av);
	sort_recursive(root);
	run_module(root);
	display_results(root, ONELINE | TM_PRINT_LAST
		| TM_SBM_SPLIT | TESTS_FULLNAME);
	module_destroy(root);
	return (EXIT_SUCCESS);
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
