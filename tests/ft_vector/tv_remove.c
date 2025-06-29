/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_remove.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 10:13:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/tests__all_modules_tests.h"

// tests vector has removed the arr[2]orrect element
// and
// tests vector_remove is bound checked with 42's call
static int	checks_01(t_vector *vec)
{
	if (vec->count != 2)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42 || \
*(int *)ft_vec_at(vec, 1) != 44)
		return (2);
	ft_vec_remove(vec, 42, NULL);
	if (vec->count != 2)
		return (3);
	return (0);
}

// tests vector_remove calls free on the correct element
static int	checks_02(t_vector *vec, const int *arr)
{
	if (vec->count != 2)
		return (1);
	if (*(int *)ft_vec_at(vec, 0) != arr[0] || *(int *)ft_vec_at(vec, 1) != \
arr[2])
		return (1);
	return (0);
}

int	tv_remove(void)
{
	t_vector	*vec;
	const int	arr[3] = {42, 43, 44};
	int			*ptr;
	size_t		i;

	i = 0;
	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)&arr[0]);
	ft_vec_add(&vec, (void *)&arr[1]);
	ft_vec_add(&vec, (void *)&arr[2]);
	ft_vec_remove(vec, 1, NULL);
	if (checks_01(vec))
		return (checks_01(vec));
	ft_vec_destroy(&vec);
	vec = ft_vec_new();
	while (i < 3)
	{
		ptr = (int *)ft_malloc(sizeof(int));
		*ptr = arr[i++];
		ft_vec_add(&vec, (void *)ptr);
	}
	ft_vec_remove(vec, 1, ft_free);
	if (checks_02(vec, arr))
		return (checks_02(vec, arr));
	return (ft_vec_apply(vec, ft_free), ft_vec_destroy(&vec), 0);
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
