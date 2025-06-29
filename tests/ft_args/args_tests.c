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

#include "tests/tests.h"
#include "tests/args_tests.h"

int	parse_args_test(void)
{
	return (0);
}

static const t_test	*init_tests(void)
{
	static const t_test	var[] = {
	{"ac", targ_ac}, {"av", targ_av}, {"ev", targ_ev}, {"getenv", targ_getenvp},
	{"setup_prog", targ_setup_prog}, {"version", targ_version_test},
	{"prog_name", targ_program_name_test}, {"opt_list", targ_opt_list_test},
	{"custom checker", targ_custom_checker_test},
	{"consume_args", targ_consume_args_test}, {"shift_args", targ_shift_args},
	{"parse_args", targ_parse}, {NULL, NULL}};

	return (var);
}

int	tests_args(void)
{
	int				collect;
	const t_test	*test = init_tests();

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
