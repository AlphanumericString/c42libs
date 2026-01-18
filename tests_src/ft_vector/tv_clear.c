/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_clear.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:21:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

int	tv_clear(void)
{
	t_vector	*vec;
	const int	a[] = {0, 1, 2};

	vec = ft_vec_from_array((t_any)a, sizeof(a) / sizeof(a[0]), sizeof(a[0]));
	ft_vec_clear(vec);
	if (vec->n_e != 0 || ft_vec_at(vec, 0) != NULL)
		return (1);
	else if (vec->cappacity == 0)
		return (2);
	ft_vec_clear(vec);
	ft_vec_clear(vec);
	ft_vec_clear(vec);
	ft_vec_clear(NULL);
	if (vec->n_e != 0 || ft_vec_at(vec, 0) != NULL || vec->cappacity == 0)
		return (3);
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
