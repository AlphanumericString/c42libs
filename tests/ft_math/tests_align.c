/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_align.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 19:53:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/13 18:12:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"

int	test_ft_align_2(void)
{
	size_t	nbr;

	nbr = 42;
	if (ft_align_2(nbr, 1) != nbr)
		return (1);
	if (ft_align_2(nbr, 8) != 48)
		return (2);
	if (ft_align_2(nbr, 16) != 48)
		return (3);
	nbr = 275;
	if (ft_align_2(nbr, 4) != 276)
		return (4);
	return (0);
}

int	test_ft_align(void)
{
	size_t	value;

	value = 42;
	if (ft_align(value, 1) != value)
		return (1);
	if (ft_align(value, 4) != 44)
		return (2);
	if (ft_align(value, 8) != 48)
		return (2);
	if (ft_align(value, 16) != 48)
		return (3);
	value = 275;
	if (ft_align(value, 6) != 276)
		return (4);
	if (ft_align(276, 6) != 276)
		return (5);
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
