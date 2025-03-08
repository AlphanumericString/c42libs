/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intrange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 16:22:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:24:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	ft_range(int x, int min, int max, int new_max)
{
	int	res;

	if (max == min || new_max == 0 || min >= max)
		return (0);
	if (x <= min)
		return (0);
	if (x >= max)
		return (new_max);
	res = x - min;
	max -= min;
	return ((int)(((double)res / max) * new_max));
}

float	ft_range_f(float x, float min, float max, float new_max)
{
	return ((float)ft_range_d((double)x, (double)min, (double)max, \
	(double)new_max));
}

double	ft_range_d(double x, double min, double max, double new_max)
{
	double	res;

	if (max == min || new_max == 0 || min >= max)
		return (0);
	if (x <= min)
		return (0);
	if (x >= max)
		return (new_max);
	res = x - min;
	max -= min;
	return ((res / max) * new_max);
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
