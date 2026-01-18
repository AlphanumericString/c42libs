/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_bblsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 17:02:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 17:02:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include "sys/types.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"

#include <stddef.h>
#include <stdlib.h>

static int	te_cases(void)
{
	t_arrinfo		infos;
	int				arr[FT_SMALL_BUF_SIZE];
	const ssize_t	lower = -FT_SMALL_BUF_SIZE / 2;
	const ssize_t	upper = FT_SMALL_BUF_SIZE / 2;

	randomize_iarr(arr, FT_SMALL_BUF_SIZE, lower, upper);
	infos = (t_arrinfo){.nmemb = FT_SMALL_BUF_SIZE, .sz = 0};
	ft_bblsort(arr, infos, ft_cmp_int_p, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, FT_SMALL_BUF_SIZE, sizeof(int), ft_cmp_int_p))
		return (8 + 1);
	infos = (t_arrinfo){.nmemb = 0, .sz = sizeof(int)};
	ft_bblsort(arr, infos, ft_cmp_int_p, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, FT_SMALL_BUF_SIZE, sizeof(int), ft_cmp_int_p))
		return (8 + 2);
	infos = (t_arrinfo){.nmemb = 1, .sz = sizeof(int)};
	ft_bblsort(arr, infos, ft_cmp_int_p, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, FT_SMALL_BUF_SIZE, sizeof(int), ft_cmp_int_p))
		return (8 + 3);
	infos = (t_arrinfo){.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(int)};
	ft_bblsort(arr, infos, ft_cmp_int_p, FT_SORT_ORD_UNO);
	ft_bblsort(NULL, infos, ft_cmp_int_p, FT_SORT_ORD_ASC);
	ft_bblsort(arr, infos, NULL, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, FT_SMALL_BUF_SIZE, sizeof(int), ft_cmp_int_p))
		return (8 + 4);
	return (EXIT_SUCCESS);
}

// we would optimally use FT_STD_BUF_SIZE, but it's too slow for bubble sort
// on that size...
int	talg_bblsort(void)
{
	const t_arrinfo	infos = {.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(int)};
	int				arr[FT_SMALL_BUF_SIZE];
	int				arr_tin[FT_SMALL_BUF_SIZE];
	const ssize_t	buff_by2 = infos.nmemb / 2;

	randomize_iarr(arr, infos.nmemb, -buff_by2, buff_by2);
	randomize_iarr(arr_tin, infos.nmemb, -buff_by2, buff_by2);
	ft_bblsort(arr, infos, ft_cmp_int_p, FT_SORT_ORD_ASC);
	ft_bblsort(arr_tin, infos, ft_cmp_int_p, FT_SORT_ORD_DES);
	if (!ft_is_sorted(arr, infos.nmemb, sizeof(int), ft_cmp_int_p)
		|| !ft_is_sorted(arr_tin, infos.nmemb, sizeof(int), ft_cmp_rint_p))
		return (1);
	return (te_cases());
}

int	talg_sbblsort(void)
{
	size_t	arr[FT_SMALL_BUF_SIZE];

	randomize_sarr(arr, FT_SMALL_BUF_SIZE, 0, FT_SMALL_BUF_SIZE);
	ft_sbblsort(arr, FT_SMALL_BUF_SIZE, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, FT_SMALL_BUF_SIZE, sizeof(size_t),
			(t_data_cmp)ft_cmp_szt_p))
		return (1);
	return (EXIT_SUCCESS);
}

int	talg_ssbblsort(void)
{
	ssize_t	arr[FT_SMALL_BUF_SIZE];
	ssize_t	msize;

	msize = FT_SMALL_BUF_SIZE / 2;
	randomize_ssarr(arr, FT_SMALL_BUF_SIZE, -msize, msize);
	ft_ssbblsort(arr, FT_SMALL_BUF_SIZE, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, FT_SMALL_BUF_SIZE, sizeof(ssize_t),
			(t_data_cmp)ft_cmp_sszt_p))
		return (1);
	return (EXIT_SUCCESS);
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
