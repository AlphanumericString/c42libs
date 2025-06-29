/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:42:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "tests/tests__all_modules_tests.h"

int	tm_log(void)
{
	int	x;

	x = 23;
	if (ft_log(x) != 1)
		return (1);
	x = 0;
	if (ft_log(x) != -1)
		return (2);
	x = 1;
	if (ft_log(x) != 0)
		return (3);
	x = 420;
	if (ft_log(x) != 2)
		return (4);
	x = -12;
	if (ft_log(x) != -1)
		return (5);
	return (0);
}

int	tm_llogof(void)
{
	if (ft_llogof(0, 2) != -1)
		return (1);
	if (ft_llogof(1, 2) != 0)
		return (2);
	if (ft_llogof(2, 2) != 1)
		return (3);
	if (ft_llogof(8, 2) != 3)
		return (4);
	if (ft_llogof(23, 3) != 2)
		return (5);
	return (0);
}

int	tm_ullogof(void)
{
	if (ft_ullogof(0, 2) != -1)
		return (1);
	if (ft_ullogof(1, 2) != 0)
		return (2);
	if (ft_ullogof(2, 2) != 1)
		return (3);
	return (0);
}

int	tm_logof(void)
{
	if (ft_logof(0, 2) != -1)
		return (1);
	if (ft_logof(1, 2) != 0)
		return (2);
	if (ft_logof(2, 2) != 1)
		return (3);
	if (ft_logof(8, 2) != 3)
		return (4);
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
