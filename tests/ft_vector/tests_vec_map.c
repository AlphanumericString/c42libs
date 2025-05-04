/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 14:22:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests__all_modules_tests.h"

#include "tests/tests.h"
#include "tests/tests_lambda_functions.h"

#include <stdlib.h>

static int	base_case(void)
{
	t_vector	*vec;
	t_vector	*ret;
	int			**arr;

	arr = (int **)creat_tb();
	vec = ft_vec_from_array((void **)arr, 3);
	ret = ft_vec_map(vec, add42_ret);
	if (ret->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(ret, 0) != 84 || *(int *)ft_vec_at(ret, 1) != 85
		|| *(int *)ft_vec_at(ret, 2) != 86)
		return (2);
	ft_vec_apply(ret, ft_free);
	ft_vec_destroy(&vec);
	ft_vec_destroy(&ret);
	return (0);
}

static int	merror_case(void)
{
	t_vector	*vec;
	t_vector	*ret;
	int			**ar;
	int			f_point;

	ar = (int **)creat_tb();
	vec = ft_vec_from_array((void **)ar, 3);
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ret = ft_vec_map(vec, add42_ret);
	talloc_set_failpoint(f_point);
	if (ret)
		return (1);
	return (ft_vec_destroy(&vec), 0);
}

int	test_vec_map(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = merror_case();
	if (ret)
		return (ret + 10);
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
