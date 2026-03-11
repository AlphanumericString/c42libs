/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nadd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 23:22:36 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 00:28:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"

static int	mt_cases(void)
{
	t_vector	v;
	bool		ret;
	const int	a_src[] = {42, 84, 126};
	const int	fp = *talloc_get_failpoint();

	ft_vec_ifrom_array(&v, a_src, 3, sizeof(int));
	if (v.n_e != 3)
		return (ft_vec_wipe(&v), 7);
	talloc_set_failpoint(0);
	ret = ft_vec_nadd(&v, v.cappacity, a_src);
	talloc_set_failpoint(fp);
	ft_vec_wipe(&v);
	if (ret != false)
		return (8);
	return (0);
}

int	tv_nadd(void)
{
	const int	a_src[] = {42, 84, 126};
	const int	b_src[] = {21, 42, 84};
	t_vector	bad_formed;
	t_vector	v;

	ft_vec_ifrom_array(&v, a_src, 3, sizeof(int));
	if (v.n_e != 3)
		return (ft_vec_wipe(&v), 1);
	if (ft_vec_nadd(&v, 2, b_src) != true || v.n_e != 5)
		return (ft_vec_wipe(&v), 2);
	if (ft_vec_nadd(&v, 2, b_src) != true || v.n_e != 7)
		return (ft_vec_wipe(&v), 2);
	if (ft_vec_nadd(&v, 0, b_src) != true || v.n_e != 7)
		return (ft_vec_wipe(&v), 3);
	if (ft_vec_nadd(&v, 9, NULL) == true
		|| ft_vec_nadd(NULL, 9, b_src) == true || v.n_e != 7)
		return (ft_vec_wipe(&v), 4);
	bad_formed = v;
	bad_formed.s_e = 0;
	if (ft_vec_nadd(&bad_formed, 2, b_src) == true)
		return (ft_vec_wipe(&v), 5);
	return (ft_vec_wipe(&v), mt_cases());
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
