/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 17:02:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:38:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/args_tests.h"

int	parse_args_test(void)
{
	return (0);
}

int	tests_args(void)
{
	int				collect;
	const t_test	test[] = {
	{"getset_version", getset_version_test}, {"getset_progname", \
		getset_program_name_test}, {"getset_opt_list", getset_opt_list_test},
	{"parse_args", parse_args_test}, {"setup_prog", tests_setup_prog},
	{"getset_custom_parser", getset_custom_checker_test}, {NULL, NULL}};

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
