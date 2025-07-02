/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:54:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 16:02:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cmp + _with

#include "ft_arr.h"

// if-elif tree at the end to casts as int otherwise some truncation could
//		invert signs
int	ft_acmp(t_const_arr a1, t_const_arr a2)
{
	size_t	i;

	if ((!a1 && !a2) || a1 == a2)
		return (0);
	if (!a1 || !a2)
		return (1 * (a2 == NULL) - 1 * (a1 == NULL));
	i = 0;
	while (a1[i] && a2[i])
	{
		if (a1[i] != a2[i])
			break ;
		i++;
	}
	if (a1[i] == a2[i])
		return (0);
	else if (a1[i] - a2[i] < 0)
		return (-1);
	return (1);
}

int	ft_acmp_with(t_const_arr a1, t_const_arr a2, t_data_cmp cmp)
{
	size_t	i;

	if (!a1 || !a2)
		return (1 * (a2 == NULL) - 1 * (a1 == NULL));
	if (!cmp)
		return (false);
	i = 0;
	while (a1[i] && a2[i])
	{
		if (cmp(a1[i], a2[i]))
			break ;
		i++;
	}
	if (a1[i] == a2[i])
		return (0);
	else if (a1[i] - a2[i] < 0)
		return (-1);
	return (1);
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
