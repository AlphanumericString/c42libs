/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nremove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/23 10:27:31 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/23 10:27:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
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

static int	tv_nremove_error(void)
{
	t_vector	bad_vec;
	void		*fake_data;
	t_vector	*vec;

	vec = ft_vec_from_array((int []){1, 2, 3, 4, 5}, 5, sizeof(int));
	fake_data = (void *)0xDEAD;
	ft_vec_nremove(NULL, 0, 12, NULL);
	bad_vec = (t_vector){.data = NULL, .n_e = 2, .s_e = 4, .cappacity = 5};
	ft_vec_nremove(&bad_vec, 0, 12, NULL);
	bad_vec = (t_vector){.data = fake_data, .n_e = 0, .s_e = 4, .cappacity = 5};
	ft_vec_nremove(&bad_vec, 0, 12, NULL);
	bad_vec = (t_vector){.data = fake_data, .n_e = 2, .s_e = 0, .cappacity = 5};
	ft_vec_nremove(&bad_vec, 0, 12, NULL);
	ft_vec_nremove(vec, vec->n_e + 3, 2, NULL);
	ft_vec_nremove(vec, 1, 0, NULL);
	ft_vec_destroy(&vec);
	return (EXIT_SUCCESS);
}

int	tv_nremove(void)
{
	t_vector	*vec;

	vec = ft_vec_from_array((int []){1, 2, 3, 4, 5}, 5, sizeof(int));
	ft_vec_nremove(vec, 2, 2, dummy_recorder);
	if (vec->n_e != 3 || *(int *)ft_vec_at(vec, 0) != 1
		|| *(int *)ft_vec_at(vec, 1) != 2
		|| *(int *)ft_vec_at(vec, 2) != 5)
		return (ft_vec_destroy(&vec), 1);
	if (*was_called() != true)
		return (2);
	ft_vec_nremove(vec, 1, 9999, NULL);
	if (vec->n_e != 1 || *(int *)ft_vec_at(vec, 0) != 1)
		return (ft_vec_destroy(&vec), 2);
	ft_vec_destroy(&vec);
	*was_called() = false;
	vec = ft_vec_from_array((int []){1, 2, 3, 4, 5}, 5, sizeof(int));
	ft_vec_nremove(vec, 0, 3, dummy_recorder);
	if (vec->n_e != 0 && *was_called() != true)
		return (ft_vec_destroy(&vec), 3);
	*was_called() = (ft_vec_destroy(&vec), false);
	vec = ft_vec_from_array((int []){1, 2, 3, 4, 5}, 5, sizeof(int));
	ft_vec_nremove(vec, 0, -1, dummy_recorder);
	if (vec->n_e != 0 && *was_called() != true)
		return (ft_vec_destroy(&vec), 4);
	return (ft_vec_destroy(&vec), tv_nremove_error(), EXIT_SUCCESS);
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
