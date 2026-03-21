/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_from_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:20:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

static int	mt_tests(void)
{
	t_vector	*vec;
	t_vector	*vec2;
	int			f_point;

	vec = NULL;
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	vec = ft_vec_from_size(42);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	vec2 = ft_vec_from_size(42);
	talloc_set_failpoint(f_point);
	if (vec || vec2)
		return (ft_vec_destroy(&vec), ft_vec_destroy(&vec2), 2 + 16);
	return (EXIT_SUCCESS);
}

int	tv_from_size(void)
{
	t_vector	*vec;

	vec = ft_vec_from_size(42);
	if (vec->n_e != 0 || vec->s_e != 1)
		return (ft_vec_destroy(&vec), 1);
	else if (vec->cappacity != 42 || !vec->data)
		return (ft_vec_destroy(&vec), 2);
	ft_vec_destroy(&vec);
	return (mt_tests());
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
