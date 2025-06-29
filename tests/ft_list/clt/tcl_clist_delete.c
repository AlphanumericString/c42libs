/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_delete.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:11 by bgoulard         ###   ########.fr       */
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

int	tcl_delete(void)
{
	t_clist	*lst;
	size_t	deleted;

	lst = NULL;
	// Test with NULL list
	deleted = ft_cl_delete(&lst, NULL);
	if (deleted != 0 || lst != NULL)
		return (1);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	deleted = ft_cl_delete(&lst, NULL);
	if (deleted != 1 || lst != NULL)
		return (3);
	// Test with multiple nodes
	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	ft_cl_push(&lst, (void *)2);
	ft_cl_push(&lst, (void *)3);
	deleted = ft_cl_delete(&lst, NULL);
	if (deleted != 3 || lst != NULL)
		return (4);
	// Test with delete function
	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	ft_cl_push(&lst, (void *)2);
	deleted = ft_cl_delete(&lst, del_data);
	if (deleted != 2 || lst != NULL)
		return (5);
	return (EXIT_SUCCESS);
}

int	tcl_delete_range(void)
{
	t_clist	*lst;
	size_t	deleted;

	lst = NULL;
	// Test with NULL start
	deleted = ft_cl_delete_range(NULL, NULL, NULL);
	if (deleted != 0)
		return (1);
	lst = ft_cl_create((void *)1);
	ft_cl_push_back(&lst, (void *)2);
	ft_cl_push_back(&lst, (void *)3);
	if (!lst)
		return (2);
	deleted = ft_cl_delete_range(lst->next, NULL, NULL);
	if (deleted != 0)
		return (3);
	deleted = ft_cl_delete_range(lst->next, lst->prev, NULL);
	if (deleted != 2 || lst->next != lst || lst->prev != lst)
		return (4);
	ft_cl_push_back(&lst, (void *)4);
	ft_cl_push_back(&lst, (void *)5);
	deleted = ft_cl_delete_range(lst->next, lst->prev, del_data);
	if (deleted != 2 || lst->next != lst || lst->prev != lst)
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
