/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_filter.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:20:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"

#include "tests/tests_lambda_functions.h"
#include "tests/vector_tests.h"
#include "types/ft_vector_types.h"

static int	edge(void)
{
	const int	arr[] = {42, 42, 42};
	t_vector	*vec;

	vec = ft_vec_from_array(arr, 3, sizeof(int));
	if (vec->n_e != 3)
		return (1);
	ft_vec_filter(vec, is42, NULL);
	ft_vec_filter(NULL, is42, NULL);
	ft_vec_filter(vec, NULL, NULL);
	if (vec->n_e != 3)
		return (2);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

static int	base_case(void)
{
	const int	src_arr[10] = {0, 42, 21, 42, 63, 42, 84, 42, 105, 126};
	const int	arr[3] = {21, 42, 63};
	t_vector	*vec;
	int			*pp;

	vec = ft_vec_from_array(arr, 3, sizeof(int));
	ft_vec_filter(vec, is42, NULL);
	if (vec->n_e != 1 || *(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	ft_vec_destroy(&vec);
	pp = ft_calloc(sizeof(int), 10);
	ft_memcpy(pp, src_arr, sizeof(src_arr));
	vec = ft_vec_convert_alloccarray(pp, 10, sizeof(int));
	ft_vec_filter(vec, is42, NULL);
	if (vec->n_e != 4)
		return (2);
	vec->s_e = 0;
	ft_vec_filter(vec, is42, NULL);
	vec->s_e = sizeof(int);
	vec->n_e = 0;
	ft_vec_filter(vec, is42, NULL);
	return (ft_vec_destroy(&vec), 0);
}

int	tv_filter(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = edge();
	if (ret)
		return (ret);
	return (EXIT_SUCCESS);
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
