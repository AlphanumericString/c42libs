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

#include "ft_arr.h"
#include "ft_vector.h"
#include "ft_allocator__dev.h"
#include "tests/fixtures.h"

static int	**create_tb_int(size_t *size)
{
	int	**tab;
	int	nb;
	int	i;

	if (!size)
		nb = 10;
	else if (size && *size)
		nb = *size;
	else
	{
		*size = 10;
		nb = *size;
	}
	i = 0;
	tab = ft_calloc(sizeof(int *), nb);
	while (i < nb - 1)
	{
		tab[i] = ft_calloc(sizeof(int), 1);
		*(tab[i]) = 42 + i;
		i++;
	}
	tab[i] = NULL;
	return (tab);
}

//	ft_vec_destroy(&vec);
	//  free(data); -> segfault : double free or corruption.
	// 	ft_vec_convert_alloccarray takes ownership of the data. refert to the
	// 	doc.
static int	base_case(void)
{
	t_vector	*vec;
	int			**a;
	size_t		len;

	len = 0;
	a = create_tb_int(&len);
	vec = ft_vec_convert_alloccarray((void **)a, len);
	if (vec->count != len || vec->cappacity != len || vec->datas != (void **)a)
		return (1);
	else if (*(int *)ft_vec_at(vec, 0) != 42
		|| *(int *)ft_vec_at(vec, 1) != 43 || *(int *)ft_vec_at(vec, 2) != 44)
		return (2);
	(ft_vec_apply(vec, ft_free), ft_vec_destroy(&vec));
	a = create_tb_int(&len);
	vec = ft_vec_convert_alloccarray((void **)a, len);
	if (vec->count != len || vec->cappacity != len || vec->datas != (void **)a)
		return (3);
	else if (*(int *)ft_vec_at(vec, 0) != 42
		|| *(int *)ft_vec_at(vec, 1) != 43 || *(int *)ft_vec_at(vec, 2) != 44)
		return (4);
	return (ft_vec_apply(vec, ft_free), ft_vec_destroy(&vec), 0);
}

static int	mt_case(void)
{
	int			**arr;
	t_vector	*vec;
	int			f_p;

	arr = create_tb_int(NULL);
	f_p = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	vec = ft_vec_convert_alloccarray((void *)arr, 0);
	if (vec)
		return (1);
	talloc_set_failpoint(f_p);
	ft_afree((void **)arr);
	return (EXIT_SUCCESS);
}

int	tv_convert_alloc_array(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = mt_case();
	if (ret)
		return (ret + 10);
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
