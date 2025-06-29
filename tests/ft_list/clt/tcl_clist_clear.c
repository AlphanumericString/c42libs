/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

static void	del_data(void *data)
{
	// Simple delete function for testing
	(void)data;
}
//
// static void	clnode_print(t_clist *node)
// {
// 	printf("%p(%ld)\t%p(%ld)\t%p(%ld)\n",
// 		node->prev, (long)node->prev->data,
// 		node, (long)node->data,
// 		node->next, (long)node->next->data);
// }

int	tcl_clear(void)
{
	t_clist	*lst;
	size_t	size;

	lst = NULL;
	// Test with NULL list
	size = ft_cl_clear(&lst, NULL);
	if (size != 0 || lst != NULL)
		return (1);
	// Test with empty list
	lst = ft_cl_new();
	if (!lst)
		return (2);
	size = ft_cl_clear(&lst, NULL);
	if (size != 1 || lst == NULL || lst->data != NULL)
		return (3);
	ft_cl_delete(&lst, NULL);
	// Test with populated list
	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	ft_cl_push(&lst, (void *)2);
	ft_cl_push(&lst, (void *)3);
	size = ft_cl_clear(&lst, NULL);
	if (size != 3 || lst == NULL || lst->data != NULL
	|| lst->next->data != NULL || lst->prev->data != NULL)
		return (4);
	ft_cl_delete(&lst, NULL);
	// Test with delete function
	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	ft_cl_push(&lst, (void *)2);
	size = ft_cl_clear(&lst, del_data);
	if (size != 2 || lst == NULL || lst->data != NULL)
		return (5);
	ft_cl_delete(&lst, NULL);
	return (EXIT_SUCCESS);
}

int	tcl_clear_range(void)
{
	t_clist	*lst;
	t_clist	*start;
	t_clist	*end;
	size_t	size;

	lst = NULL;
	// Test with NULL start
	size = ft_cl_clear_range(NULL, NULL, NULL);
	if (size != 0)
		return (1);
	// Test with single node
	lst = ft_cl_new();
	if (!lst)
		return (2);
	size = ft_cl_clear_range(lst, NULL, NULL);
	if (size != 1)
		return (3);
	ft_cl_delete(&lst, NULL);
	// Test with multiple nodes
	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	ft_cl_push(&lst, (void *)2);
	ft_cl_push(&lst, (void *)3);
	ft_cl_push(&lst, (void *)4);
	start = lst->next;
	end = lst->prev;
	size = ft_cl_clear_range(start, end, NULL);
	if (size != 2)
		return (4);
	ft_cl_delete(&lst, NULL);
	// Test with delete function
	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	ft_cl_push(&lst, (void *)2);
	ft_cl_push(&lst, (void *)3);
	size = ft_cl_clear_range(lst, lst->next, del_data);
	if (size != 1 || lst == NULL || lst->data != NULL)
		return (5);
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
