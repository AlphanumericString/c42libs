/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_shrink.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

#include "tests/fixtures.h"

static int	base_cases(void)
{
	t_vector	state_1;
	t_vector	*vec;
	const long	data[3] = {42, 43, 44};
	size_t		i;

	vec = ft_vec_create(sizeof(void *));
	i = 0;
	while (i < sizeof(data) / sizeof(data[0]))
		ft_vec_add(vec, &data[i++]);
	ft_vec_shrink(vec);
	state_1 = *vec;
	if (vec->n_e != 3 || vec->cappacity != (vec->n_e * vec->s_e))
		return (1);
	else if (*(long *)ft_vec_at(vec, 0) != 42
		|| *(long *)ft_vec_at(vec, 1) != 43 || *(long *)ft_vec_at(vec, 2) != 44)
		return (2);
	ft_vec_shrink(vec);
	ft_vec_shrink(vec);
	ft_vec_shrink(vec);
	if (!vec || ft_memcmp(vec, &state_1, sizeof(t_vector)) != 0)
		return (3);
	return (ft_vec_destroy(&vec), EXIT_SUCCESS);
}

static int	edge_cases(void)
{
	t_vector	hold;
	t_vector	*vec;
	const long	data[] = {1, 2, 3};
	size_t		i;

	vec = ft_vec_create(sizeof(long));
	i = 0;
	while (i < (sizeof(data) / sizeof(data[0])))
		ft_vec_add(vec, &data[i++]);
	hold = *vec;
	vec->s_e = 0;
	if (ft_vec_shrink(vec) != false)
		return (1);
	*vec = hold;
	vec->n_e = 0;
	if (ft_vec_shrink(vec) != true || vec->cappacity != vec->s_e)
		return (2);
	hold = *vec;
	vec->data = NULL;
	if (ft_vec_shrink(vec) != false || vec->data != NULL)
		return (3);
	*vec = hold;
	if (ft_vec_shrink(NULL) != false)
		return (4);
	return (ft_vec_delete(vec), EXIT_SUCCESS);
}

static int	mt_cases(void)
{
	t_vector	*vec;
	const void	*data[3] = {(void *)42, (void *)43, (void *)44};
	size_t		i;
	int			f_point;

	vec = ft_vec_create(sizeof(data[0]));
	i = 0;
	while (i < sizeof(data) / sizeof(data[0]))
		ft_vec_add(vec, &data[i++]);
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_vec_shrink(vec) != false)
		return (1);
	talloc_set_failpoint(f_point);
	ft_vec_destroy(&vec);
	return (EXIT_SUCCESS);
}

int	tv_shrink(void)
{
	int	ret;

	ret = base_cases();
	if (ret)
		return (ret);
	ret = edge_cases();
	if (ret)
		return (ret + 8);
	ret = mt_cases();
	if (ret)
		return (ret + 16);
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
