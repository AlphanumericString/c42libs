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

static int	error_case(void)
{
	t_vector	*vec;
	const char	*arr_src[] = {"Hello", "world", "this", "is", "Zod"};
	const char	**arr_r;
	t_vector	*ar;
	size_t		i;

	i = 0;
	vec = ft_vec_create(sizeof(char *));
	while (i < (sizeof(arr_src) / sizeof(arr_src[0])))
		ft_vec_add(vec, &arr_src[i++]);
	arr_r = (t_any)ft_vec_to_array(NULL);
	if (arr_r != NULL)
		return (ft_vec_destroy(&vec), 1);
	ar = NULL;
	arr_r = (t_any)ft_vec_to_array(&ar);
	if (arr_r != NULL)
		return (ft_vec_destroy(&vec), 2);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

static int	base_case(void)
{
	t_vector	*vector;
	const char	*array_src[] = {"Hello", "world", "this", "is", "Zod"};
	const char	**array_ret;
	size_t		i;

	i = 0;
	vector = ft_vec_create(sizeof(char *));
	while (i < (sizeof(array_src) / sizeof(array_src[0])))
		ft_vec_add(vector, &array_src[i++]);
	array_ret = (t_any)ft_vec_to_array(&vector);
	if (vector)
		return (ft_free(array_ret), ft_free(vector), 1);
	i = 0;
	while (array_ret && i < 5 && !ft_strcmp(array_ret[i], array_src[i]))
		i++;
	if (i != 5)
		return (ft_free(array_ret), 2);
	ft_free(array_ret);
	array_ret = ft_vec_to_array(&vector);
	if (array_ret || vector)
		return (ft_free(array_ret), 3);
	return (EXIT_SUCCESS);
}

int	tv_to_array(void)
{
	int	ret;

	ret = base_case();
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
