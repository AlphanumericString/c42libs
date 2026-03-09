/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_findget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 11:19:19 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/09 11:19:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/vector_tests.h"

static int	loc_int_it_eq(void *a, void *b)
{
	return (*(int *)a - *(int *)b);
}
static int	loc_int_it_inf(void *a, void *b)
{
	if (*(int *)a <= *(int *)b)
		return (0);
	return (-1);
}

int	tv_findget(void)
{
	const int	src[] = {23, 45, 67, 42};
	t_vector	a;
	int			res;
	int			treshold;

	res = 0;
	ft_vec_ifrom_array(&a, src, sizeof(src) / sizeof(src[0]), sizeof(int));
	treshold = 42;
	ft_vec_findget(&a, &treshold, (t_data_cmp)loc_int_it_inf, &res);
	if (res != 23)
		return (ft_vec_wipe(&a), 1);
	treshold = 33;
	ft_vec_findget(&a, &treshold, (t_data_cmp)loc_int_it_eq, &res);
	if (res != 0)
		return (ft_vec_wipe(&a), 2);
	if (ft_vec_findget(NULL, &treshold, (t_data_cmp)loc_int_it_eq, &res) != NULL
		|| ft_vec_findget(&a, &treshold, (t_data_cmp)loc_int_it_eq, NULL) != NULL)
		return (ft_vec_wipe(&a), 3);
	return (ft_vec_wipe(&a), 0);
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
