/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:13:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

#include "tests/fixtures.h"

static int	bases_case(void)
{
	t_vector	*vec;
	int			i;

	i = 42;
	vec = ft_vec_create(sizeof(int));
	ft_vec_add(vec, &i);
	if (vec->s_e != sizeof(int) || vec->n_e != 1)
		return (1);
	if (ft_memcmp(ft_vec_at(vec, 0), &i, sizeof(int)))
		return (2);
	while (i++ < 47)
		ft_vec_add(vec, &i);
	i = (42 - 1);
	while (++i < 47)
		if (ft_memcmp(ft_vec_at(vec, i - 42), &i, sizeof(int)))
			return (i + 8);
	ft_vec_destroy(&vec);
	return (EXIT_SUCCESS);
}

static int	err_case(void)
{
	t_vector	*vec;
	int			i;

	i = 42;
	vec = ft_vec_new();
	vec->s_e = 0;
	if (ft_vec_add(vec, &i) != false)
		return (1 + 16);
	return (ft_vec_delete(vec), EXIT_SUCCESS);
}

static int	mt_case(void)
{
	t_vector	*vec;
	int			f_po;
	int			i;

	vec = ft_vec_create(sizeof(int));
	i = 42;
	ft_vec_add(vec, &i);
	ft_vec_shrink(vec);
	f_po = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	i = 43;
	ft_vec_add(vec, &i);
	talloc_set_failpoint(f_po);
	if (vec->n_e != 1)
		return (1 + 32);
	ft_vec_destroy(&vec);
	return (EXIT_SUCCESS);
}

int	tv_add(void)
{
	int	ret;

	ret = bases_case();
	if (ret)
		return (ret);
	ret = err_case();
	if (ret)
		return (ret);
	ret = mt_case();
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
