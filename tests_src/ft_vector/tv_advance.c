/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_advance.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:33:35 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/08 22:33:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

int	tv_advance(void)
{
	t_vector	vec;
	bool		res[4];
	const bool	exp[4] = {true, false, false, true};

	ft_vec_ifrom_array(&vec, (int []){1, 2, 3}, 3, sizeof(int));
	if (vec.n_e != 3)
		return (ft_vec_wipe(&vec), 1);
	res[0] = ft_vec_advance(&vec, 1);
	if (vec.n_e != 2)
		return (ft_vec_wipe(&vec), 2);
	res[1] = ft_vec_advance((void *)0xDEAD, 0);
	res[2] = ft_vec_advance(NULL, 999);
	res[3] = ft_vec_advance(&vec, 999);
	if (vec.n_e)
		return (ft_vec_wipe(&vec), 3);
	if (ft_memcmp(res, exp, sizeof(bool) * 4) != 0)
		return (ft_vec_wipe(&vec), 4);
	return (ft_vec_wipe(&vec), 0);
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
