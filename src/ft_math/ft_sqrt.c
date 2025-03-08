/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 23:00:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:22:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// using newton's method
double	ft_sqrt(double nb)
{
	double	x;
	double	y;

	x = nb;
	if (nb <= 0)
		return (-1);
	y = 1;
	while (x - y > 0.0000001)
	{
		x = (x + y) / 2;
		y = nb / x;
	}
	return (x);
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
