/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_minmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:49:30 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "tests/tests__all_modules_tests.h"

int	tm_min(void)
{
	const int	a = 1;
	const int	b = 2;
	const int	c = 3;

	if (ft_min(a, b) != a)
		return (1);
	if (ft_min(b, c) != b)
		return (2);
	if (ft_min(c, a) != a)
		return (3);
	return (0);
}

int	tm_max(void)
{
	const int	a = 1;
	const int	b = 2;
	const int	c = 3;

	if (ft_max(a, b) != b)
		return (1);
	if (ft_max(c, b) != c)
		return (2);
	if (ft_max(c, a) != c)
		return (3);
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
