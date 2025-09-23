/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_binsrch.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 16:08:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 16:08:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_sort.h"
#include "tests/str__mem_tests.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

int	talg_binsrch(void)
{
	const t_arrinfo	infos = {FT_STD_BUF_SIZE, sizeof(int)};
	int				arr[FT_STD_BUF_SIZE];
	int				nb_tries;
	int				target;
	int				i;

	randomize_iarr(arr, infos.n_ele, 0, infos.n_ele);
	ft_qsort(arr, infos.n_ele, infos.ele_s, ft_cmp_int_p);
	nb_tries = 16;
	while (nb_tries-- > 0)
	{
		target = rand() % FT_STD_BUF_SIZE;
		i = ft_binsrch(arr, infos, &arr[target], ft_cmp_int_p);
		if (arr[i] != arr[target])
			return (16 - nb_tries + 1);
	}
	i = ft_binsrch(arr, (t_arrinfo){0}, &target, ft_cmp_int_p);
	if (i != 0)
		return (16 + 2);
	i += ft_binsrch(arr, (t_arrinfo){infos.n_ele, 0}, &target, ft_cmp_int_p);
	i += ft_binsrch(arr, (t_arrinfo){0, infos.ele_s}, &target, ft_cmp_int_p);
	if (i != 0)
		return (16 + 3);
	return (0);
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
