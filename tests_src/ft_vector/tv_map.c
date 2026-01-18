/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

#include "tests/fixtures.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

static int	error_case(void)
{
	t_vector	*vec;
	int			arr[3] = {42, 43, 44};

	vec = ft_vec_from_array(arr, 3, sizeof(int));
	if (ft_vec_map(NULL, add42) != NULL)
		return (1);
	if (ft_vec_map(vec, NULL) != NULL)
		return (2);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);

}
static int	base_case(void)
{
	t_vector	hold;
	t_vector	*vec;
	t_vector	*ret;
	int			arr[3] = {42, 43, 44};

	vec = ft_vec_from_array(arr, 3, sizeof(int));
	ret = ft_vec_map(vec, add42);
	if (ret->n_e != 3)
		return (1);
	else if (*(int *)ft_vec_at(ret, 0) != 84 || *(int *)ft_vec_at(ret, 1) != 85
		|| *(int *)ft_vec_at(ret, 2) != 86)
		return (ft_vec_destroy(&vec), ft_vec_destroy(&ret), 2);
	ft_vec_destroy(&ret);
	hold = *vec;
	vec->s_e = 0;
	if (ft_vec_map(vec, add42) != NULL)
		return (3);
	ft_memcpy(vec, &hold, sizeof(t_vector));
	vec->n_e = 0;
	if (ft_vec_map(vec, add42) != NULL)
		return (4);
	ft_memcpy(vec, &hold, sizeof(t_vector));
	vec->data = NULL;
	if (ft_vec_map(vec, add42) != NULL)
		return (5);
	return (ft_vec_destroy(&vec), ft_vec_destroy(&ret), EXIT_SUCCESS);
}

static int	mt_case(void)
{
	t_vector	*vec;
	t_vector	*ret;
	int			ar[3] = {42, 43, 44};
	int			f_point;

	vec = ft_vec_from_array(ar, 3, sizeof(int *));
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ret = ft_vec_map(vec, add42);
	talloc_set_failpoint(f_point);
	if (ret)
		return (ft_vec_destroy(&vec), ft_vec_destroy(&ret), 1 + 8);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	ret = ft_vec_map(vec, add42);
	talloc_set_failpoint(f_point);
	if (ret)
		return (ft_vec_destroy(&vec), ft_vec_destroy(&ret), 2 + 8);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

int	tv_map(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = mt_case();
	if (ret)
		return (ret);
	ret = error_case();
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
