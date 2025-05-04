/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:16:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 13:49:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/math_tests.h"

int	tests_math(void)
{
	int				i;
	const t_test	tests[] = {
	{"abs", mt_abs}, {"abs_l", mt_abs_l}, {"abs_ssize", mt_abs_ssize},
	{"clamp", mt_clamp},
	{"complex_abs", mt_complex_abs},
	{"complex_addl", mt_complex_addl},
	{"complex_mull", mt_complex_mull},
	{"complex_muld", mt_complex_muld},
	{"range", mt_range}, {"range_f", mt_range_f},
	{"range_d", mt_range_d}, {"log", mt_log},
	{"llogof", mt_llogof}, {"ullogof", mt_ullogof},
	{"logof", mt_logof}, {"min", mt_min},
	{"max", mt_max}, {"pow", mt_pow}, {"round", mt_round},
	{"sqrt", mt_sqrt}, {"clamp_f", mt_clamp_f},
	{"clamp_d", mt_clamp_d}, {"align", mt_align},
	{"align_2", mt_align_2}, {"align_2_mul", mt_align_2_multiple},
	{NULL, NULL}};

	i = 0;
	run_test(tests, &i);
	return (i);
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
