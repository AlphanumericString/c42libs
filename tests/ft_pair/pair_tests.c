/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:53:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 13:56:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/pair_tests.h"
#include "tests/tests.h"

int	tests_pair(void)
{
	int				collect;
	const t_test	test[] = {
	{"tp_set", tp_set}, {"tp_new", tp_new},
	{"tp_first", tp_first}, {"tp_second", tp_second},
	{"tp_cmp", tp_cmp}, {"tp_cmp_first", tp_cmp_first},
	{"tp_cmp_second", tp_cmp_second},
	{"tp_destroy", tp_destroy}, {"tp_destroy", tp_destroy_sep},
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
