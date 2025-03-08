/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:20:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	test_vec_filter(void)
{
	const int	arr[3] = {21, 42, 63};
	t_vector	*vec;
	int			*pp[3];

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)&arr[0]);
	ft_vec_add(&vec, (void *)&arr[1]);
	ft_vec_add(&vec, (void *)&arr[2]);
	ft_vec_filter(vec, is42, NULL);
	if (vec->count != 1 || *(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	ft_vec_clear(vec);
	pp[0] = malloc(sizeof(int));
	*pp[0] = 21;
	pp[1] = malloc(sizeof(int));
	*pp[1] = 42;
	pp[2] = malloc(sizeof(int));
	*pp[2] = 63;
	ft_vec_add(&vec, pp[0]);
	ft_vec_add(&vec, pp[1]);
	ft_vec_add(&vec, pp[2]);
	ft_vec_filter(vec, is42, free);
	if (vec->count != 1 || ft_vec_at(vec, 0) != pp[1])
		return (1);
	return (ft_vec_apply(vec, free), ft_vec_destroy(&vec), 0);
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
