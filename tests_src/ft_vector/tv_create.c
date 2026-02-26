/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 23:57:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/01 23:57:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"

// allow's next alloc and fail after:
// talloc_set_failpoint(*talloc_get_currentpoint() + 1);
static int	mt_error(void)
{
	const int	fp = *talloc_get_failpoint();
	t_vector	*vec;

	talloc_set_failpoint(0);
	vec = ft_vec_create(4);
	talloc_set_failpoint(fp);
	if (vec)
		return (ft_vec_destroy(&vec), 4);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	vec = ft_vec_create(4);
	talloc_set_failpoint(fp);
	if (vec)
		return (ft_vec_destroy(&vec), 5);
	return (EXIT_SUCCESS);
}

int	tv_create(void)
{
	t_vector	*v;

	v = ft_vec_create(12);
	if (v->cappacity < FT_VECTOR_BASE_LEN)
		return (ft_vec_destroy(&v), 1);
	if (v->n_e != 0 || v->s_e != 12)
		return (ft_vec_destroy(&v), 2);
	if (ft_vec_create(0) != NULL)
		return (ft_vec_destroy(&v), 3);
	return (ft_vec_destroy(&v), mt_error());
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
