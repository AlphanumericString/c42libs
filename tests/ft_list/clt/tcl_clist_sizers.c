/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_sizers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

static bool	is_even(const void *data)
{
	return (((long)data % 2) == 0);
}

static int	cmp_data(const void *data1, const void *data2)
{
	return ((long)data1 - (long)data2);
}

int	tcl_size(void)
{
	t_clist	*lst;

	if (ft_cl_size(NULL) != 0)
		return (1);
	lst = ft_cl_create((void *)42);
	if (ft_cl_size(lst) != 1)
		return (3);
	ft_cl_push(&lst, (void *)43);
	ft_cl_push(&lst, (void *)44);
	if (ft_cl_size(lst) != 3)
		return (4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_size_data_is(void)
{
	t_clist	*lst;

	if (ft_cl_size_data_is(NULL, is_even) != 0)
		return (1);
	lst = ft_cl_create((void *)42);
	if (ft_cl_size_data_is(lst, is_even) != 1)
		return (ft_cl_delete(&lst, NULL), 2);
	ft_cl_delete(&lst, NULL);
	lst = ft_cl_create((void *)43);
	if (ft_cl_size_data_is(lst, is_even) != 0)
		return (5);
	(ft_cl_push(&lst, (void *)44), ft_cl_push(&lst, (void *)45));
	ft_cl_push(&lst, (void *)46);
	if (ft_cl_size_data_is(lst, is_even) != 2)
		return (6);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_size_cmp(void)
{
	t_clist	*lst;

	if (ft_cl_size_cmp(NULL, (void *)42, cmp_data) != 0)
		return (1);
	lst = ft_cl_create((void *)42);
	if (ft_cl_size_cmp(lst, (void *)42, cmp_data) != 1)
		return (3);
	if (ft_cl_size_cmp(lst, (void *)43, cmp_data) != 0)
		return (4);
	(ft_cl_push(&lst, (void *)42), ft_cl_push(&lst, (void *)43));
	ft_cl_push(&lst, (void *)42);
	if (ft_cl_size_cmp(lst, (void *)42, cmp_data) != 3)
		return (5);
	if (ft_cl_size_cmp(lst, (void *)43, cmp_data) != 1)
		return (6);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
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
