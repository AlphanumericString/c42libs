/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_reserve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

#include "tests/fixtures.h"

static int	edge(void)
{
	t_vector	*v;
	bool		ret;
	void		*d;

	v = ft_vec_from_size(FT_VECTOR_BASE_LEN);
	d = v->data;
	v->data = NULL;
	ret = ft_vec_reserve(v, FT_VECTOR_BASE_LEN);
	ft_free(d);
	if (!v->data || !ret)
		return (1 + 8);
	ft_vec_delete(v);
	if (ft_vec_reserve(NULL, 42) != false
		|| ft_vec_reserve((t_vector *)0xDEAD, 0) != false)
		return (2 + 8);
	return (EXIT_SUCCESS);
}

int	tv_reserve(void)
{
	t_vector	*vec;
	int			f_point;
	int			i;
	bool		ret[4];

	vec = ft_vec_from_size(FT_VECTOR_BASE_LEN - 1);
	ret[0] = ft_vec_reserve(vec, FT_VECTOR_BASE_LEN - 2);
	ret[1] = ft_vec_reserve(vec, FT_VECTOR_BASE_LEN);
	ret[2] = ft_vec_reserve(vec, FT_VECTOR_BASE_LEN + 2);
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ret[3] = !ft_vec_reserve(vec, FT_VECTOR_BASE_LEN * 2 + 3);
	talloc_set_failpoint(f_point);
	i = 0;
	while (i < 4)
		if (ret[i++] != true)
			return (i);
	if (vec->cappacity != (FT_VECTOR_BASE_LEN * 2))
		return (5 + 1);
	return (ft_vec_destroy(&vec), edge());
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
