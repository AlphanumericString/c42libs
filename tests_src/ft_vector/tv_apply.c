/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_apply.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:13:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"
#include "tests/tests_lambda_functions.h"

int	tv_apply(void)
{
	t_vector	*vec;
	size_t		i;

	i = 0;
	vec = ft_vec_create(sizeof(i));
	ft_vec_add(vec, &i);
	ft_vec_apply(vec, add42);
	if (*((size_t *)ft_vec_at(vec, 0)) != 42)
		return (1);
	vec->s_e = 0;
	ft_vec_apply(vec, add42);
	i = vec->n_e;
	vec->n_e = 0;
	ft_vec_apply(vec, add42);
	vec->s_e = sizeof(i);
	ft_vec_apply(vec, add42);
	*vec = (t_vector){.cappacity = vec->cappacity, .data = vec->data,
		.n_e = i, .s_e = sizeof(i)};
	ft_vec_destroy(&vec);
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
