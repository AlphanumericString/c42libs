/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_from_array.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:19:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:09:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "types/ft_vector_types.h"
#include "tests/vector_tests.h"

static int	error_cases(void)
{
	int			fp;
	int			ar[] = {21, 42, 63, 84};
	t_vector	*v;

	v = ft_vec_from_array(ar, 0, 4);
	if (v)
		return (EXIT_FAILURE);
	v = ft_vec_from_array(ar, 4, 0);
	if (v)
		return (EXIT_FAILURE);
	v = ft_vec_from_array(NULL, 4, 4);
	if (v)
		return (EXIT_FAILURE);
	fp = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	v = ft_vec_from_array(ar, 4, sizeof(*ar));
	talloc_set_failpoint(fp);
	if (v)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}


static int	checks_01(t_vector *vec, const void **data)
{
	if (vec->n_e != 3 || vec->s_e != sizeof(data[0]) || !vec->data)
		return (1);
	else if (*(void **)ft_vec_at(vec, 0) != data[0]
		|| *(void **)ft_vec_at(vec, 1) != data[1]
		|| *(void **)ft_vec_at(vec, 2) != data[2])
		return (2);
	return (EXIT_SUCCESS);
}

static int	checks_02(t_vector *vec, const void **data)
{
	if (vec->n_e != 6 || vec->s_e != sizeof(data[0]) || !vec->data)
		return (3);
	else if (*(void **)ft_vec_at(vec, 0) != data[0]
		|| *(void **)ft_vec_at(vec, 1) != data[1]
		|| *(void **)ft_vec_at(vec, 2) != data[2]
		|| *(void **)ft_vec_at(vec, 3) != data[3]
		|| *(void **)ft_vec_at(vec, 4) != data[4]
		|| *(void **)ft_vec_at(vec, 5) != data[5])
		return (4);
	return (EXIT_SUCCESS);
}

// TODO: add mt case
// add errcases like 0 nmemb or 0 elem_size
int	tv_from_array(void)
{
	const void	*data[3] = {(void *)12, (void *)13, (void *)14};
	const void	*data2[6] = {(void *)20, (void *)21, (void *)22,
		(void *)23, (void *)24, (void *)25};
	t_vector	*vec;
	int			ret;

	vec = ft_vec_from_array(data, 3, sizeof(void *));
	ret = checks_01(vec, data);
	if (ret)
		return (ft_vec_destroy(&vec), ret);
	ft_vec_destroy(&vec);
	vec = ft_vec_from_array(data2, 6, sizeof(void *));
	ret = checks_02(vec, data2);
	if (ret)
		return (ft_vec_destroy(&vec), ret);
	return (ft_vec_destroy(&vec), error_cases());
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
