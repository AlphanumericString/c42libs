/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_acpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:14:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/13 21:28:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_defs.h"
#include "ft_arr.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

int	tca_acpy(void)
{
	t_arr			dst;
	const char		*src[] = {"hello", "world", NULL};

	dst = ft_malloc(sizeof(char *) * 4);
	ft_acpy((t_iconst_arr)dst, (t_const_arr)src);
	if (ft_acmp((t_const_arr)dst, (t_const_arr)src) != 0)
		return (1);
	ft_acpy(NULL, (t_const_arr)src);
	ft_acpy((t_iconst_arr)dst, NULL);
	ft_free(dst);
	return (EXIT_SUCCESS);
}

int	tca_alcpy(void)
{
	t_arr			dst;
	const char		*src[] = {"hello", "world", NULL};

	dst = ft_malloc(sizeof(char *) * 4);
	ft_alcpy((t_iconst_arr)dst, 4, (t_const_arr)src);
	if (ft_acmp((t_const_arr)dst, (t_const_arr)src) != 0)
		return (1);
	ft_alcpy((t_iconst_arr)dst, 2, (t_const_arr)src);
	if (ft_strcmp(dst[0], src[0]) != 0)
		return (2);
	ft_alcpy((t_iconst_arr)dst, 0, (t_const_arr)src);
	ft_alcpy(NULL, 4, (t_const_arr)src);
	ft_alcpy((t_iconst_arr)dst, 0, NULL);
	ft_free(dst);
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
