/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:27:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests_lambda_functions.h"

int	test_vec_sort(void)
{
	t_vector	*vec;
	int			nbrs[3];

	nbrs[0] = 44;
	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)&nbrs[0]);
	nbrs[1] = 43;
	ft_vec_add(&vec, (void *)&nbrs[1]);
	nbrs[2] = 42;
	ft_vec_add(&vec, (void *)&nbrs[2]);
	ft_vec_sort(vec, cmp_int);
	if (vec->count != 3)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42)
		return (2);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (3);
	else if (*(int *)ft_vec_at(vec, 2) != 44)
		return (4);
	ft_vec_destroy(&vec);
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
