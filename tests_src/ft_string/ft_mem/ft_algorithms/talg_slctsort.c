/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_slctsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 21:43:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/25 21:43:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include "ft_mem.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"
#include <stdio.h>

// 0 is swapped w 3
// 4 is swapped w 3
// array is ordered slct sort should stop there
static int	edge_cases_tests(void)
{
	const t_arrinfo	nf = {.nmemb = 5, .sz = sizeof(ssize_t)};
	const size_t	src_arr[] = {3, 1, 4, 2, 0};
	size_t			arr[5];
	int				ord;

	ft_memcpy(arr, src_arr, nf.nmemb * nf.sz);
	ord = FT_SORT_ORD_ASC;
	ft_slctsort(arr, nf, ft_cmp_szt_p, ord);
	if (!ft_is_sorted(arr, 2, nf.sz, (t_data_cmp)ft_cmp_szt_p))
		return (1 + 8);
	return (0);
}

int	talg_slctsort(void)
{
	const t_arrinfo	nf = {.nmemb = FT_MICRO_BUF_SIZE, .sz = sizeof(ssize_t)};
	size_t			arr[FT_MICRO_BUF_SIZE];
	int				ord;

	randomize_sarr(arr, nf.nmemb, 0, nf.nmemb);
	ft_slctsort(arr, nf, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, (t_data_cmp)ft_cmp_szt_p))
		return (1);
	ft_slctsort(arr, nf, ft_cmp_szt_p, FT_SORT_ORD_DES);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, (t_data_cmp)ft_cmp_rszt_p))
		return (2);
	randomize_sarr(arr, nf.nmemb, 0, nf.nmemb);
	ord = FT_SORT_ORD_DES;
	ft_slctsort(arr, nf, NULL, ord);
	ft_slctsort(NULL, nf, ft_cmp_szt_p, ord);
	ft_slctsort(arr, (t_arrinfo){.nmemb = 2, .sz = 0}, ft_cmp_szt_p, ord);
	ft_slctsort(arr, (t_arrinfo){.nmemb = 0, .sz = 1}, ft_cmp_szt_p, ord);
	ft_slctsort(arr, (t_arrinfo){.nmemb = 1, .sz = 1}, ft_cmp_szt_p, ord);
	ord = FT_SORT_ORD_UNO;
	ft_slctsort(arr, nf, ft_cmp_szt_p, ord);
	if (ft_is_sorted(arr, nf.nmemb, nf.sz, (t_data_cmp)ft_cmp_rszt_p))
		return (3);
	return (edge_cases_tests());
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
