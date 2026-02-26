/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nset.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:23:32 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 09:23:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/vector_tests.h"

int	tv_nset(void)
{
	t_vector	v;
	const int	arr[] = {1, 2, 3};
	const int	new_vals[] = {999, 998};

	ft_vec_ifrom_array(&v, arr, 3, sizeof(arr[0]));
	if (ft_vec_nset(&v, 99, 2, NULL) != false)
		return (1);
	if (ft_vec_nset(NULL, 1, 2, (void *)0xDEAD) != false)
		return (2);
	if (ft_vec_nset(&v, 2, 2, new_vals) != false)
		return (3);
	if (ft_vec_nset(&v, 1, 2, new_vals) != true)
		return (4);
	if (((int *)v.data)[1] != new_vals[0] || ((int *)v.data)[2] != new_vals[1])
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
