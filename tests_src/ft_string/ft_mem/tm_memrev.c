/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_memrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/22 15:21:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/29 11:31:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_algorithms.h"
#include "tests/str__mem_tests.h"
#include <stdio.h>
#include <stdlib.h>

int	tm_memrev(void)
{
	const t_arrinfo	inf = {.nmemb = FT_MICRO_BUF_SIZE, .sz = sizeof(char)};
	char			arr[FT_MICRO_BUF_SIZE];
	size_t			off;
	char			i;

	i = 0;
	off = 0;
	while (off < inf.nmemb)
		arr[off++] = i++;
	ft_memrev(arr, inf.nmemb);
	off = 0;
	i = 0;
	while (off < inf.nmemb)
		if (arr[off++] != (char)inf.nmemb - 1 - i++)
			return (1);
	ft_memrev(arr, 1);
	ft_memrev(arr, 0);
	off = 0;
	i = 0;
	while (off < inf.nmemb)
		if (arr[off++] != (char)inf.nmemb - 1 - i++)
			return (1);
	return (EXIT_SUCCESS);
}

int	tm_memnrev(void)
{
	const int		arr_src[5] = {1, 2, 3, 4, 5};
	int				arr[2][5];

	ft_memcpy(arr[0], arr_src, sizeof(arr_src));
	ft_memcpy(arr[1], arr_src, sizeof(arr_src));
	ft_memnrev(arr[0], 3, sizeof(int));
	if (arr[0][0] != 3 || arr[0][1] != 2 || arr[0][2] != 1)
		return (1);
	ft_memnrev(arr[0], 5, sizeof(int));
	if (arr[0][0] != 5 || arr[0][1] != 4 || arr[0][2] != 1
		|| arr[0][3] != 2 || arr[0][4] != 3)
		return (2);
	ft_memnrev(arr[1], 1, sizeof(int));
	ft_memnrev(arr[1], 5, 0);
	if (ft_memcmp(arr[1], arr_src, sizeof(arr_src)) != 0)
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
