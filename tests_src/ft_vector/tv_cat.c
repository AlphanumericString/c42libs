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

#include "ft_mem.h"
#include "ft_vector.h"
#include "tests/fixtures.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"
#include <stdbool.h>
#include <stdio.h>

/*
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ft_vec_add(&vec_b, &d); // 45
	ft_vec_add(&vec_b, &e); // 45 46
	ft_vec_add(&vec_b, &f); // 45 46 47
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
	ft_vec_add(&vec_a, &a); // 42
	ft_vec_add(&vec_a, &b); // 42 43
	ft_vec_add(&vec_a, &c); // 42 43 44
	ret = ft_vec_cat(&vec_a, vec_b); // 42 43 44 + 45 46 47
*/

static void	init_vec_cat(t_vector **vec_a, t_vector **vec_b)
{
	int	i;

	*vec_a = ft_vec_create(sizeof(int));
	i = 42 - 1;
	while (++i - 42 < 3)
		ft_vec_add(*vec_a, &i);
	i = 45 - 1;
	*vec_b = ft_vec_create(sizeof(int));
	while (++i - 45 < 3)
		ft_vec_add(*vec_b, &i);
}

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
	while (i < (vec_a->cappacity / vec_a->s_e))
	{
		ft_vec_add(vec_a, &i);
		ft_vec_add(vec_b, &i);
		i++;
	}
	fp = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ret = ft_vec_cat(vec_a, vec_b);
	talloc_set_failpoint(fp);
	(ft_vec_delete(vec_a), ft_vec_delete(vec_b));
	if (ret)
		return (1 + 8);
	return (EXIT_SUCCESS);
}

int	tv_cat(void)
{
	bool		ret;
	t_vector	*vec_a;
	t_vector	*vec_b;

	init_vec_cat(&vec_a, &vec_b);
	ret = ft_vec_cat(vec_a, vec_b);
	if (ret != true || vec_a->n_e != 6)
		return (1);
	else if (*(int *)ft_vec_at(vec_a, 0) != 42
		|| *(int *)ft_vec_at(vec_a, 1) != 43
		|| *(int *)ft_vec_at(vec_a, 2) != 44
		|| *(int *)ft_vec_at(vec_a, 3) != 45
		|| *(int *)ft_vec_at(vec_a, 4) != 46
		|| *(int *)ft_vec_at(vec_a, 5) != 47)
		return (2);
	vec_a = (ft_vec_destroy(&vec_a), ft_vec_create(sizeof(long)));
	if (ft_vec_cat(vec_a, vec_b) != false || vec_a->n_e != 0)
		return (3);
	vec_a = (ft_vec_destroy(&vec_a), ft_vec_create(vec_b->s_e));
	if (ft_vec_cat(vec_a, vec_b) != true || vec_a->n_e != vec_b->n_e)
		return (4);
	else if (ft_memcmp(vec_a->data, vec_b->data, ft_vec_inuse(vec_b)) != 0)
		return (5);
	return (ft_vec_destroy(&vec_a), ft_vec_destroy(&vec_b), mt_test());
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
