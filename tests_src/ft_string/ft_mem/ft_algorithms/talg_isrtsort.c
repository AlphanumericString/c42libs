/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_isrtsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:46:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 16:46:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include "tests/fixtures.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"

static int	mt_isrtsort(void)
{
	const t_arrinfo	infos = {.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(int)};
	const int		fp = *talloc_get_failpoint();
	int				arr[FT_SMALL_BUF_SIZE];
	int				ret;

	ret = EXIT_SUCCESS;
	randomize_iarr(arr, infos.nmemb, 0, FT_SMALL_BUF_SIZE);
	talloc_set_failpoint(0);
	ft_isrtsort(arr, infos, (t_data_cmp)ft_cmp_int_p, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, infos.nmemb, infos.sz, ft_cmp_int_p))
		ret = 1 + 8;
	talloc_set_failpoint(fp);
	return (ret);
}

int	talg_isrtsort(void)
{
	const t_arrinfo	infos = {.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(int)};
	int				arr[FT_SMALL_BUF_SIZE];

	randomize_iarr(arr, infos.nmemb, 0, FT_SMALL_BUF_SIZE);
	ft_isrtsort(arr, infos, (t_data_cmp)ft_cmp_int_p, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, infos.nmemb, infos.sz, ft_cmp_int_p))
		return (1);
	randomize_iarr(arr, infos.nmemb, 0, FT_SMALL_BUF_SIZE);
	ft_isrtsort(arr, (t_arrinfo){0, infos.sz}, ft_cmp_rint_p,
		FT_SORT_ORD_DES);
	ft_isrtsort(arr, (t_arrinfo){infos.nmemb, 0}, ft_cmp_rint_p,
		FT_SORT_ORD_DES);
	ft_isrtsort(arr, infos, ft_cmp_rint_p, FT_SORT_ORD_UNO);
	ft_isrtsort(NULL, infos, ft_cmp_rint_p, FT_SORT_ORD_ASC);
	ft_isrtsort(arr, infos, NULL, FT_SORT_ORD_ASC);
	if (ft_is_sorted(arr, infos.nmemb, infos.sz, ft_cmp_int_p))
		return (2);
	randomize_iarr(arr, infos.nmemb, 0, FT_SMALL_BUF_SIZE);
	ft_isrtsort(arr, infos, ft_cmp_rint_p, FT_SORT_ORD_DES);
	if (!ft_is_sorted(arr, infos.nmemb, infos.sz, ft_cmp_int_p))
		return (3);
	return (mt_isrtsort());
}

int	talg_sisrtsort(void)
{
	const t_arrinfo	nf = {.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(ssize_t)};
	size_t			arr[FT_SMALL_BUF_SIZE];

	randomize_sarr(arr, nf.nmemb, 0, FT_SMALL_BUF_SIZE);
	ft_sisrtsort(arr, nf.nmemb, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, (t_data_cmp)ft_cmp_szt_p))
		return (1);
	return (EXIT_SUCCESS);
}

int	talg_ssisrtsort(void)
{
	const t_arrinfo	nf = {.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(ssize_t)};
	ssize_t			arr[FT_SMALL_BUF_SIZE];

	randomize_ssarr(arr, nf.nmemb, -FT_SMALL_BUF_SIZE / 2,
		FT_SMALL_BUF_SIZE / 2);
	ft_ssisrtsort(arr, nf.nmemb, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, (t_data_cmp)ft_cmp_sszt_p))
		return (1);
	return (EXIT_SUCCESS);
}

int	talg_isrtsort_b(void)
{
	const t_arrinfo	nf = {.nmemb = FT_SMALL_BUF_SIZE, .sz = sizeof(int)};
	int				arr[FT_SMALL_BUF_SIZE];
	int				buff;

	randomize_iarr(arr, nf.nmemb, 0, FT_SMALL_BUF_SIZE);
	ft_isrtsort_b(arr, nf, ft_cmp_int_p, &buff);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, ft_cmp_int_p))
		return (1);
	randomize_iarr(arr, nf.nmemb, 0, FT_SMALL_BUF_SIZE);
	ft_isrtsort_b(arr, (t_arrinfo){nf.nmemb, 0}, ft_cmp_int_p, &buff);
	ft_isrtsort_b(arr, (t_arrinfo){0, nf.sz}, ft_cmp_int_p, &buff);
	ft_isrtsort_b(arr, (t_arrinfo){1, nf.sz}, ft_cmp_int_p, &buff);
	ft_isrtsort_b(NULL, nf, ft_cmp_int_p, &buff);
	ft_isrtsort_b(arr, nf, NULL, &buff);
	if (ft_is_sorted(arr, nf.nmemb, nf.sz, ft_cmp_int_p))
		return (2);
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
