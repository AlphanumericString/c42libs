/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

int	tv_new(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	if (vec->n_e != 0 || vec->s_e != 1
		|| vec->cappacity != FT_VECTOR_BASE_LEN)
		return (ft_vec_destroy(&vec), 1);
	else if (!vec->data)
		return (ft_vec_destroy(&vec), 2);
	ft_vec_destroy(&vec);
	return (EXIT_SUCCESS);
}

#pragma GCC diagnostic warning "-Wdeprecated-declarations"

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
