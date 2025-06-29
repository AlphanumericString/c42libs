/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:16:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/02 14:57:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/math_tests.h"

int	tests_math(void)
{
	int				i;
	const t_test	tests[] = {
	{"abs", tm_abs}, {"abs_l", tm_abs_l}, {"abs_ssize", tm_abs_ssize},
	{"clamp", tm_clamp},
	{"complex_abs", tm_complex_abs},
	{"complex_addl", tm_complex_addl},
	{"complex_mull", tm_complex_mull},
	{"complex_muld", tm_complex_muld},
	{"range", tm_range}, {"range_f", tm_range_f},
	{"range_d", tm_range_d}, {"log", tm_log},
	{"llogof", tm_llogof}, {"ullogof", tm_ullogof},
	{"logof", tm_logof}, {"min", tm_min}, {"max", tm_max},
	{"nbrlen", tm_nbrlen}, {"unbrlen", tm_unbrlen_base},
	{"nbrlen_base", tm_nbrlen_base},
	{"powd", tm_powd}, {"pow", tm_pow}, {"round", tm_round},
	{"sqrt", tm_sqrt}, {"clamp_f", tm_clamp_f},
	{"clamp_d", tm_clamp_d}, {"align", tm_align},
	{"align_2", tm_align_2}, {"align_2_mul", tm_align_2_multiple},
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
