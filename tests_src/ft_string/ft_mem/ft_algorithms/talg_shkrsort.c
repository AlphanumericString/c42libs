/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_shkrsort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:22:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/26 16:22:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"

#include <stdio.h>

int	talg_shkrsort(void)
{
	const t_arrinfo	nf = (t_arrinfo){FT_STD_BUF_SIZE, sizeof(size_t)};
	size_t			arr[FT_STD_BUF_SIZE];

	if (nf.nmemb != FT_STD_BUF_SIZE || nf.sz != sizeof(arr[0]))
		return (1);
	randomize_sarr(arr, nf.nmemb, 0, 4242);
	ft_shkrsort(arr, (t_arrinfo){0, 32}, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	ft_shkrsort(arr, (t_arrinfo){1, 32}, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	ft_shkrsort(arr, (t_arrinfo){nf.nmemb, 0}, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	ft_shkrsort(arr, nf, NULL, FT_SORT_ORD_ASC);
	ft_shkrsort(NULL, nf, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	ft_shkrsort(arr, nf, ft_cmp_szt_p, FT_SORT_ORD_UNO);
	if (ft_is_sorted(arr, nf.nmemb, nf.sz, ft_cmp_szt_p))
		return (2);
	ft_shkrsort(arr, nf, ft_cmp_szt_p, FT_SORT_ORD_ASC);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, ft_cmp_szt_p))
		return (2);
	randomize_sarr(arr, nf.nmemb, 0, 4242);
	ft_shkrsort(arr, nf, ft_cmp_szt_p, FT_SORT_ORD_DES);
	if (!ft_is_sorted(arr, nf.nmemb, nf.sz, ft_cmp_rszt_p))
		return (3);
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
