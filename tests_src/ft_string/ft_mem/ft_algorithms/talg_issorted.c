/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_issorted.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:41:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 16:41:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_algorithms.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	talg_issorted(void)
{
	const t_arrinfo	infos = {.nmemb = FT_STD_BUF_SIZE, .sz = sizeof(int)};
	int				arr[FT_STD_BUF_SIZE];
	int				arr_uno[FT_STD_BUF_SIZE];

	randomize_iarr(arr, infos.nmemb, 0, infos.nmemb);
	ft_memcpy(arr_uno, arr, infos.nmemb * infos.sz);
	ft_qsort(arr, infos.nmemb, infos.sz, ft_cmp_int_p);
	if (!ft_is_sorted(arr, infos.nmemb, infos.sz, ft_cmp_int_p))
		return (1);
	if (ft_is_sorted(arr_uno, infos.nmemb, infos.sz, ft_cmp_int_p))
		return (2);
	if (!ft_is_sorted(arr, 1, infos.sz, ft_cmp_int_p)
		|| !ft_is_sorted(arr, 0, infos.sz, ft_cmp_int_p)
		|| !ft_is_sorted(arr, infos.nmemb, 0, ft_cmp_int_p))
		return (3);
	if (ft_is_sorted(NULL, infos.nmemb, infos.sz, ft_cmp_int_p) != true
		|| ft_is_sorted(arr, infos.nmemb, infos.sz, NULL) != true)
		return (4);
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
