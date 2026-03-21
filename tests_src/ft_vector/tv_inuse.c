/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_inuse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/18 16:44:03 by bgoulard          #+#    #+#             */
/*   Updated: 2026/01/18 16:44:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

int	tv_inuse(void)
{
	t_vector	*vec;
	int			a;

	vec = ft_vec_create(sizeof(int));
	a = -1;
	while (++a < 3)
		ft_vec_add(vec, &a);
	if (ft_vec_inuse(vec) != (vec->n_e * vec->s_e))
		return (ft_vec_destroy(&vec), 1);
	if (ft_vec_inuse(NULL) != 0)
		return (ft_vec_destroy(&vec), 2);
	ft_vec_destroy(&vec);
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
