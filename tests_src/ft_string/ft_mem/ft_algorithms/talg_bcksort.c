/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_bcksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 20:56:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 20:56:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_math.h"
#include "ft_sort.h"
#include "tests/fixtures.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

static int	mt_sbcksrt(void)
{
	const int		fp = *talloc_get_failpoint();
	const t_arrinfo	infos = {.n_ele = FT_STD_BUF_SIZE, .ele_s = sizeof(size_t)};
	size_t			arr[FT_STD_BUF_SIZE];
	int				ret;
	const int		k = ft_ullogof(infos.n_ele, 10) + 1;

	ret = EXIT_SUCCESS;
	randomize_sarr(arr, infos.n_ele, 0, infos.n_ele);
	talloc_set_failpoint(0);
	ft_sbcksort(arr, infos.n_ele, FT_SORT_ORD_ASC);
	talloc_set_failpoint(*talloc_get_currentpoint() + (k + 1));
	ft_sbcksort(arr, infos.n_ele, FT_SORT_ORD_ASC);
	talloc_set_failpoint(fp);
	if (ft_is_sorted(arr, infos.n_ele, infos.ele_s, (t_data_cmp)ft_cmp_szt_p))
		ret = 1 + 8;
	return (ret);
}

int	talg_sbcksort(void)
{
	const t_arrinfo	infos = {.n_ele = FT_STD_BUF_SIZE, .ele_s = sizeof(size_t)};
	size_t			arr[FT_STD_BUF_SIZE];

	randomize_sarr(arr, infos.n_ele, 0, infos.n_ele);
	ft_sbcksort(arr, infos.n_ele, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, infos.n_ele, infos.ele_s, (t_data_cmp)ft_cmp_szt_p))
		return (1);
	randomize_sarr(arr, infos.n_ele, 0, infos.n_ele);
	arr[rand() % infos.n_ele] = FT_SIZE_MAX;
	ft_sbcksort(arr, infos.n_ele, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, infos.n_ele, infos.ele_s, (t_data_cmp)ft_cmp_szt_p))
		return (2);
	randomize_sarr(arr, infos.n_ele, 0, infos.n_ele);
	ft_sbcksort(arr, 0, FT_SORT_ORD_ASC);
	ft_sbcksort(arr, 1, FT_SORT_ORD_ASC);
	ft_sbcksort(arr, 2, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, infos.n_ele, infos.ele_s, (t_data_cmp)ft_cmp_szt_p))
		return (3);
	return (mt_sbcksrt());
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
