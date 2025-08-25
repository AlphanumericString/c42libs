/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stris_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:00:10 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:00:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/str__str_sis_tests.h"
#include "tests/tests.h"

static const t_fnamed	*tsi_tests(void)
{
	static const t_fnamed	tests[] = {
	{"isalpha", tsi_isalpha},
	{"isbool", tsi_isbool}, {"alnum", tsi_isalnum},
	{"isdigit", tsi_isdigit}, {"isdouble", tsi_isdouble},
	{"ishex", tsi_ishex}, {"islong", tsi_islong},
	{"isnum", tsi_isnum}, {"isoct", tsi_isoct},
	{"ispath", tsi_ispath},
	{"isint", tsi_isint}, {"isfloat", tsi_isfloat},
	{"isfname", tsi_isfname},
	{"isvalid", tsi_isvalid}, {NULL, NULL}};

	return (tests);
}

t_module	*stris_tests(void)
{
	int				i;
	const t_fnamed	*funcs = tsi_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "stris", "query functions for c-strings.");
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
