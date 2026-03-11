/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/09 10:48:55 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 01:30:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_vector.h"
#include "tests/vector_tests.h"

static int	loc_cmp_str_it(const char **a, const char **b)
{
	return (ft_strcmp(*a, *b));
}

int	tv_cmp(void)
{
	const char	*src_1[] = {"this is zod", "aaaa", "aac"};
	const char	*src_2[] = {"this is zod", "aaaa", "aab"};
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;

	ft_vec_ifrom_array(&v1, src_1, 3, sizeof(const char *));
	ft_vec_ifrom_array(&v2, src_1, 3, sizeof(const char *));
	ft_vec_ifrom_array(&v3, src_2, 3, sizeof(const char *));
	if (ft_vec_cmp(&v1, &v2, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_cmp(&v2, &v1, (t_data_cmp)loc_cmp_str_it) != 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 1);
	if (ft_vec_cmp(&v1, &v2, NULL) != 0 || ft_vec_cmp(&v2, &v1, NULL) != 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 2);
	if (ft_vec_cmp(&v3, &v3, (t_data_cmp)loc_cmp_str_it) != 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 3);
	if (ft_vec_cmp(&v1, &v3, (t_data_cmp)loc_cmp_str_it) == 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 4);
	if (ft_vec_cmp(&v3, &v3, NULL) != 0
		|| ft_vec_cmp(NULL, &v3, (t_data_cmp)loc_cmp_str_it) != -1
		|| ft_vec_cmp(&v3, NULL, (t_data_cmp)loc_cmp_str_it) != 1)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 5);
	return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 0);
}

int	tv_ncmp(void)
{
	const char	*src_1[] = {"this is zod", "aaaa", "aac"};
	const char	*src_2[] = {"this is zod", "aaaa", "aab"};
	t_vector	v1;
	t_vector	v2;
	t_vector	v3;

	ft_vec_ifrom_array(&v1, src_1, 3, sizeof(const char *));
	ft_vec_ifrom_array(&v2, src_1, 3, sizeof(const char *));
	ft_vec_ifrom_array(&v3, src_2, 3, sizeof(const char *));
	if (ft_vec_ncmp(&v1, 2, &v1, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_ncmp(&v1, 2, &v2, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_ncmp(&v1, 2, &v3, (t_data_cmp)loc_cmp_str_it) != 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 1);
	if (ft_vec_ncmp(&v1, 3, &v1, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_ncmp(&v1, 3, &v2, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_ncmp(&v1, 3, &v3, (t_data_cmp)loc_cmp_str_it) == 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 2);
	if (ft_vec_ncmp(&v1, 999, &v1, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_ncmp(&v1, 999, &v2, (t_data_cmp)loc_cmp_str_it) != 0
		|| ft_vec_ncmp(&v1, 999, &v3, (t_data_cmp)loc_cmp_str_it) == 0)
		return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 2);
	return (ft_vec_wipe(&v1), ft_vec_wipe(&v2), ft_vec_wipe(&v3), 0);
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
