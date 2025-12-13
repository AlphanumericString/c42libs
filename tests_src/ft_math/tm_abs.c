/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:20:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:59:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "tests/math_tests.h"
#include <sys/types.h>
#include <stdlib.h>

int	tm_abs_l(void)
{
	long	x;

	x = -42;
	if (ft_abs_l(x) != 42)
		return (1);
	x = 42;
	if (ft_abs_l(x) != 42)
		return (2);
	x = 0;
	if (ft_abs_l(x) != 0)
		return (3);
	return (EXIT_SUCCESS);
}

int	tm_abs_ssize(void)
{
	ssize_t	x;

	x = -42;
	if (ft_abs_ssize_t(x) != 42)
		return (1);
	x = 42;
	if (ft_abs_ssize_t(x) != 42)
		return (2);
	x = 0;
	if (ft_abs_ssize_t(x) != 0)
		return (3);
	return (EXIT_SUCCESS);
}

int	tm_abs(void)
{
	int	x;

	x = -42;
	if (ft_abs(x) != 42)
		return (1);
	x = 42;
	if (ft_abs(x) != 42)
		return (2);
	x = 0;
	if (ft_abs(x) != 0)
		return (3);
	return (EXIT_SUCCESS);
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
