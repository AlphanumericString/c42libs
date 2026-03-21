/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/25 08:48:10 by bgoulard          #+#    #+#             */
/*   Updated: 2026/02/25 08:48:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"

static int	mt_init(void)
{
	t_vector	v;
	t_vector	*ret;
	const int	fp = *talloc_get_failpoint();

	talloc_set_failpoint(0);
	ret = ft_vec_init(&v, 3, sizeof(int));
	talloc_set_failpoint(fp);
	if (ret != NULL)
		return (ft_vec_wipe(ret), 4);
	return (0);
}

int	tv_init(void)
{
	t_vector	v;

	ft_vec_init(&v, 3, sizeof(int));
	if (v.n_e != 0 || v.s_e != sizeof(int) || v.cappacity < 3)
		return (ft_vec_wipe(&v), 1);
	return (ft_vec_wipe(&v), mt_init());
}

static int	mt_fromarr(void)
{
	const int	fp = *talloc_get_failpoint();
	t_vector	v;
	const int	arr[] = {1, 2, 3};
	t_vector	*ret;

	talloc_set_failpoint(0);
	ret = ft_vec_ifrom_array(&v, arr, 3, sizeof(int));
	talloc_set_failpoint(fp);
	if (ret != NULL)
		return (ft_vec_wipe(ret), 17);
	return (0);
}

int	tv_ifrom_array(void)
{
	t_vector	v;
	const int	arr[] = {1, 2, 3};

	ft_vec_ifrom_array(&v, arr, 3, sizeof(int));
	if (!v.data || v.data == arr)
		return (ft_vec_wipe(&v), 1);
	if (v.n_e != 3 || v.s_e != sizeof(int) || v.cappacity < 3)
		return (ft_vec_wipe(&v), 2);
	ft_vec_wipe(&v);
	if (ft_vec_ifrom_array(&v, NULL, 3, sizeof(int)) != NULL)
		return (4);
	if (ft_vec_ifrom_array(NULL, arr, 3, sizeof(int)) != NULL)
		return (5);
	if (ft_vec_ifrom_array(NULL, arr, 3, sizeof(int)) != NULL)
		return (6);
	if (ft_vec_ifrom_array(&v, arr, 0, sizeof(int)) != NULL)
		return (7);
	if (ft_vec_ifrom_array(&v, arr, 3, 0) != NULL)
		return (8);
	return (mt_fromarr());
}

int	tv_iconvert_allocarray(void)
{
	t_vector	v;
	int			*arr;

	arr = ft_malloc(sizeof(int) * 3);
	ft_memcpy(arr, (int []){1, 2, 3}, sizeof(int) * 3);
	ft_vec_iconvert_allocarray(&v, arr, 3, sizeof(int));
	if (!v.data || v.data != arr)
		return (ft_free(arr), 1);
	if (v.n_e != 3 || v.s_e != sizeof(int) || v.cappacity < 3)
		return (ft_free(arr), 2);
	v = (t_vector){0};
	if (ft_vec_iconvert_allocarray(&v, NULL, 3, sizeof(int)) != NULL)
		return (ft_free(arr), 4);
	if (ft_vec_iconvert_allocarray(NULL, arr, 3, sizeof(int)) != NULL)
		return (ft_free(arr), 5);
	if (ft_vec_iconvert_allocarray(NULL, arr, 3, sizeof(int)) != NULL)
		return (ft_free(arr), 6);
	if (ft_vec_iconvert_allocarray(&v, arr, 0, sizeof(int)) != NULL)
		return (ft_free(arr), 7);
	if (ft_vec_iconvert_allocarray(&v, arr, 3, 0) != NULL)
		return (ft_free(arr), 8);
	return (ft_free(arr), 0);
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
