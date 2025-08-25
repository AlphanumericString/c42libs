/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:27:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_defs.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"
#include "tests/tests_lambda_functions.h"

static int	cmp_ptr(const void *a, const void *b)
{
	return (a - b);
}

static int	base_cases(void)
{
	t_vector	*vec;
	const long	nbrs[3] = {44, 43, 42};

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)nbrs[0]);
	ft_vec_add(&vec, (void *)nbrs[1]);
	ft_vec_add(&vec, (void *)nbrs[2]);
	ft_vec_sort(vec, cmp_ptr);
	if (vec->count != 3)
		return (1);
	else if (ft_vec_at(vec, 0) != (t_any)42
		|| ft_vec_at(vec, 1) != (t_any)43
		|| ft_vec_at(vec, 2) != (t_any)44)
		return (2);
	ft_vec_sort(vec, cmp_ptr);
	if (ft_vec_at(vec, 0) != (t_any)42
		|| ft_vec_at(vec, 1) != (t_any)43
		|| ft_vec_at(vec, 2) != (t_any)44)
		return (3);
	ft_vec_destroy(&vec);
	return (0);
}

int	tv_sort(void)
{
	int	ret;

	ret = base_cases();
	if (ret)
		return (ret);
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
