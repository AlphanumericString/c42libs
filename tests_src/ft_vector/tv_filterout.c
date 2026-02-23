/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_remove_if.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"
#include "tests/tests_lambda_functions.h"

static int	error_case(void)
{
	t_vector	*vec;
	t_vector	hold;
	const int	a[3] = {42, 43, 44};

	vec = ft_vec_from_array(a, 3, sizeof(int));
	ft_vec_filterout(vec, NULL, NULL);
	ft_vec_filterout(NULL, is42, NULL);
	hold = *vec;
	vec->n_e = 0;
	ft_vec_filterout(vec, is42, NULL);
	*vec = hold;
	vec->s_e = 0;
	ft_vec_filterout(vec, is42, NULL);
	*vec = hold;
	vec->data = NULL;
	ft_vec_filterout(vec, is42, NULL);
	*vec = hold;
	ft_vec_destroy(&vec);
	return (EXIT_SUCCESS);
}

static int	base_case(void)
{
	t_vector	*vec;
	const int	a[3] = {42, 43, 44};

	vec = ft_vec_from_array(a, 3, sizeof(int));
	ft_vec_filterout(vec, is42, NULL);
	if (vec->n_e != 2)
		return (ft_vec_destroy(&vec), 1);
	else if (*(int *)ft_vec_at(vec, 0) != 43)
		return (ft_vec_destroy(&vec), 2);
	else if (*(int *)ft_vec_at(vec, 1) != 44)
		return (ft_vec_destroy(&vec), 3);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

int	tv_filterout(void)
{
	int	a;
	int	b;

	a = base_case();
	b = error_case();
	if (a || b)
		return (a + b * 100);
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
