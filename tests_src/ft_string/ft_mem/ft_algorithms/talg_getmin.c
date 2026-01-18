/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talg_getmin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 05:12:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/26 05:12:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_defs.h"
#include "ft_algorithms.h"
#include "tests/tests_lambda_functions.h"
#include "tests/str__mem_tests.h"

int	talg_getmin(void)
{
	size_t			arr[FT_STD_BUF_SIZE];
	const t_arrinfo	infos = {.sz = sizeof(*arr), .nmemb = FT_STD_BUF_SIZE};
	const void		*elem;
	size_t			pos;

	randomize_sarr(arr, FT_STD_BUF_SIZE, 1, 4242);
	pos = rand() % infos.nmemb;
	arr[pos] = 0;
	elem = ft_getmin(arr, infos, ft_cmp_szt_p);
	if (elem != &arr[pos])
		return (1);
	if (ft_getmin(arr, (t_arrinfo){.nmemb = 1, 0}, ft_cmp_szt_p) != NULL)
		return (2);
	if (ft_getmin(arr, (t_arrinfo){.nmemb = 0, 1}, ft_cmp_szt_p) != NULL)
		return (3);
	if (ft_getmin(NULL, infos, ft_cmp_szt_p) != NULL)
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
