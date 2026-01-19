/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:27:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

static int	error_case(void)
{
	t_vector	hold;
	t_vector	*vec;
	const int	data[3] = {42, 43, 44};

	vec = ft_vec_from_array(data, 3, sizeof(int));
	hold = *vec;
	vec->n_e = 0;
	ft_vec_swap(vec, 0, 2);
	*vec = hold;
	vec->s_e = 0;
	ft_vec_swap(vec, 0, 2);
	*vec = hold;
	vec->data = NULL;
	ft_vec_swap(vec, 0, 2);
	*vec = hold;
	ft_vec_swap(NULL, 0, 2);
	ft_vec_swap(vec, 999, 2);
	ft_vec_swap(vec, 0, 999);
	return (ft_vec_delete(vec), EXIT_SUCCESS);
}

static int	base_case(void)
{
	t_vector	*vec;
	const int	data[3] = {42, 43, 44};

	vec = ft_vec_from_array(data, 3, sizeof(int));
	ft_vec_swap(vec, 0, 2);
	if (vec->n_e != 3)
		return (ft_vec_destroy(&vec), 1);
	else if (*(int *)ft_vec_at(vec, 1) != 43)
		return (ft_vec_destroy(&vec), 2);
	else if (*(int *)ft_vec_at(vec, 0) != 44
		|| *(int *)ft_vec_at(vec, 2) != 42)
		return (ft_vec_destroy(&vec), 3);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

int	tv_swap(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = error_case();
	if (ret)
		return (ret + 8);
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
