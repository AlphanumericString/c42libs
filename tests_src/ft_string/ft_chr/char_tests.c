/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 14:31:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 22:41:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/str__char_tests.h"
#include "tests/tests.h"

static const t_fnamed	*tc_tests(void)
{
	static const t_fnamed	tests[] = {
	{"isalnum", tc_isalnum}, {"isalpha", tc_isalpha},
	{"isascii", tc_isascii}, {"isdigit", tc_isdigit},
	{"isprint", tc_isprint}, {"tolower", tc_tolower},
	{"toupper", tc_toupper}, {"isalnum", tc_isalnum},
	{"ishexdigit", tc_ishexdigit},
	{"isoctdigit", tc_isoctdigit}, {"isspace", tc_isspace},
	{NULL, NULL}};

	return (tests);
}

t_module	*char_tests(void)
{
	int				i;
	const t_fnamed	*funcs = tc_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "memory", "memory manipulation functions module.");
	while (funcs[i].name)
	{
		add_test_f(args, funcs[i].test, funcs[i].name);
		i++;
	}
	return (args);
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
