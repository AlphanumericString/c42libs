/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:13:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

static bool	*was_called(void)
{
	static bool	t = false;

	return (&t);
}

static void	dummy_recorder(void *e)
{
	*was_called() = true;
	(void)e;
}

// crashes on fail so no returns lol
static int	error_cases(void)
{
	t_vector	bad_vec;
	void		*fake_data;

	fake_data = (void *)0xDEAD;
	ft_vec_remove(NULL, 3, NULL);
	bad_vec = (t_vector){.data = NULL, .n_e = 2, .s_e = 4, .cappacity = 5};
	ft_vec_remove(&bad_vec, 0, NULL);
	bad_vec = (t_vector){.data = fake_data, .n_e = 0, .s_e = 4, .cappacity = 5};
	ft_vec_remove(&bad_vec, 0, NULL);
	bad_vec = (t_vector){.data = fake_data, .n_e = 2, .s_e = 0, .cappacity = 5};
	ft_vec_remove(&bad_vec, 0, NULL);
	return (EXIT_SUCCESS);
}

int	tv_remove(void)
{
	t_vector	*vec;
	const int	arr[3] = {42, 43, 44};

	vec = ft_vec_from_array(arr, 3, sizeof(int));
	ft_vec_remove(vec, 1, NULL);
	if (vec->n_e != 2 || *(int *)ft_vec_at(vec, 0) != 42
		|| *(int *)ft_vec_at(vec, 1) != 44)
		return (ft_vec_destroy(&vec), 1);
	ft_vec_remove(vec, 0, NULL);
	if (vec->n_e != 1 || *(int *)ft_vec_at(vec, 0) != 44)
		return (ft_vec_destroy(&vec), 2);
	ft_vec_remove(vec, 0, NULL);
	if (vec->n_e != 0)
		return (ft_vec_destroy(&vec), 3);
	ft_vec_destroy(&vec);
	error_cases();
	vec = ft_vec_from_array(arr, 3, sizeof(int));
	ft_vec_remove(vec, 999, dummy_recorder);
	if (*was_called() != true)
		return (ft_vec_destroy(&vec), 4);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
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
