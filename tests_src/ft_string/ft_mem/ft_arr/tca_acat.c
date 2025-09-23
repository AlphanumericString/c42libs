/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_acat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

#include <stdlib.h>
#include <string.h>

int	tca_acat(void)
{
	size_t		i;
	const int	*arr[42] = {
		(int *)1, (int *)2, (int *)3, (int *)4, (int *)5, NULL};
	const int	*arr2[] = {
		(int *)10, (int *)20, (int *)30, (int *)40, (int *)50, NULL};

	ft_acat((t_iconst_arr)arr, (t_const_arr)arr2);
	if (ft_alen((t_const_arr)arr) != 10)
		return (1);
	i = 0;
	while (i < 10)
	{
		if ((i < 5 && arr[i] != (int *)(i + 1))
			|| (i >= 5 && arr[i] != (int *)((i + 1 - 5) * 10)))
			return (2);
		i++;
	}
	return (EXIT_SUCCESS);
}

int	tca_alcat(void)
{
	t_arr			dst;
	const char		*src[] = {"hello", "world", NULL};

	dst = ft_calloc(sizeof(char *), 4);
	ft_alcat((t_iconst_arr)dst, 4, (t_const_arr)src);
	if (ft_acmp((t_const_arr)dst, (t_const_arr)src) != 0)
		return (1);
	ft_alcat((t_iconst_arr)dst, 2, (t_const_arr)src);
	if (ft_strcmp(dst[0], src[0]) != 0
		|| ft_alen((t_const_arr)dst) != 2)
		return (2);
	dst[0] = NULL;
	ft_alcat((t_iconst_arr)dst, 4, (t_const_arr)src);
	ft_alcat((t_iconst_arr)dst, 4, (t_const_arr)src);
	if (ft_strcmp(dst[0], src[0]) != 0
		|| ft_strcmp(dst[1], src[1]) != 0 || ft_strcmp(dst[2], src[0]) != 0
		|| dst[3] != NULL || ft_alen((t_const_arr)dst) != 3)
		return (3);
	ft_alcat((t_iconst_arr)dst, 0, (t_const_arr)src);
	ft_alcat(NULL, 4, (t_const_arr)src);
	ft_alcat((t_iconst_arr)dst, 4, NULL);
	return (ft_free(dst), 0);
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
