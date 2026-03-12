/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tv_nmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 09:51:04 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/12 09:51:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "ft_vector.h"
#include "tests/fixtures.h"
#include "tests/tests_lambda_functions.h"
#include "tests/vector_tests.h"
#include "types/ft_vector_types.h"

static int	mt_cases(void)
{
	t_vector	v;
	t_vector	*res;
	const int	d_src[] = {1, 2, 3};
	const int	fp = *talloc_get_failpoint();

	ft_vec_ifrom_array(&v, d_src, 3, sizeof(int));
	talloc_set_failpoint(0);
	res = ft_vec_nmap(&v, 3, add42);
	talloc_set_failpoint(fp);
	ft_vec_wipe(&v);
	if (res)
		return (16);
	return (0);
}

static int	err_cases(void)
{
	t_vector	v;
	const int	d_src[] = {1, 2, 3};

	ft_vec_ifrom_array(&v, d_src, 3, sizeof(int));
	if (ft_vec_nmap(NULL, 3, add42) != NULL)
		return (ft_vec_wipe(&v), 8);
	if (ft_vec_nmap(&v, 3, NULL))
		return (ft_vec_wipe(&v), 9);
	ft_vec_wipe(&v);
	if (ft_vec_nmap(&v, 3, add42))
		return (10);
	return (mt_cases());
}

int	tv_nmap(void)
{
	t_vector	v;
	t_vector	*res;
	const int	d_src[] = {1, 2, 3};
	const int	d_exp1[] = {42 + 1, 42 + 2, 42 + 3};

	ft_vec_ifrom_array(&v, d_src, 3, sizeof(int));
	res = ft_vec_nmap(&v, 3, add42);
	if (!res || res->n_e != 3 || ft_vec_acmp(res, d_exp1, ft_cmp_int_p))
		return (ft_vec_wipe(&v), ft_vec_destroy(&res), 1);
	if (ft_vec_acmp(&v, d_src, ft_cmp_int_p))
		return (ft_vec_wipe(&v), ft_vec_destroy(&res), 2);
	return (ft_vec_wipe(&v), ft_vec_destroy(&res), err_cases());
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
