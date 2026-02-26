/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_set.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:48:15 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 08:48:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/vector_tests.h"
#include "types/ft_vector_types.h"

int	tv_set(void)
{
	t_vector	v;
	const int	arr[] = {1, 2, 3};
	const int	new_val = 999;

	v = (t_vector){.s_e = sizeof(int), .n_e = 3, .cappacity = 3,
		.data = (void *)0xDEAD};
	if (ft_vec_set(&v, 99, NULL) != false)
		return (1);
	if (ft_vec_set(NULL, 2, (void *)0xDEAD) != false)
		return (2);
	ft_vec_ifrom_array(&v, arr, 3, sizeof(int));
	if (ft_vec_set(&v, 1, &new_val) != true)
		return (ft_vec_wipe(&v), 3);
	if (((int *)v.data)[1] != new_val)
		return (ft_vec_wipe(&v), 4);
	return (ft_vec_wipe(&v), 0);
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
