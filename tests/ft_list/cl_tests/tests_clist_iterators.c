/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_iterators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 14:25:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

int	t_cl_at(void)
{
	t_clist	*lst;
	t_clist	*node;

	lst = NULL;
	// Test with NULL list
	node = ft_cl_at(NULL, 0);
	if (node != NULL)
		return (1);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	node = ft_cl_at(lst, 0);
	if (!node || node->data != (void *)42)
		return (3);
	node = ft_cl_at(lst, 1);
	if (node != NULL)
		return (4);
	node = ft_cl_at(lst, -1);
	if (node != NULL)
		return (5);
	// Test with multiple nodes
	ft_cl_push_back(&lst, (void *)43);
	ft_cl_push_back(&lst, (void *)44);
	node = ft_cl_at(lst, 0);
	if (!node || node->data != (void *)42)
		return (6);
	node = ft_cl_at(lst, 1);
	if (!node || node->data != (void *)43)
		return (7);
	node = ft_cl_at(lst, 2);
	if (!node || node->data != (void *)44)
		return (8);
	node = ft_cl_at(lst, -1);
	if (!node || node->data != (void *)44)
		return (9);
	node = ft_cl_at(lst, -2);
	if (!node || node->data != (void *)43)
		return (10);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	t_cl_begin(void)
{
	t_clist	*lst;
	t_clist	*begin;

	lst = NULL;
	// Test with NULL list
	begin = ft_cl_begin(NULL);
	if (begin != NULL)
		return (1);
	// Test with valid list
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	begin = ft_cl_begin(lst);
	if (!begin || begin != lst)
		return (3);
	// Test with multiple nodes
	ft_cl_push_back(&lst, (void *)43);
	begin = ft_cl_begin(lst);
	if (!begin || begin != lst)
		return (4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	t_cl_end(void)
{
	t_clist	*lst;
	t_clist	*end;

	lst = NULL;
	// Test with NULL list
	end = ft_cl_end(NULL);
	if (end != NULL)
		return (1);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	end = ft_cl_end(lst);
	if (!end || end != lst)
		return (3);
	// Test with multiple nodes
	ft_cl_push_back(&lst, (void *)43);
	ft_cl_push_back(&lst, (void *)44);
	end = ft_cl_end(lst);
	if (!end || end->data != (void *)44 || end != lst->prev)
		return (4);
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
