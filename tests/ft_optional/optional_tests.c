/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optional_tests.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 00:57:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 14:52:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/optional_test.h"
#include "tests/tests.h"

void	*add_fail(void *val)
{
	(void)val;
	return (NULL);
}

void	*add_4(void *val)
{
	long long	ptr;

	ptr = (long long)val;
	ptr += 4;
	return ((void *)ptr);
}

int	tests_optional(void)
{
	int				collect;
	const t_test	test[] = {
	{"copy", test_optional_copy},
	{"new", test_optional_new},
	{"from_val", test_optional_from_val},
	{"dup", test_optional_dup},
	{"chain", test_optional_chain},
	{"map", test_optional_map},
	{"unwrap", test_optional_unwrap},
	{"destroy", test_optional_destroy},
	{NULL, NULL}
	};

	collect = 0;
	run_test(test, &collect);
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
