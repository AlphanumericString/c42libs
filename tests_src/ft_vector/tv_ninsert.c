/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_ninsert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 23:18:21 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 23:18:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"
#include <stdio.h>

static int	cmp_int_it(const void *a, const void *b)
{
	const int	*it_a = a;
	const int	*it_b = b;

	return (*it_a - *it_b);
}

static int	mt_cases(void)
{
	t_vector	v;
	const int	values[] = {42, 43, 44};
	const int	fp = *talloc_get_failpoint();
	int			ret;

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	ft_vec_shrink(&v);
	if (v.n_e != v.cappacity)
		return (ft_vec_wipe(&v), 20);
	ret = 0;
	talloc_set_failpoint(0);
	if (ft_vec_ninsert(&v, 1, 3, values) != false)
		ret = 1 + 20;
	talloc_set_failpoint(fp);
	return (ft_vec_wipe(&v), ret);
}

static int	bad_vec_cases(void)
{
	t_vector	vec;

	vec = (t_vector){.cappacity = 1, .n_e = 1, .s_e = 1, .data = NULL};
	if (ft_vec_ninsert(NULL, 999, 32, (void *) 0xDEAD) != false
		|| ft_vec_ninsert(&vec, 990, 32, (void *)0xDEAD) != false)
		return (16);
	vec = (t_vector){.cappacity = 1, .n_e = 0, .s_e = 1, .data = (t_any)0xCAFE};
	if (ft_vec_ninsert(&vec, 990, 32, (void *)0xDEAD) != false)
		return (17);
	vec = (t_vector){.cappacity = 1, .n_e = 1, .s_e = 0, .data = (t_any)0xCAFE};
	if (ft_vec_ninsert(&vec, 990, 32, (void *)0xDEAD) != false)
		return (18);
	return (mt_cases());
}

int	tv_ninsert(void)
{
	t_vector	v;
	const int	values[] = {42, 43, 44};
	const int	p2[] = {1, 2, 3, 42, 43};
	const int	p3[] = {1, 42, 43, 2, 3, 42, 43};
	const int	p4[] = {1, 42, 43, 2, 42, 43, 44, 3, 42, 43};

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	if (ft_vec_ninsert(NULL, 1, 1, values) != false
		|| ft_vec_ninsert(&v, 1, 1, NULL) != false)
		return (ft_vec_wipe(&v), 1);
	if (!ft_vec_ninsert(&v, 1, 0, values))
		return (ft_vec_wipe(&v), 2);
	if (!ft_vec_ninsert(&v, -1, 2, values) || v.n_e != 5
		|| ft_vec_ancmp(&v, 5, p2, cmp_int_it))
		return (ft_vec_wipe(&v), 3);
	if (!ft_vec_ninsert(&v, 1, 2, values) || v.n_e != 7
		|| ft_vec_ancmp(&v, 7, p3, cmp_int_it))
		return (ft_vec_wipe(&v), 4);
	ft_vec_reserve(&v, 15);
	if (!ft_vec_ninsert(&v, 4, 3, values) || v.n_e != 10
		|| ft_vec_ancmp(&v, 10, p4, cmp_int_it))
		return (ft_vec_wipe(&v), 5);
	return (ft_vec_wipe(&v), bad_vec_cases());
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
