/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_tests.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:16:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:40:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"
#include "tests/math_tests.h"

int	tests_math(void)
{
	int				i;
	const t_test	tests[] = {
	{"abs", test_ft_abs}, {"clamp", test_ft_clamp},
	{"complex_abs", test_ft_complex_abs},
	{"complex_addl", test_ft_complex_addl},
	{"complex_mull", test_ft_complex_mull},
	{"complex_muld", test_ft_complex_muld},
	{"range", test_ft_range}, {"range_f", test_ft_range_f},
	{"range_d", test_ft_range_d}, {"log", test_ft_log},
	{"llogof", test_ft_llogof}, {"ullogof", test_ft_ullogof},
	{"logof", test_ft_logof}, {"min", test_ft_min},
	{"max", test_ft_max}, {"pow", test_ft_pow}, {"round", test_ft_round},
	{"sqrt", test_ft_sqrt}, {"clamp_f", test_ft_clamp_f},
	{"clamp_d", test_ft_clamp_d}, {"align", test_ft_align},
	{"align_2", test_ft_align_2}, {NULL, NULL}};

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
