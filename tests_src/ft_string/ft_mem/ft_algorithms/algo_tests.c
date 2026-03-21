/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:02:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 16:02:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "tests/tests.h"
#include "tests/str__mem_tests.h"

/*
 * sorted list:

{"bblsort", talg_bblsort},
{"binsrch", talg_binsrch},
{"cmps", talg_cmps},
{"getmax", talg_getmax},
{"getmin", talg_getmin},
{"isord_ok", talg_isord_ok},
{"isrtsort_b", talg_isrtsort_b},
{"isrtsort", talg_isrtsort},
{"is_sorted", talg_issorted},
{"mrgsort_r", talg_mrgsort_r},
{"mrgsort", talg_mrgsort},
{"qsort", talg_qsort},
{"rcmp", talg_rcmps},
{"sbblsort", talg_sbblsort},
{"sbcksort", talg_sbcksort},
{"shkrsort", talg_shkrsort},
{"sisrtsort", talg_sisrtsort},
{"slctsort", talg_slctsort},
{"ssbblsort", talg_ssbblsort},
{"ssisrtsort", talg_ssisrtsort},

*/

static const t_fnamed	*talg_tests(void)
{
	static const t_fnamed	tests[] = {
	{"bblsort", talg_bblsort}, {"binsrch", talg_binsrch}, {"cmps", talg_cmps},
	{"getmax", talg_getmax}, {"getmin", talg_getmin},
	{"isord_ok", talg_isord_ok}, {"isrtsort_b", talg_isrtsort_b},
	{"isrtsort", talg_isrtsort}, {"is_sorted", talg_issorted},
	{"mrgsort_r", talg_mrgsort_r}, {"mrgsort", talg_mrgsort},
	{"qsort", talg_qsort}, {"rcmp", talg_rcmps}, {"sbblsort", talg_sbblsort},
	{"sbcksort", talg_sbcksort}, {"shkrsort", talg_shkrsort},
	{"sisrtsort", talg_sisrtsort}, {"slctsort", talg_slctsort},
	{"ssbblsort", talg_ssbblsort}, {"ssisrtsort", talg_ssisrtsort},
	{NULL, NULL}};

	return (tests);
}

t_module	*algorithms_module_tests(void)
{
	const t_fnamed	*funcs = talg_tests();
	t_module		*algs;

	algs = ft_calloc(sizeof(*algs), 1);
	init_module(algs, "algorithms", "common algorithms module (sort|srch).");
	while (funcs->name)
	{
		add_test_f(algs, funcs->test, funcs->name);
		funcs++;
	}
	return (algs);
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
