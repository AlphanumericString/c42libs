/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_insert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 06:25:01 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 01:39:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"
#include "ft_vector.h"

static int	mt_error(void)
{
	const int	fp = *talloc_get_failpoint();
	const int	to_insert = 666;
	bool		ret;
	t_vector	*vec;

	ret = EXIT_SUCCESS;
	vec = ft_vec_from_array((int []){1, 2, 3}, 3, sizeof(int));
	talloc_set_failpoint(0);
	ret = ft_vec_insert(vec, 1, &to_insert);
	talloc_set_failpoint(fp);
	if (ret != false)
		return (ft_vec_destroy(&vec), 24);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

static int	error_cases(void)
{
	t_vector	vec;

	vec = (t_vector){.cappacity = 1, .n_e = 1, .s_e = 1, .data = NULL};
	if (ft_vec_insert(NULL, 999, (void *) 0xDEAD) != false
		|| ft_vec_insert(&vec, 990, (void *)0xDEAD) != false)
		return (16);
	vec = (t_vector){.cappacity = 1, .n_e = 0, .s_e = 1, .data = (t_any)0xCAFE};
	if (ft_vec_insert(&vec, 990, (void *)0xDEAD) != false)
		return (17);
	vec = (t_vector){.cappacity = 1, .n_e = 1, .s_e = 0, .data = (t_any)0xCAFE};
	if (ft_vec_insert(&vec, 990, (void *)0xDEAD) != false)
		return (18);
	vec = (t_vector){.cappacity = 1, .n_e = 1, .s_e = 1, .data = (t_any)0xCAFE};
	if (ft_vec_insert(&vec, 990, NULL) != false)
		return (18);
	return (mt_error());
}

static int	tv_insert_grow(void)
{
	t_vector	*vec;
	int			*src_arr;
	bool		ret;
	int			to_insert;

	to_insert = 0;
	src_arr = ft_malloc(sizeof(int) * (FT_VECTOR_BASE_LEN - 1));
	while (to_insert < (FT_VECTOR_BASE_LEN - 1))
		src_arr[to_insert++] = 1412;
	vec = ft_vec_convert_alloccarray(src_arr, FT_VECTOR_BASE_LEN - 1,
			sizeof(int));
	if (vec->cappacity != FT_VECTOR_BASE_LEN - 1)
		return (8);
	to_insert = 666;
	ret = ft_vec_insert(vec, 2, &to_insert);
	if (ret != true || *((int *)ft_vec_at(vec, 2)) != 666)
		return (9);
	ft_vec_destroy(&vec);
	return (error_cases());
}

int	tv_insert(void)
{
	t_vector	*vec;
	const int	a[] = {42, 43, 45};
	int			b;
	bool		ret;

	b = 44;
	vec = ft_vec_from_array(a, 3, sizeof(int));
	ret = ft_vec_insert(vec, 2, &b);
	if (vec->n_e != 4 || ret != true)
		return (ft_vec_destroy(&vec), 1);
	if (*((int *)ft_vec_at(vec, 2)) != 44 || *((int *)ft_vec_at(vec, 3)) != 45)
		return (ft_vec_destroy(&vec), 2);
	ret = ft_vec_insert(vec, 2, &b);
	if (vec->n_e != 5 || ret != true)
		return (ft_vec_destroy(&vec), 3);
	if (*((int *)ft_vec_at(vec, 2)) != 44 || *((int *)ft_vec_at(vec, 3)) != 44)
		return (ft_vec_destroy(&vec), 4);
	b = 666;
	ret = ft_vec_insert(vec, 99, &b);
	if (vec->n_e != 6 || ret != true)
		return (ft_vec_destroy(&vec), 5);
	if (*((int *)ft_vec_at(vec, 5)) != 666 || *((int *)ft_vec_at(vec, 4)) != 45)
		return (ft_vec_destroy(&vec), 6);
	return (ft_vec_destroy(&vec), tv_insert_grow());
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
