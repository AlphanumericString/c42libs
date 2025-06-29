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

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/tests__all_modules_tests.h"

#include "tests/tests.h"

int	tv_reserve(void)
{
	t_vector	*vec;
	int			f_point;
	int			i;
	bool		ret[4];

	vec = ft_vec_from_size(FT_VECTOR_BASE_LEN - 1);
	ret[0] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN - 2);
	ret[1] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN);
	ret[2] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN + 2);
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ret[3] = !ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN + 3);
	talloc_set_failpoint(f_point);
	i = 0;
	while (i < 4)
		if (ret[i++] != true)
			return (i);
	if (vec->cappacity != FT_VECTOR_BASE_LEN + 2)
		return (4 + 1);
	ft_vec_destroy(&vec);
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
