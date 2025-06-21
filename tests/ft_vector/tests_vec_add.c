/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:13:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/30 07:33:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/tests__all_modules_tests.h"

#include "tests/tests.h"

static int	bases_case(void)
{
	t_vector	*vec;

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)42);
	if (vec->count != 1)
		return (1);
	if (vec->datas[0] != (void *)42)
		return (2);
	ft_vec_add(&vec, (void *)43);
	ft_vec_add(&vec, (void *)44);
	ft_vec_add(&vec, (void *)45);
	ft_vec_add(&vec, (void *)46);
	ft_vec_add(&vec, (void *)47);
	if (vec->count != 6)
		return (3);
	if (vec->datas[0] != (void *)42 || vec->datas[1] != (void *)43 || \
vec->datas[2] != (void *)44 || vec->datas[3] != (void *)45 || \
vec->datas[4] != (void *)46 || vec->datas[5] != (void *)47)
		return (4);
	ft_vec_destroy(&vec);
	return (0);
}

static int	mt_case(void)
{
	t_vector	*vec;
	int			f_po;

	vec = ft_vec_new();
	ft_vec_add(&vec, (void *)42);
	ft_vec_shrink(vec);
	f_po = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ft_vec_add(&vec, (void *)43);
	talloc_set_failpoint(f_po);
	if (vec->count != 1)
		return (1);
	ft_vec_destroy(&vec);
	return (0);
}

int	tv_add(void)
{
	int	ret;

	ret = bases_case();
	if (ret)
		return (ret);
	ret = mt_case();
	if (ret)
		return (ret + 10);
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
