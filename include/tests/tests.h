/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 11:15:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/21 17:48:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

# include <stdbool.h>
# include <stddef.h>

# define TEST_NOT_IMPLEMENTED EXIT_FAILURE

# if defined(__linux__)
#  define SRAND_OK true
# else
#  define SRAND_OK false
# endif

# ifndef FORK_TESTS
#  define FORK_TESTS 1
# endif

typedef enum verbosity
{
	VER_TESTS = 0,
	VER_MODULES = 1,
	VER_SUB_MODULES = 2,
	VER_ALL = 3,
	VER_QUIET = 4,
}	t_verbosity;

# ifndef VERBOSE
#  define VERBOSE VER_ALL
# endif

//
// typedef enum e_err_test_type
// {
// 	TERR_CRASH = -1,
// 	TERR_OK = 0,
// 	TERR_ERR = 1,
// }	t_err_test_type;

typedef struct s_test
{
	char	*name;
	int		(*test)(void);
}			t_test;

typedef struct s_module
{
	char	*full_name;
	char	*short_name;
	int		(*test)(int);
	int		res;
}			t_module;

typedef int	(*t_function_test_runner)(t_test, int *, int, int);

// test main frame
int			run_module(t_module module, int depth);
int			run_test(const t_test *test, int *collect, int depth);

// verbosity control of tests
t_verbosity	tverbose(void);
void		tverbose_set(t_verbosity verbose);

// hook for modules tests
int			tests_args(int d);
int			tests_bitset(int d);
int			tests_lists(int d);
int			tests_map(int d);
int			tests_math(int d);
int			tests_optional(int d);
int			tests_pair(int d);
int			tests_string(int d);
int			tests_vector(int d);

// sub modules tests
// - string
int			t_string_tests(int d);
int			mem_tests(int d);
int			str_tests(int d);
int			char_tests(int d);
int			put_tests(int d);
int			num_conv_tests(int d);
// - lists
int			tests_doubly_linked_list_all(int d);
int			tests_linked_list_all(int d);
int			tests_circular_linked_list_all(int d);

// - string/mem
int			arr_module_tests(int depth);
int			allocator_module_tests(int depth);
int			arena_module_tests(int depth);

// - string/str/stris
int			stris_tests(int depth);

// to see utils and such see : test_lambda_functions.h

#endif /* TESTS_H */
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
