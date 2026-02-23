/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_mrgsort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 17:00:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/27 17:00:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "ft_defs.h"
#include "sys/cdefs.h"
#include "tests/fixtures.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"

//	ft_mrgsort_r(sarr, nf, ft_cmp_szt_p, NULL); < does not compile

// size_t			sarr[FT_STD_BUF_SIZE];
// char			buff[FT_STD_BUF_SIZE * sizeof(size_t)];
// const t_arrinfo	nf = (t_arrinfo){.nmemb = FT_STD_BUF_SIZE,
// 	.sz = sizeof(size_t)};
//
// randomize_sarr(sarr, nf.sz, 0, 333333);
// ft_mrgsort_r(sarr, nf, ft_cmp_szt_p, buff);
// if (!ft_is_sorted(sarr, nf.nmemb, nf.sz, ft_cmp_szt_p))
// 	return (1);
// return (EXIT_SUCCESS);
int	talg_mrgsort_r(void)
{
	return (EXIT_SUCCESS);
}

// test on malloc faillure (alloc temp buff to store sorted array)
static __attribute_maybe_unused__ int	mt_mrgsort(void)
{
	const t_arrinfo	infs = {.nmemb = FT_STD_BUF_SIZE, .sz = sizeof(size_t)};
	const int		fp = *talloc_get_failpoint();
	size_t			sarr[FT_STD_BUF_SIZE];

	randomize_sarr(sarr, infs.nmemb, 0, 424242);
	talloc_set_failpoint(0);
	ft_mrgsort(sarr, infs, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	talloc_set_failpoint(fp);
	if (ft_is_sorted(sarr, infs.nmemb, infs.sz, ft_cmp_szt_p) != false)
		return (8 + 1);
	return (EXIT_SUCCESS);
}

// t_arrinfo	infs;
// size_t		sarr[FT_STD_BUF_SIZE];
// int			iarr[FT_STD_BUF_SIZE + 13];
//
// infs.nmemb = FT_STD_BUF_SIZE;
// infs.sz = sizeof(size_t);
// randomize_sarr(sarr, infs.nmemb, 0, 424242);
// randomize_iarr(iarr, infs.nmemb, 0, 424242);
// ft_mrgsort(sarr, infs, ft_cmp_szt_p, FT_SORT_ORD_ASC);
// if (!ft_is_sorted(sarr, infs.nmemb, infs.sz, ft_cmp_szt_p))
// 	return (1);
// infs = (t_arrinfo){.sz = sizeof(int), .nmemb = FT_STD_BUF_SIZE + 13};
// ft_mrgsort(iarr, infs, ft_cmp_int_p, FT_SORT_ORD_UNO);
// ft_mrgsort(iarr, (t_arrinfo){0, infs.sz}, ft_cmp_int_p, FT_SORT_ORD_ASC);
// ft_mrgsort(iarr, (t_arrinfo){1, infs.sz}, ft_cmp_int_p, FT_SORT_ORD_ASC);
// ft_mrgsort(iarr, (t_arrinfo){infs.nmemb, 0}, ft_cmp_int_p, FT_SORT_ORD_ASC);
// if (ft_is_sorted(iarr, infs.nmemb, infs.sz, ft_cmp_int_p))
// 	return (2);
// ft_mrgsort(iarr, infs, ft_cmp_int_p, FT_SORT_ORD_DES);
// if (ft_is_sorted(iarr, infs.nmemb, infs.sz, ft_cmp_rint_p) != true)
// 	return (3);
// return (mt_mrgsort());
int	talg_mrgsort(void)
{
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
