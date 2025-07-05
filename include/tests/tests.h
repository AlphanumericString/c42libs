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

# define TESTS_FPREFIX		"build/test_"
# define TESTS_FPREFIX_TMP	"/tmp/c42libs_test_"

# ifndef VERBOSE
#  define VERBOSE 0
# endif

# define TEST_NOT_IMPLEMENTED EXIT_FAILURE

# if defined(__linux__)
#  define SRAND_OK true
# else
#  define SRAND_OK false
# endif

# ifndef FORK_TESTS
#  define FORK_TESTS 1
# endif

typedef enum e_err_test_type
{
	TERR_CRASH = -1,
	TERR_OK = 0,
	TERR_ERR = 1,
}	t_err_test_type;

typedef union u_returns
{
	int	(*module_test)(int);
	int	(*tests_test)(void);
	struct
	{
		t_err_test_type	e_type;
		int				value;
	};
}	t_packed_returns;

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
}			t_module;

typedef int	(*t_function_test_runner)(t_test, int *, int, int);

// test main frame
int		run_module(const t_module module, int depth);
int		run_test(const t_test *test, int *collect, int depth);
int		open_test_file(char **func_to_test);
void	destroy_test_file(int fd, const char *file);

// memory alloc fail tests
/// set/get fail point + counter for allocs
int		*talloc_get_failpoint(void);
int		*talloc_get_currentpoint(void);
void	talloc_set_failpoint(int val);
void	talloc_set_currentpoint(int val);
bool	talloc_is_ok(void);
/// setup
void	*talloc_prev_group(void);
void	talloc_wrapper_setup(void);

void	*talloc_alloc(size_t s);
void	*talloc_calloc(size_t a, size_t b);
void	*talloc_realloc(void *p, size_t s);
void	talloc_free(void *p);
void	*talloc_reallocarray(void *p, size_t a, size_t b);
/// memory fail end

// hook for modules tests
int		tests_args(int d);
// int		tests_arena(int d);
// int		tests_array(int d);
int		tests_bitset(int d);
int		tests_lists(int d);
int		tests_map(int d);
int		tests_math(int d);
int		tests_optional(int d);
int		tests_pair(int d);
int		tests_string(int d);
int		tests_vector(int d);

// sub modules tests
// - string
int		t_string_tests(int d);
int		mem_tests(int d);
int		str_tests(int d);
int		char_tests(int d);
// - lists
int		tests_doubly_linked_list_all(int d);
int		tests_linked_list_all(int d);
int		tests_circular_linked_list_all(int d);

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
