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

/*
 * todos:
 * moar tests for parse_args

 * list sorted:

{"ac", targ_ac},
{"arg_printopts", targ_printopts},
{"av", targ_av},
{"consume_args", targ_consume_args_test},
{"custom checker", targ_custom_checker_test},
{"disp loaded", targ_disploaded},
{"ev_from_acav", targ_ev_from_acav},
{"ev", targ_ev},
{"getenv", targ_getenvp},
{"opt_list", targ_opt_list_test},
{"parse_args", targ_parse},
{"parser_perror", targ_perror_pa_state},
{"prog_name", targ_program_name_test},
{"put_type", targ_puttype_fd},
{"setup_prog", targ_setup_prog},
{"shift_args", targ_shift_args},
{"version", targ_version_test},

*/

static const t_fnamed	*targ_tests(void)
{
	static const t_fnamed	var[] = {
	{"ac", targ_ac}, {"arg_printopts", targ_printopts}, {"av", targ_av},
	{"consume_args", targ_consume_args_test},
	{"custom checker", targ_custom_checker_test},
	{"disp loaded", targ_disploaded}, {"ev_from_acav", targ_ev_from_acav},
	{"ev", targ_ev}, {"getenv", targ_getenvp},
	{"opt_list", targ_opt_list_test}, {"parse_args", targ_parse},
	{"parser_perror", targ_perror_pa_state},
	{"prog_name", targ_program_name_test}, {"put_type", targ_puttype_fd},
	{"setup_prog", targ_setup_prog}, {"shift_args", targ_shift_args},
	{"version", targ_version_test}, {NULL, NULL}};

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
