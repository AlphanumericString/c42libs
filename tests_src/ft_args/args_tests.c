/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:02:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 15:44:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/args_tests.h"

static const t_fnamed	*targ_tests(void)
{
	static const t_fnamed	var[] = {
	{"ac", targ_ac}, {"av", targ_av}, {"ev", targ_ev},
	{"ev_from_acav", targ_ev_from_acav}, {"getenv", targ_getenvp},
	{"setup_prog", targ_setup_prog}, {"version", targ_version_test},
	{"prog_name", targ_program_name_test}, {"opt_list", targ_opt_list_test},
	{"custom checker", targ_custom_checker_test},
	{"consume_args", targ_consume_args_test}, {"shift_args", targ_shift_args},
	{"arg_printopts", targ_printopts}, {"parser_perror", targ_perror_pa_state},
	{"put_type", targ_puttype_fd}, {"parse_args", targ_parse},
	{"disp loaded", targ_disploaded},
	{NULL, NULL}};

	return (var);
}

t_module	*tests_args(void)
{
	int				i;
	const t_fnamed	*funcs = targ_tests();
	t_module		*args;

	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "args", "argument handling module [ev, av, parsing ...]");
	i = 0;
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
