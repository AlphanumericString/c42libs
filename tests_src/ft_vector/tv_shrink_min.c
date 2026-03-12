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

#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/vector_tests.h"
#include "types/ft_vector_types.h"
#include <stdio.h>

static int	mt_cases(void)
{
	t_vector	v;
	const int	fp = *talloc_get_failpoint();
	int			ret;

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	ft_vec_reserve(&v, 12);
	ret = 0;
	talloc_set_failpoint(0);
	if (ft_vec_shrink_min(&v, 4) != false)
		ret = 32 + 1;
	talloc_set_failpoint(fp);
	ft_vec_wipe(&v);
	return (ret);
}

static int	error_cases(void)
{
	t_vector	v;
	t_vector	malicious;

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	ft_vec_reserve(&v, 12);
	malicious = v;
	malicious.n_e = 0;
	if (ft_vec_shrink_min(&malicious, 1) != false)
		return (ft_vec_wipe(&v), 16 + 1);
	malicious = v;
	malicious.s_e = 0;
	if (ft_vec_shrink_min(&malicious, 1) != false)
		return (ft_vec_wipe(&v), 16 + 2);
	malicious = v;
	malicious.data = 0;
	if (ft_vec_shrink_min(&malicious, 1) != false)
		return (ft_vec_wipe(&v), 16 + 3);
	malicious = v;
	malicious.cappacity = 0;
	if (ft_vec_shrink_min(&malicious, 1) != false)
		return (ft_vec_wipe(&v), 16 + 4);
	if (ft_vec_shrink_min(NULL, 1) != false)
		return (ft_vec_wipe(&v), 16 + 5);
	return (ft_vec_wipe(&v), mt_cases());
}

int	tv_shrink_min(void)
{
	t_vector	v;

	ft_vec_ifrom_array(&v, (int []){1, 2, 3}, 3, sizeof(int));
	ft_vec_reserve(&v, 12);
	if (v.cappacity < 12)
		return (ft_vec_wipe(&v), 1);
	if (ft_vec_shrink_min(&v, 0) != true || v.n_e != v.cappacity)
		return (ft_vec_wipe(&v), 2);
	if (ft_vec_shrink_min(&v, 1) != true || v.n_e != v.cappacity)
		return (ft_vec_wipe(&v), 3);
	ft_vec_reserve(&v, 12);
	if (ft_vec_shrink_min(&v, 4) != true || v.n_e + 1 != v.cappacity)
		return (ft_vec_wipe(&v), 4);
	if (ft_vec_shrink_min(&v, 2) != true || v.n_e != v.cappacity)
		return (ft_vec_wipe(&v), 5);
	return (ft_vec_wipe(&v), error_cases());
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
