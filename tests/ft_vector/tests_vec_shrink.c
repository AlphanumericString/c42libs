/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_vec_shrink.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 11:28:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/30 07:27:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "types/ft_vector_types.h"
#include "tests/tests__all_modules_tests.h"

#include "tests/tests.h"

static int	base_cases(void)
{
	t_vector	*vec;
	void		*data[3];

	data[0] = (void *)42;
	data[1] = (void *)43;
	data[2] = (void *)44;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	ft_vec_shrink(vec);
	if (vec->count != 3 || vec->cappacity != 3)
		return (1);
	else if (ft_vec_at(vec, 0) != (void *) 42 || ft_vec_at(vec, 1) != \
(void *) 43 || ft_vec_at(vec, 2) != (void *) 44)
		return (2);
	ft_vec_shrink(vec);
	if (!vec || !vec->datas || !vec->cappacity || !vec->count || \
vec->count != vec->cappacity || vec->count != 3)
		return (3);
	ft_vec_destroy(&vec);
	return (0);
}

static int	mt_cases(void)
{
	t_vector	*vec;
	void		*data[3];
	int			f_point;

	data[0] = (void *)42;
	data[1] = (void *)43;
	data[2] = (void *)44;
	vec = ft_vec_from_array(data, sizeof(data) / sizeof(data[0]));
	f_point = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_vec_shrink(vec) != false)
		return (1);
	talloc_set_failpoint(f_point);
	ft_vec_destroy(&vec);
	return (0);
}

int	test_vec_shrink(void)
{
	int	ret;

	ret = base_cases();
	if (ret)
		return (ret);
	ret = mt_cases();
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
