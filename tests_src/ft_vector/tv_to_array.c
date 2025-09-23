/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_to_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:35:25 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

int	tv_to_array(void)
{
	t_vector	*vector;
	const char	**array;

	vector = ft_vec_new();
	ft_vec_add(&vector, "Hello");
	ft_vec_add(&vector, "world");
	ft_vec_add(&vector, "this");
	ft_vec_add(&vector, "is");
	ft_vec_add(&vector, "Zod");
	array = (const char **)ft_vec_to_array(&vector);
	if (ft_strcmp(array[0], "Hello") != 0)
		return (1);
	if (ft_strcmp(array[1], "world") != 0)
		return (1);
	if (ft_strcmp(array[2], "this") != 0)
		return (1);
	if (ft_strcmp(array[3], "is") != 0)
		return (1);
	if (ft_strcmp(array[4], "Zod") != 0)
		return (1);
	ft_free(array);
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
