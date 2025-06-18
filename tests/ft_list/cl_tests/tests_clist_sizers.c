/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_sizers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 12:58:25 by bgoulard         ###   ########.fr       */
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

int	t_cl_size(void)
{
	t_clist	*lst;
	size_t	size;

	lst = NULL;
	// Test with NULL list
	size = ft_cl_size(NULL);
	if (size != 0)
		return (1);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	size = ft_cl_size(lst);
	if (size != 1)
		return (3);
	// Test with multiple nodes
	ft_cl_push(&lst, (void *)43);
	ft_cl_push(&lst, (void *)44);
	size = ft_cl_size(lst);
	if (size != 3)
		return (4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	t_cl_size_data_is(void)
{
	t_clist	*lst;
	size_t	size;

	lst = NULL;
	// Test with NULL list
	size = ft_cl_size_data_is(NULL, is_even);
	if (size != 0)
		return (1);
	// Test with single node - even
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	size = ft_cl_size_data_is(lst, is_even);
	if (size != 1)
		return (3);
	// Test with single node - odd
	ft_cl_delete(&lst, NULL);
	lst = ft_cl_create((void *)43);
	if (!lst)
		return (4);
	size = ft_cl_size_data_is(lst, is_even);
	if (size != 0)
		return (5);
	// Test with multiple nodes
	ft_cl_push(&lst, (void *)44);
	ft_cl_push(&lst, (void *)45);
	ft_cl_push(&lst, (void *)46);
	size = ft_cl_size_data_is(lst, is_even);
	if (size != 2)
		return (6);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	t_cl_size_cmp(void)
{
	t_clist	*lst;
	size_t	size;

	lst = NULL;
	// Test with NULL list
	size = ft_cl_size_cmp(NULL, (void *)42, cmp_data);
	if (size != 0)
		return (1);
	// Test with single node - match
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	size = ft_cl_size_cmp(lst, (void *)42, cmp_data);
	if (size != 1)
		return (3);
	// Test with single node - no match
	size = ft_cl_size_cmp(lst, (void *)43, cmp_data);
	if (size != 0)
		return (4);
	// Test with multiple nodes
	ft_cl_push(&lst, (void *)42);
	ft_cl_push(&lst, (void *)43);
	ft_cl_push(&lst, (void *)42);
	size = ft_cl_size_cmp(lst, (void *)42, cmp_data);
	if (size != 3)
		return (5);
	size = ft_cl_size_cmp(lst, (void *)43, cmp_data);
	if (size != 1)
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
