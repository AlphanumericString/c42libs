/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 22:49:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 22:49:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"

#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

static int	mt_cl_copy_list(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*original;
	t_clist		*copy;
	size_t		i;
	int			r;

	i = 0;
	original = NULL;
	r = EXIT_SUCCESS;
	while (i < 10)
		ft_cl_push(&original, (void *)(long)i++);
	if (!original || ft_cl_size(original) != 10)
		return (ft_cl_delete(&original, NULL), 1);
	talloc_set_failpoint(0);
	copy = ft_cl_copy_list(original);
	if (copy != NULL)
		r = 2;
	talloc_set_failpoint(fp);
	ft_cl_delete(&original, NULL);
	return (r);
}

static int	mt_cl_copy_node(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*node1;
	t_clist		*node;
	int			r;

	node1 = ft_cl_create(&mt_cl_copy_node);
	r = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	node = ft_cl_copy_node(node1);
	if (node)
		r = 1;
	talloc_set_failpoint(fp);
	ft_free(node1);
	return (r);
}

int	tcl_copy_node(void)
{
	t_clist	*original;
	t_clist	*copy;

	copy = ft_cl_copy_node(NULL);
	if (copy != NULL)
		return (1);
	original = ft_cl_create((void *)42);
	if (!original)
		return (2);
	copy = ft_cl_copy_node(original);
	if (!copy || copy->data != original->data
		|| copy->next != original->next
		|| copy->prev != original->prev)
		return (ft_free(original), ft_free(copy), 3);
	return (ft_free(original), ft_free(copy), mt_cl_copy_node());
}

static int	check_nodes(t_clist *original, t_clist *copy)
{
	t_clist	*orig_it;
	t_clist	*copy_it;

	if (!original && !copy)
		return (EXIT_SUCCESS);
	else if (!original || !copy)
		return (EXIT_FAILURE);
	orig_it = original;
	copy_it = copy;
	while (orig_it != original->prev && copy_it != copy->prev)
	{
		if (orig_it->data != copy_it->data)
			return (EXIT_FAILURE);
		orig_it = orig_it->next;
		copy_it = copy_it->next;
	}
	return (EXIT_SUCCESS);
}

int	tcl_copy_list(void)
{
	t_clist	*original;
	t_clist	*copy;

	if (ft_cl_copy_list(NULL) != NULL)
		return (1);
	original = ft_cl_create((void *)42);
	copy = ft_cl_copy_list(original);
	if (!copy || copy->data != original->data || copy->next != copy)
		return (ft_cl_delete(&original, NULL), ft_cl_delete(&copy, NULL), 3);
	(ft_cl_delete(&original, NULL), ft_cl_delete(&copy, NULL));
	original = a_to_cl((int []){1, 2, 3}, 3);
	copy = ft_cl_copy_list(original);
	if (!copy || ft_cl_size(copy) != ft_cl_size(original))
		return (ft_cl_delete(&original, NULL), ft_cl_delete(&copy, NULL), 4);
	if (check_nodes(original, copy) != 0)
		return (ft_cl_delete(&original, NULL), ft_cl_delete(&copy, NULL), 5);
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
