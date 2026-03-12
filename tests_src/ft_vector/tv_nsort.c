/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 12:12:30 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/12 12:12:30 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

// static void	dump(void *a)
// {
// 	printf("%d\n", *(int*)a);
// }
//
static int	err_cases(void)
{
	ft_vec_nsort(NULL, 2, ft_cmp_int_p);
	return (0);
}

int	tv_nsort(void)
{
	t_vector	v;
	const int	a_src[] = {268, 192, 37};
	const int	exp[][3] = {{192, 268, 37}, {37, 192, 268}};

	ft_vec_ifrom_array(&v, a_src, 3, sizeof(int));
	ft_vec_nsort(&v, 2, ft_cmp_int_p);
	if (ft_vec_acmp(&v, exp[0], ft_cmp_int_p))
		return (ft_vec_wipe(&v), 1);
	ft_vec_nsort(&v, 3, ft_cmp_int_p);
	if (ft_vec_acmp(&v, exp[1], ft_cmp_int_p))
		return (ft_vec_wipe(&v), 2);
	ft_vec_wipe(&v);
	ft_vec_ifrom_array(&v, a_src, 3, sizeof(int));
	ft_vec_nsort(&v, -1, ft_cmp_int_p);
	if (ft_vec_acmp(&v, exp[1], ft_cmp_int_p))
		return (ft_vec_wipe(&v), 3);
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
