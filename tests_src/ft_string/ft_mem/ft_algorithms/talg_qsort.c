/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:20:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_algorithms.h"
#include "tests/tests_lambda_functions.h"
#include "tests/str__mem_tests.h"
#include <stdlib.h>

#define NB_TESTS 100

static int	tm_set(void)
{
	const t_arrinfo	infos = {.nmemb = FT_STD_BUF_SIZE, .sz = sizeof(int)};
	int				ar_out[FT_STD_BUF_SIZE];

	randomize_iarr(ar_out, infos.nmemb, 0, infos.nmemb * 2);
	ft_qsort(ar_out, infos.nmemb, infos.sz, ft_cmp_int_p);
	if (!ft_is_sorted(ar_out, infos.nmemb, infos.sz, ft_cmp_int_p))
		return (1);
	return (EXIT_SUCCESS);
}

int	talg_qsort(void)
{
	int	ar_err[3];
	int	i;

	i = 0;
	while (i++ < NB_TESTS)
		if (tm_set() == 1)
			return (1);
	ft_qsort(ar_err, 0, sizeof(int), (t_data_cmp)ft_cmp_int_p);
	ft_qsort(ar_err, 3, 0, (t_data_cmp)ft_cmp_int_p);
	ft_qsort(ar_err, 1, sizeof(int), (t_data_cmp)ft_cmp_int_p);
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
