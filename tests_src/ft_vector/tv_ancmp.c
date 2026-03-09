/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_ancmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 22:58:00 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/08 22:58:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "ft_string.h"
#include "tests/vector_tests.h"
#include <stdio.h>

static int	loc_longcmp_it(const long **a, const long **b)
{
	return (*a - *b);
}

static int	loc_strcmp_it(const char **a, const char **b)
{
	return (ft_strcmp(*a, *b));
}

static int	loc_strcmp_spe(const char **a, const char **b)
{
	if (!ft_strcmp(*a, ".*"))
		return (0);
	if (!ft_strcmp(*b, ".*"))
		return (0);
	return (ft_strcmp(*a, *b));
}

int	tv_acmp(void)
{
	void		*a_src[] = {(void *)0xDEAD, (void *)0, (void *)0xBEEFCAFE};
	void		*new_val = (void *)0xCAFE;
	t_vector	v;

	ft_vec_ifrom_array(&v, a_src, 3, sizeof(void *));
	if (ft_vec_acmp(&v, a_src, (t_data_cmp)loc_longcmp_it) != 0)
		return (ft_vec_wipe(&v), 1);
	ft_vec_set(&v, 2, &new_val);
	if (ft_vec_acmp(&v, a_src, (t_data_cmp)loc_longcmp_it) == 0)
		return (ft_vec_wipe(&v), 2);
	return (ft_vec_wipe(&v), 0);
}

int	tv_ancmp(void)
{
	t_vector	v;
	const char	*src_arr[] = {"a", "b", "c"};
	const char	*spe_arr[] = {".*", ".*", "c"};

	ft_vec_ifrom_array(&v, src_arr, 3, sizeof(const char *));
	if (ft_vec_ancmp(&v, 3, src_arr, (t_data_cmp)loc_strcmp_it))
		return (ft_vec_wipe(&v), 1);
	if (ft_vec_ancmp(&v, 3, spe_arr, (t_data_cmp)loc_strcmp_it) == 0)
		return (ft_vec_wipe(&v), 2);
	if (ft_vec_ancmp(&v, 3, spe_arr, (t_data_cmp)loc_strcmp_spe))
		return (ft_vec_wipe(&v), 3);
	if (ft_vec_ancmp(&v, 3, NULL, (t_data_cmp)loc_strcmp_it) != -1)
		return (ft_vec_wipe(&v), 4);
	if (ft_vec_ancmp(NULL, 3, src_arr, (t_data_cmp)loc_strcmp_it) != 1)
		return (ft_vec_wipe(&v), 5);
	if (ft_vec_ancmp(NULL, 3, NULL, (t_data_cmp)loc_strcmp_it) != 0)
		return (ft_vec_wipe(&v), 6);
	return (ft_vec_wipe(&v), 0);
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
