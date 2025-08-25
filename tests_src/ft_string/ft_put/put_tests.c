/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 13:10:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:20:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/str__put_tests.h"

static const t_fnamed	*tsp_tests(void)
{
	static const t_fnamed	tests[] = {
	{"putnbr", tsp_putnbr}, {"putnbr_base", tsp_putnbr_base},
	{"putunbr_base", tsp_putunbr_base},
	{"putdbl_fd", tsp_putdbl_fd},
	{"putstr", tsp_putstr}, {"putendl", tsp_putendl},
	{"putchar", tsp_putchar}, {"putnchar", tsp_putnchar},
	{"perror", tsp_perror},
	{"print_fd", tsp_printfd}, {"print", tsp_print},
	{"print_err", tsp_print_err}, {"va_print_fd", tsp_va_printfd},
	{NULL, NULL}};

	return (tests);
}

t_module	*put_tests(void)
{
	int				i;
	const t_fnamed	*funcs = tsp_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "put", "output pure strings functions module.");
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
