/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:48:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

static int	mt_cl_copy_list(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*original;
	t_clist		*copy;
	size_t		i;

	i = 0;
	original = NULL;
	while (i < 10)
		ft_cl_push(&original, (void *)(long)i++);
	if (!original || ft_cl_size(original) != 10)
		return (1);
	talloc_set_failpoint(0);
	copy = ft_cl_copy_list(original);
	if (copy != NULL)
		return (2);
	talloc_set_failpoint(fp);
	ft_cl_delete(&original, NULL);
	return (EXIT_SUCCESS);
}

static int	mt_cl_copy_node(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*node1;
	t_clist		*node;

	node1 = ft_cl_create(&mt_cl_copy_node);
	talloc_set_failpoint(0);
	node = ft_cl_copy_node(node1);
	if (node)
		return (1);
	talloc_set_failpoint(fp);
	ft_free(node1);
	return (EXIT_SUCCESS);
}

static int	mt_cl_create(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist	*node;

	talloc_set_failpoint(0);
	node = ft_cl_create(NULL);
	if (node)
		return (1);
	talloc_set_failpoint(fp);
	return (EXIT_SUCCESS);
}

int	tcl_create(void)
{
	t_clist	*node;

	// Test with NULL data
	node = ft_cl_create(NULL);
	if (!node || node->data != NULL || node->next != node || node->prev != node)
		return (1);
	ft_free(node);
	// Test with valid data
	node = ft_cl_create((void *)42);
	if (!node || node->data != (void *)42 || node->next != node || node->prev != node)
		return (2);
	ft_free(node);
	return (mt_cl_create());
}

int	tcl_copy_node(void)
{
	t_clist	*original;
	t_clist	*copy;

	// Test with NULL
	copy = ft_cl_copy_node(NULL);
	if (copy != NULL)
		return (1);
	// Test with valid node
	original = ft_cl_create((void *)42);
	if (!original)
		return (2);
	copy = ft_cl_copy_node(original);
	if (!copy || copy->data != original->data || copy->next != original->next || copy->prev != original->prev)
		return (3);
	ft_free(original);
	ft_free(copy);
	return (mt_cl_copy_node());
}

int	tcl_copy_list(void)
{
	t_clist	*original;
	t_clist	*copy;
	t_clist	*orig_it;
	t_clist	*copy_it;

	// Test with NULL
	copy = ft_cl_copy_list(NULL);
	if (copy != NULL)
		return (1);
	// Test with single node
	original = ft_cl_create((void *)42);
	if (!original)
		return (2);
	copy = ft_cl_copy_list(original);
	if (!copy || copy->data != original->data)
		return (3);
	ft_free_clear((void **)&original);
	ft_free_clear((void **)&copy);
	// Test with multiple nodes
	ft_cl_push(&original, (void *)1);
	ft_cl_push(&original, (void *)2);
	ft_cl_push(&original, (void *)3);
	copy = ft_cl_copy_list(original);
	if (!copy)
		return (4);
	// Verify copy structure
	orig_it = original;
	copy_it = copy;
	do {
		if (orig_it->data != copy_it->data)
			return (5);
		orig_it = orig_it->next;
		copy_it = copy_it->next;
	} while (orig_it != original);
	return (ft_cl_delete(&original, NULL), ft_cl_delete(&copy, NULL),
					mt_cl_copy_list());
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
