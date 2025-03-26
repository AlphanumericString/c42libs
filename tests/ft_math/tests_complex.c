/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_complex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:46:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "ft_math_types.h"
#include "tests/tests__all_modules_tests.h"

int	test_ft_complex_abs(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	const t_complex	z = {42, 42};
	double			res;

	res = ft_complex_abs(x);
	if (res < 41.99 || res > 42.01)
		return (1);
	res = ft_complex_abs(y);
	if (res < 41.99 || res > 42.01)
		return (2);
	res = ft_complex_abs(z);
	if (res < 59.39 || res > 59.41)
		return (3);
	return (0);
}

int	test_ft_complex_addl(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	t_complex		res;

	res = ft_complex_addl(x, 42);
	if (res.real != 84 || res.imaginary != 42)
		return (1);
	res = ft_complex_addl(y, 42);
	if (res.real != 42 || res.imaginary != 84)
		return (1);
	return (0);
}

int	test_ft_complex_mull(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	t_complex		res;

	res = ft_complex_mull(x, 2);
	if (res.real != 84 || res.imaginary != 0)
		return (1);
	res = ft_complex_mull(y, 2);
	if (res.real != 0 || res.imaginary != 84)
		return (1);
	return (0);
}

int	test_ft_complex_muld(void)
{
	const t_complex	x = {42, 0};
	const t_complex	y = {0, 42};
	t_complex		res;

	res = ft_complex_muld(x, 2.5);
	if (res.real != 105 || res.imaginary != 0)
		return (1);
	res = ft_complex_muld(y, 2.5);
	if (res.real != 0 || res.imaginary != 105)
		return (1);
	return (0);
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
