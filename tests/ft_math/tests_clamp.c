/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clamp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:46:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "tests/tests__all_modules_tests.h"

int	mt_clamp(void)
{
	const int	max = 42;
	const int	min = 21;
	int			x;

	x = 0;
	if (ft_clamp(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp(x, min, max) != x)
		return (1);
	return (0);
}

int	mt_clamp_f(void)
{
	const float	max = 42.0;
	const float	min = 21.0;
	float		x;

	x = 0;
	if (ft_clamp_f(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp_f(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp_f(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp_f(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp_f(x, min, max) != x)
		return (1);
	return (0);
}

int	mt_clamp_d(void)
{
	const double	max = 42.0;
	const double	min = 21.0;
	double			x;

	x = 0;
	if (ft_clamp_d(x, min, max) != min)
		return (1);
	x = 21;
	if (ft_clamp_d(x, min, max) != min)
		return (1);
	x = 42;
	if (ft_clamp_d(x, min, max) != max)
		return (1);
	x = 84;
	if (ft_clamp_d(x, min, max) != max)
		return (1);
	x = 23;
	if (ft_clamp_d(x, min, max) != x)
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
