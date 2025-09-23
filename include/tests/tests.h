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

# include "./testing_lib/include/tests_fxtr.h"
# include <stdbool.h>
# include <stddef.h>

# define TEST_NOT_IMPLEMENTED EXIT_FAILURE

# if defined(__linux__)
#  define SRAND_OK true
# else
#  define SRAND_OK false
# endif

typedef struct s_fnamed
{
	const char	*name;
	int			(*test)(void);
}				t_fnamed;

typedef t_module *(*	t_mod_constructor)(void);

// hook for modules tests
t_module		*tests_args(void);
t_module		*tests_bitset(void);
t_module		*tests_lists(void);
t_module		*tests_map(void);
t_module		*tests_math(void);
t_module		*tests_optional(void);
t_module		*tests_pair(void);
t_module		*tests_string(void);
t_module		*tests_vector(void);

// sub modules tests
// - string
t_module		*t_string_tests(void);
t_module		*mem_tests(void);
t_module		*str_tests(void);
t_module		*char_tests(void);
t_module		*put_tests(void);
t_module		*num_conv_tests(void);
// - lists
t_module		*tests_doubly_linked_list_all(void);
t_module		*tests_linked_list_all(void);
t_module		*tests_circular_linked_list_all(void);

// - string/mem
t_module		*arr_module_tests(void);
t_module		*allocator_module_tests(void);
t_module		*arena_module_tests(void);
t_module		*algorithms_module_tests(void);

// - string/str/stris
t_module		*stris_tests(void);

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
