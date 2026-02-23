/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:20:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

int	tv_delete(void)
{
	t_vector	*vec;
	void		*hold;

	vec = ft_vec_create(sizeof(void *));
	if (ft_vec_delete(vec) != true)
		return (1);
	vec = NULL;
	if (ft_vec_delete(vec) != false)
		return (2);
	vec = ft_vec_create(sizeof(void *));
	hold = vec->data;
	vec->data = NULL;
	if (ft_vec_delete(vec) != true)
		return (3);
	ft_free(hold);
	return (EXIT_SUCCESS);
}

int	tv_destroy(void)
{
	t_vector	*vec;
	bool		ret;
	const int	a[] = {0, 1, 2};
	void		*data;

	vec = ft_vec_from_array(a, 3, sizeof(int));
	ret = ft_vec_destroy(&vec);
	if (vec || ret != true)
		return (1);
	ret = ft_vec_destroy(&vec);
	if (vec || ret != false)
		return (2);
	vec = ft_vec_from_array(a, 3, sizeof(int));
	data = vec->data;
	vec->data = NULL;
	ret = ft_vec_destroy(&vec);
	if (vec || !ret)
		return (3);
	return (ft_free(data), EXIT_SUCCESS);
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
