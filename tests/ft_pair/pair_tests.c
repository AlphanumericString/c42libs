/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 15:53:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:41:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/pair_tests.h"
#include "tests/tests.h"

int	tests_pair(void)
{
	int				collect;
	const t_test	test[] = {
	{"test_pair_set", test_pair_set},
	{"test_pair_new", test_pair_new},
	{"test_pair_second", test_pair_second},
	{"test_pair_first", test_pair_first},
	{"test_pair_cmp", test_pair_cmp},
	{"test_pair_cmp_first", test_pair_cmp_first},
	{"test_pair_cmp_second", test_pair_cmp_second},
	{"tests_pair_destroy", tests_pair_destroy},
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
