/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_intrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:41:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "tests/tests__all_modules_tests.h"

static int	tm_range_errors(void)
{
	const int	min = 9;
	const int	max = 42;
	const int	new_max = 21;
	int			x;

	x = -1;
	if (ft_range(x, min, max, new_max) != 0)
		return (1);
	x = min;
	if (ft_range(x, min + max, max, new_max) != 0)
		return (2);
	x = max + 1;
	if (ft_range(x, min, max, 0) != 0)
		return (3);
	return (0);
}

int	tm_range(void)
{
	const int	min = 9;
	const int	max = 42;
	const int	new_max = 21;
	int			x;

	x = -1;
	if (ft_range(x, min, max, new_max) != 0)
		return (1);
	x = min;
	if (ft_range(x, min, max, new_max) != 0)
		return (2);
	x = max + 1;
	if (ft_range(x, max, max, new_max) != 0)
		return (3);
	if (ft_range(x, min, max, new_max) != new_max)
		return (4);
	x = 42;
	if (ft_range(x, min, max, new_max) != new_max)
		return (5);
	x = 21;
	if (ft_range(x, min, max, new_max) != (int)(((double)(x - min) / \
(max - min)) * new_max))
		return (6);
	return (tm_range_errors());
}

int	tm_range_f(void)
{
	const float	min = 9.0f;
	const float	max = 42.0f;
	const float	new_max = 21.0f;
	float		x;

	x = -1;
	if (ft_range_f(x, min, max, new_max) != 0)
		return (1);
	x = min;
	if (ft_range_f(x, min, max, new_max) != 0)
		return (2);
	x = max + 1;
	if (ft_range_f(x, max, max, new_max) != 0)
		return (3);
	if (ft_range_f(x, min, max, new_max) != new_max)
		return (4);
	x = 42;
	if (ft_range_f(x, min, max, new_max) != new_max)
		return (5);
	x = 21;
	if (ft_range_f(x, min, max, new_max) != \
(float)(((double)(x - min) / (max - min)) * new_max))
		return (6);
	return (0);
}

static int	tm_range_d_errors(void)
{
	const double	min = 9.0;
	const double	max = 42.0;
	const double	new_max = 21.0;
	double			x;

	x = -1;
	if (ft_range_d(x, min, max, new_max) != 0)
		return (1);
	x = min;
	if (ft_range_d(x, min + max, max, new_max) != 0)
		return (2);
	x = max + 1;
	if (ft_range_d(x, min, max, 0) != 0)
		return (3);
	return (0);
}

int	tm_range_d(void)
{
	const double	min = 9.0;
	const double	max = 42.0;
	const double	new_max = 21.0;
	double			x;

	x = -1;
	if (ft_range_d(x, min, max, new_max) != 0)
		return (1);
	x = min;
	if (ft_range_d(x, min, max, new_max) != 0)
		return (2);
	x = max + 1;
	if (ft_range_d(x, max, max, new_max) != 0)
		return (3);
	if (ft_range_d(x, min, max, new_max) != new_max)
		return (4);
	x = 42;
	if (ft_range_d(x, min, max, new_max) != new_max)
		return (5);
	x = 21;
	if (ft_range_d(x, min, max, new_max) != ((x - min) / (max - min)) * new_max)
		return (6);
	return (tm_range_d_errors());
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
