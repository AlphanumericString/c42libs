/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_reserve.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:48:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_vector_types.h"

int	test_vec_reserve(void)
{
	t_vector	*vec;
	bool		ret[3];

	vec = ft_vec_from_size(FT_VECTOR_BASE_LEN - 1);
	ret[0] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN - 2);
	ret[1] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN);
	ret[2] = ft_vec_reserve(&vec, FT_VECTOR_BASE_LEN + 2);
	if (ret[0] != true)
		return (1);
	else if (ret[1] != true)
		return (1);
	else if (ret[2] == false)
		return (1);
	else if (vec->cappacity != FT_VECTOR_BASE_LEN + 2)
		return (1);
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
