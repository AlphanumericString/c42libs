/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 10:13:51 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/12 10:13:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"
#include "types/ft_vector_types.h"

static int	err_cases(void)
{
	t_vector	v;
	const int	a_src[] = {0, 1, 2, 3};

	ft_vec_nswap(NULL, 1, 0, -1);
	ft_vec_ifrom_array(&v, a_src, 4, sizeof(int));
	ft_vec_nswap(&v, 99, 0, -1);
	ft_vec_nswap(&v, 1, 12, -1);
	ft_vec_nswap(&v, 1, 0, -12);
	ft_vec_wipe(&v);
	v = (t_vector){.s_e = 1, .n_e = 0, .cappacity = 1, .data = (t_any)0xCAFE};
	ft_vec_nswap(&v, 1, 0, 1);
	v = (t_vector){.s_e = 0, .n_e = 2, .cappacity = 1, .data = (t_any)0xCAFE};
	ft_vec_nswap(&v, 1, 0, -1);
	v = (t_vector){.s_e = 1, .n_e = 2, .cappacity = 1, .data = NULL};
	ft_vec_nswap(&v, 0, 0, -1);
	return (0);
}

int	tv_nswap(void)
{
	t_vector	v;
	const int	a_src[] = {0, 1, 2, 3};
	const int	exp_1[] = {3, 1, 2, 0};

	ft_vec_ifrom_array(&v, a_src, 4, sizeof(int));
	ft_vec_nswap(&v, 1, 0, -1);
	if (ft_vec_acmp(&v, exp_1, ft_cmp_int_p))
		return (ft_vec_wipe(&v), 1);
	return (ft_vec_wipe(&v), err_cases());
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
