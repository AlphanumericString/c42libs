/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 11:25:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:38:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "tests/tests__all_modules_tests.h"

static int	cmp_fun(const void *v_data, const void *key)
{
	return (ft_strcmp(v_data, key));
}

int	tv_get(void)
{
	t_vector	*vector;
	void		*data_ret;

	vector = ft_vec_new();
	ft_vec_add(&vector, "Hello");
	ft_vec_add(&vector, "world");
	ft_vec_add(&vector, "this");
	ft_vec_add(&vector, "is");
	ft_vec_add(&vector, "Zod");
	data_ret = ft_vec_find(vector, "world", cmp_fun);
	if (ft_strcmp(data_ret, "world") != 0)
		return (1);
	data_ret = ft_vec_find(vector, "Zod", cmp_fun);
	if (ft_strcmp(data_ret, "Zod") != 0)
		return (1);
	data_ret = ft_vec_find(vector, "not here", cmp_fun);
	if (data_ret)
		return (1);
	ft_vec_destroy(&vector);
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
