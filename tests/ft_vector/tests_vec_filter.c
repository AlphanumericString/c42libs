/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_filter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:20:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:38:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "tests/tests__all_modules_tests.h"

#include "ft_vector.h"
#include "ft_vector_types.h"

#include "ft_string.h"

#include "tests/tests_lambda_functions.h"

static int	**create_tb_int(int *size)
{
	int	**tab;
	int	i;

	if (size)
		*size = 10;
	i = 10;
	tab = ft_calloc(sizeof(int *), i + 1);
	i = 0;
	while (i < 10)
	{
		tab[i] = ft_calloc(sizeof(int), 1);
		*(tab[i]) = 42 + i;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

static int	base_case(void)
{
	const int	arr[3] = {21, 42, 63};
	t_vector	*vec;
	int			**pp;

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)&arr[0]);
	ft_vec_add(&vec, (void *)&arr[1]);
	ft_vec_add(&vec, (void *)&arr[2]);
	ft_vec_filter(vec, is42, NULL);
	if (vec->count != 1 || *(int *)ft_vec_at(vec, 0) != 42)
		return (1);
	ft_vec_destroy(&vec);
	pp = (int **)create_tb_int(NULL);
	*(pp[8]) = 42;
	*(pp[3]) = 42;
	*(pp[4]) = 42;
	vec = ft_vec_convert_alloccarray((void **)pp, 0);
	ft_vec_filter(vec, is42, ft_free);
	if (ft_vec_at(vec, 0) != pp[0])
		return (2);
	return (ft_vec_apply(vec, ft_free), ft_vec_destroy(&vec), 0);
}

int	test_vec_filter(void)
{
	int	ret;

	ret = base_case();
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
