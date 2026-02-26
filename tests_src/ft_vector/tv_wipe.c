/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_wipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 09:38:06 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 09:38:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

int	tv_wipe(void)
{
	t_vector	v;
	void		*data;

	if (ft_vec_wipe(NULL) != false)
		return (1);
	data = ft_malloc(12);
	v = (t_vector){.n_e = 3, .cappacity = 3, .s_e = sizeof(int), .data = NULL};
	if (ft_vec_wipe(&v) != true)
		return (2);
	if (v.s_e != sizeof(int) || v.n_e != 0 || v.cappacity != 0
		|| v.data != NULL)
		return (3);
	v = (t_vector){.n_e = 3, .cappacity = 3, .s_e = sizeof(int), .data = data};
	if (ft_vec_wipe(&v) != true)
		return (4);
	if (v.s_e != sizeof(int) || v.n_e != 0 || v.cappacity != 0
		|| v.data != NULL)
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
