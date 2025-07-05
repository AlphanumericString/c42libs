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

#include "tests/str__str_sis_tests.h"
#include "tests/tests.h"

int	stris_tests(int depth)
{
	int				collect;
	const t_test	tests[] = {
	{"isalpha", tsi_isalpha},
	{"isbool", tsi_isbool}, {"alnum", tsi_isalnum},
	{"isdigit", tsi_isdigit}, {"isdouble", tsi_isdouble},
	{"ishex", tsi_ishex}, {"islong", tsi_islong},
	{"isnum", tsi_isnum}, {"isoct", tsi_isoct},
	{"isint", tsi_isint}, {"isfloat", tsi_isfloat},
	{"isvalid", tsi_isvalid}, {NULL, NULL}};

	collect = 0;
	run_test(tests, &collect, depth);
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
