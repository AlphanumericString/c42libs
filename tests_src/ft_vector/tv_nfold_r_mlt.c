/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nfold_r.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 11:16:09 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 11:16:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/vector_tests.h"
#include "ft_vector.h"

static void	*add_ints(void *a, void *b)
{
	static int	res = 0;

	res = *(int *)a + *(int *)b;
	return (&res);
}

static int	e_cases(void)
{
	const int	asrc[] = {1, 2, 3, 4, 5, 6, 7};
	t_vector	v;

	ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
	ft_vec_nfold_r_mltp(&v, 0, add_ints, 42);
	ft_vec_nfold_r_mltp(&v, 42, add_ints, 0);
	ft_vec_nfold_r_mltp(NULL, 42, add_ints, 42);
	ft_vec_nfold_r_mltp(&v, 42, NULL, 42);
	ft_vec_wipe(&v);
	return (0);
}

__attribute_maybe_unused__	static int	b_cases(void)
{
	const int	asrc[] = {1, 2, 3, 4, 5, 6, 7};
	t_vector	v;
	int			g;

	ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
	ft_vec_nfold_r_mltp(&v, -1, add_ints, -1);
	if (ft_vec_get(&v, 0, &g) != &g || g != 28)
		return (ft_vec_wipe(&v), 1);
	ft_vec_wipe(&v);
	ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
	ft_vec_nfold_r_mltp(&v, 3, add_ints, 1);
	if (v.n_e != 7 - (3 / 2))
		return (ft_vec_wipe(&v), 2);
	ft_vec_wipe(&v);
	ft_vec_ifrom_array(&v, asrc, 7, sizeof(int));
	ft_vec_nfold_r_mltp(&v, 4, add_ints, -1);
	if (ft_vec_get(&v, 0, &g) != &g || g != 10)
		return (ft_vec_wipe(&v), 3);
	return (ft_vec_wipe(&v), 0);
}

int	tv_nfold_r_mltp(void)
{
	int	r;

	r = e_cases();
	if (r)
		return (r);
	r = b_cases();
	if (r)
		return (r);
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
