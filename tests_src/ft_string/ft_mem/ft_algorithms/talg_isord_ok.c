/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_isord_ok.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 16:17:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/26 16:17:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_algorithms.h"
#include "internal/algo_util.h"
#include "tests/str__mem_tests.h"

int	talg_isord_ok(void)
{
	const size_t	arr[4] = {0, 1, 3, 2};

	if (ft_isord_ok(FT_SORT_ORD_ASC, ft_cmp_szt_p(&arr[2], &arr[3])) != false)
		return (1);
	if (ft_isord_ok(FT_SORT_ORD_DES, ft_cmp_szt_p(&arr[1], &arr[2])) != false)
		return (2);
	if (ft_isord_ok(FT_SORT_ORD_DES, ft_cmp_szt_p(&arr[2], &arr[3])) != true)
		return (3);
	if (ft_isord_ok(FT_SORT_ORD_ASC, ft_cmp_szt_p(&arr[1], &arr[2])) != true)
		return (4);
	if (!ft_isord_ok(FT_SORT_ORD_UNO, ft_cmp_szt_p(&arr[1], &arr[2]))
		|| !ft_isord_ok(FT_SORT_ORD_UNO, ft_cmp_szt_p(&arr[2], &arr[3]))
		|| !ft_isord_ok(FT_SORT_ORD_UNO, -12)
		|| !ft_isord_ok(FT_SORT_ORD_UNO, 0)
		|| !ft_isord_ok(FT_SORT_ORD_UNO, 12))
		return (5);
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
