/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:15:21 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "ft_mem.h"
#include "ft_vector.h"
#include "tests/fixtures.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"
#include <stdbool.h>

static int	mt_test(void)
{
	size_t		i;
	t_vector	*vec_a;
	t_vector	*vec_b;
	int			fp;
	bool		ret;

	i = 0;
	vec_a = ft_vec_create(sizeof(i));
	vec_b = ft_vec_create(sizeof(i));
	while (i++ < FT_VECTOR_BASE_LEN)
		(ft_vec_add(vec_a, &i), ft_vec_add(vec_b, &i));
	fp = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ret = ft_vec_cat(vec_a, vec_b);
	talloc_set_failpoint(fp);
	(ft_vec_delete(vec_a), ft_vec_delete(vec_b));
	if (ret)
		return (1 + 8);
	return (EXIT_SUCCESS);
}

static int	err_cases(void)
{
	t_vector	*va;
	t_vector	*vb;
	const int	a_src[] = {42, 43, 44};
	const int	b_src[] = {45, 46, 47};

	va = ft_vec_from_array(a_src, 3, sizeof(int));
	vb = ft_vec_from_array(b_src, 3, sizeof(int));
	if (ft_vec_cat(NULL, vb) || ft_vec_cat(va, NULL) || ft_vec_cat(NULL, NULL))
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 6);
	ft_vec_clear(vb);
	if (ft_vec_cat(va, vb) != true && va->n_e != 3)
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 7);
	return (ft_vec_destroy(&va), ft_vec_destroy(&vb), mt_test());
}

int	tv_cat(void)
{
	const int	exp[] = {42, 43, 44, 45, 46, 47};
	const int	a_src[] = {42, 43, 44};
	const int	b_src[] = {45, 46, 47};
	t_vector	*va;
	t_vector	*vb;

	va = ft_vec_from_array(a_src, 3, sizeof(int));
	vb = ft_vec_from_array(b_src, 3, sizeof(int));
	if (ft_vec_cat(va, vb) != true || va->n_e != 6)
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 1);
	else if (ft_vec_acmp(va, exp, ft_cmp_int_p))
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 2);
	va = (ft_vec_destroy(&va), ft_vec_create(sizeof(long)));
	if (ft_vec_cat(va, vb) != false || va->n_e != 0)
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 3);
	va = (ft_vec_destroy(&va), ft_vec_create(vb->s_e));
	if (ft_vec_cat(va, vb) != true || va->n_e != vb->n_e)
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 4);
	else if (ft_memcmp(va->data, vb->data, ft_vec_inuse(vb)) != 0)
		return (ft_vec_destroy(&va), ft_vec_destroy(&vb), 5);
	return (ft_vec_destroy(&va), ft_vec_destroy(&vb), err_cases());
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
