/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_shift.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

static int	error_cases(void)
{
	t_vector	bad_vec;

	bad_vec.n_e = 0;
	bad_vec.s_e = 1;
	bad_vec.cappacity = 99;
	bad_vec.data = (void *)0xDEAD;
	ft_vec_shift(&bad_vec, 1, 1);
	bad_vec.n_e = 42;
	bad_vec.s_e = 0;
	ft_vec_shift(&bad_vec, 1, 1);
	return (EXIT_SUCCESS);
}

int	tv_shift(void)
{
	t_vector	*vec;
	const int	a[4] = {42, 43, 44, 45};

	vec = ft_vec_from_array(a, 4, sizeof(int));
	ft_vec_shift(vec, 1, 2);
	if (vec->n_e != 2)
		return (ft_vec_destroy(&vec), 1);
	else if (*(int *)ft_vec_at(vec, 0) != 42 || *(int *)ft_vec_at(vec, 1) != 45)
		return (ft_vec_destroy(&vec), 2);
	vec = (ft_vec_destroy(&vec), ft_vec_from_array(a, 4, sizeof(int)));
	ft_vec_shift(NULL, 1, 1);
	ft_vec_shift(vec, 99, sizeof(int));
	ft_vec_shift(vec, 1, 0);
	if (vec->n_e != 4 || *(int *)ft_vec_at(vec, 0) != 42
		|| *(int *)ft_vec_at(vec, 1) != 43 || *(int *)ft_vec_at(vec, 2) != 44
		|| *(int *)ft_vec_at(vec, 3) != 45)
		return (ft_vec_destroy(&vec), 3);
	ft_vec_shift(vec, 1, 999);
	if (vec->n_e != 1)
		return (ft_vec_destroy(&vec), 4);
	return (ft_vec_destroy(&vec), error_cases());
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
