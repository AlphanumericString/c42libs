/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:25:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"
#include "tests/tests_lambda_functions.h"
#include "types/ft_vector_types.h"
#include <stdlib.h>

static int	edge(t_vector *vect, const char **src_2)
{
	const t_vector	original_state = *vect;

	vect->n_e = 0;
	if (ft_vec_find(vect, "Hello", cmp_str) != NULL)
		return (4);
	vect->n_e = original_state.n_e;
	vect->s_e = 0;
	if (ft_vec_find(vect, "Hello", cmp_str) != NULL)
		return (5);
	vect->s_e = original_state.s_e;
	vect->data = NULL;
	if (ft_vec_find(vect, "Hello", cmp_str) != NULL)
		return (6);
	*vect = original_state;
	if (*(char **)ft_vec_find(vect, src_2, cmp_str) != *src_2
		|| *(char **)ft_vec_find(vect, ft_vec_at(vect, 2), NULL) != *src_2
		|| ft_vec_find(NULL, ft_vec_at(vect, 2), cmp_str) != NULL
		|| ft_vec_find(vect, "zboub", NULL) != NULL)
		return (6);
	return (0);
}

int	tv_find(void)
{
	size_t		i;
	const char	*src[] = {"Hello", "world", "this", "is", "Zod"};
	t_vector	*vector;
	void		*data_ret;

	vector = ft_vec_create(sizeof(char *));
	i = 0;
	while (i < (sizeof(src) / sizeof(src[0])))
		ft_vec_add(vector, &src[i++]);
	data_ret = ft_vec_find(vector, "world", cmp_str);
	if (data_ret && ft_strcmp(data_ret, "world") != 0)
		return (ft_vec_destroy(&vector), 1);
	data_ret = ft_vec_find(vector, "Zod", cmp_str);
	if (data_ret && ft_strcmp(data_ret, "Zod") != 0)
		return (ft_vec_destroy(&vector), 2);
	if (ft_vec_find(vector, "not here", cmp_str) != NULL
		|| ft_vec_find(vector, "not here", NULL) != NULL)
		return (ft_vec_destroy(&vector), 3);
	i = edge(vector, &src[2]);
	if (i)
		return (ft_vec_destroy(&vector), i);
	return (ft_vec_destroy(&vector), EXIT_SUCCESS);
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
