/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_convert_alloc_array.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:30:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/vector_tests.h"

#include "ft_vector.h"
#include "ft_allocator__dev.h"
#include "tests/fixtures.h"

//	ft_vec_destroy(&vec);
	//  free(data); -> segfault : double free or corruption.
	// 	ft_vec_convert_alloccarray takes ownership of the data. refert to the
	// 	doc.
static int	base_case(void)
{
	t_vector	*vec;
	int			*a;
	size_t		len;

	len = 3;
	a = ft_calloc(len, sizeof(int));
	a[0] = 42;
	a[1] = 43;
	a[2] = 44;
	if (ft_vec_convert_alloccarray(a, 0, sizeof(int))
		|| ft_vec_convert_alloccarray(a, len, 0))
		return (ft_free(a), 1);
	vec = ft_vec_convert_alloccarray(a, len, sizeof(int));
	if (!vec)
		return (ft_free(a), 2);
	else if (vec->n_e != len || vec->s_e != sizeof(int) || !vec->data
		|| vec->cappacity != len)
		return (ft_vec_destroy(&vec), 3);
	else if (*(int *)ft_vec_at(vec, 0) != a[0]
		|| *(int *)ft_vec_at(vec, 1) != a[1]
		|| *(int *)ft_vec_at(vec, 2) != a[2])
		return (ft_vec_destroy(&vec), 4);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

static int	error_case(void)
{
	int			*arr;
	t_vector	*vec;

	arr = ft_calloc(3, sizeof(int));
	vec = ft_vec_convert_alloccarray(NULL, 3, sizeof(int));
	if (vec)
		return (ft_free(arr), ft_vec_destroy(&vec), 1 + 8 * 2);
	return (ft_free(arr), EXIT_SUCCESS);
}

static int	mt_case(void)
{
	int			*arr;
	t_vector	*vec;
	int			f_p;

	arr = ft_calloc(3, sizeof(int));
	f_p = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	vec = ft_vec_convert_alloccarray(arr, 3, sizeof(int));
	talloc_set_failpoint(f_p);
	if (vec)
		return (ft_free(arr), ft_vec_destroy(&vec), 1 + 8);
	return (ft_free(arr), EXIT_SUCCESS);
}

int	tv_convert_alloc_array(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = mt_case();
	if (ret)
		return (ret);
	ret = error_case();
	if (ret)
		return (ret);
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
