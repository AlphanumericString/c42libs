/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_ncat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/11 00:30:56 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 01:29:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"
#include "types/ft_vector_types.h"
#include "ft_arr.h"

#include <stdio.h>

static int	ncat_base_cases(void)
{
	const char	*d_src[] = {"a", "sadljfadslf", "c"};
	const char	*split_res[] = {"example", "of", "a", "classical", "split",
		"return", NULL};
	t_vector	v;
	t_vector	v_src;

	ft_vec_ifrom_array(&v, d_src, 3, sizeof(char *));
	ft_vec_ifrom_array(&v_src, split_res, ft_alen((void *)split_res),
		sizeof(char *));
	if (ft_vec_ncat(&v, &v_src, v_src.n_e) != true || v.n_e != 3 + v_src.n_e)
		return (ft_vec_wipe(&v), ft_vec_wipe(&v_src), 1);
	if (ft_vec_ncat(&v, &v_src, -1) != true || v.n_e != 3 + v_src.n_e * 2)
		return (ft_vec_wipe(&v), ft_vec_wipe(&v_src), 2);
	if (ft_vec_ncat(&v, &v_src, 0) != true || v.n_e != 3 + v_src.n_e * 2)
		return (ft_vec_wipe(&v), ft_vec_wipe(&v_src), 3);
	return (ft_vec_wipe(&v), ft_vec_wipe(&v_src), 0);
}

static int	err_cases(void)
{
	t_vector	v;
	t_vector	v2;
	t_vector	v_dif_ele_size;

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	ft_vec_ifrom_array(&v_dif_ele_size, (char []){1, 2, 3}, 3, sizeof(char));
	ft_vec_ifrom_array(&v2, (int []){4, 5, 6}, 3, sizeof(int));
	if (ft_vec_ncat(NULL, &v2, 3) != false
		|| ft_vec_ncat(&v, NULL, 3) != false
		|| ft_vec_ncat(&v, &v_dif_ele_size, 3))
		return (ft_vec_wipe(&v2), ft_vec_wipe(&v),
			ft_vec_wipe(&v_dif_ele_size), 1);
	return (ft_vec_wipe(&v2), ft_vec_wipe(&v), ft_vec_wipe(&v_dif_ele_size),
		0);
}

static int	mt_cases(void)
{
	t_vector	v;
	t_vector	v2;
	const int	fp = *talloc_get_failpoint();
	bool		ret;

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	ft_vec_ifrom_array(&v2, (int []){4, 5, 6}, 3, sizeof(int));
	talloc_set_failpoint(0);
	ret = ft_vec_ncat(&v, &v2, v2.n_e);
	talloc_set_failpoint(fp);
	if (ret != false || v.n_e != 3)
		return (ft_vec_wipe(&v), ft_vec_wipe(&v2), 1);
	return (ft_vec_wipe(&v), ft_vec_wipe(&v2), 0);
}

int	tv_ncat(void)
{
	int	r;

	r = ncat_base_cases();
	if (r)
		return (r);
	r = err_cases();
	if (r)
		return (r + 8);
	r = mt_cases();
	if (r)
		return (r + 16);
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
