/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:04:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 04:15:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

#include <stddef.h>

size_t	ft_pow(size_t x, size_t y)
{
	size_t	res;

	res = 1;
	if (y == 0)
		return (1);
	if (x == 0)
		return (0);
	while (y > 0)
	{
		res *= x;
		y--;
	}
	return (res);
}

double	ft_pow_d(double x, double y)
{
	double	res;

	res = 1.0;
	if (y == 0.0)
		return (1.0);
	if (x == 0.0)
		return (0.0);
	while (y > 0.0)
	{
		res *= x;
		y--;
	}
	return (res);
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
