/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 19:04:02 by bgoulard         ###   ########.fr       */
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

static int	mt_clpush_back(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*lst;
	t_clist		*other;

	lst = NULL;
	lst = ft_cl_push(&lst, "toto");
	talloc_set_failpoint(0);
	other = ft_cl_push_back(&lst, "titi");
	if (other)
		return (1);
	talloc_set_failpoint(fp);
	ft_cl_delete(&lst, NULL);
	return (EXIT_SUCCESS);

}

static int	mt_clpush(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*lst;
	t_clist		*other;

	lst = NULL;
	lst = ft_cl_push(&lst, "toto");
	talloc_set_failpoint(0);
	other = ft_cl_push(&lst, "titi");
	if (other)
		return (1);
	talloc_set_failpoint(fp);
	ft_cl_delete(&lst, NULL);
	return (EXIT_SUCCESS);

}

int	t_cl_push(void)
{
	t_clist	*lst;
	void	*data;

	lst = NULL;
		// Test with NULL node
	data = ft_cl_push(NULL, (void *)42);
		if (data != NULL)
		return (1);
	// Test with NULL data
	lst = ft_cl_push(&lst, NULL);
	if (!lst || lst->data != NULL)
		return (2);
	ft_cl_delete(&lst, NULL);
	// Test with valid data
		lst = ft_cl_push(&lst, (void *)42);
	if (!lst || lst->data != (void *)42)
		return (3);
	// Test multiple pushes
	lst = ft_cl_push(&lst, (void *)43);
	if (!lst || lst->data != (void *)43)
		return (4);
	lst = ft_cl_push(&lst, (void *)44);
		if (!lst || lst->data != (void *)44)
		return (5);
	return (ft_cl_delete(&lst, NULL), mt_clpush());
}

int	t_cl_push_back(void)
{
	t_clist	*lst;
	t_clist	*result;

	lst = NULL;
	// Test with NULL node
	result = ft_cl_push_back(NULL, (void *)42);
	if (result != NULL)
		return (1);
	// Test with NULL data
	result = ft_cl_push_back(&lst, NULL);
	if (!result || result->data != NULL)
		return (2);
	ft_cl_delete(&lst, NULL);
	// Test with valid data
	result = ft_cl_push_back(&lst, (void *)42);
	if (!result || result->data != (void *)42)
		return (3);
	// Test multiple pushes
	result = ft_cl_push_back(&lst, (void *)43);
	if (!result || result->data != (void *)42)
		return (4);
	result = ft_cl_push_back(&lst, (void *)44);
	if (!result || result->data != (void *)42)
		return (5);
	// Verify the last element
	if (lst->prev->data != (void *)44)
		return (6);
	return (ft_cl_delete(&lst, NULL), mt_clpush_back());
}

int	t_cl_pop(void)
{
	t_clist	*lst;
	void	*data;

	lst = NULL;
	// Test with NULL node
	data = ft_cl_pop(NULL);
	if (data != NULL)
		return (1);
	// Test with empty list
	data = ft_cl_pop(&lst);
	if (data != NULL || lst != NULL)
		return (2);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (3);
	data = ft_cl_pop(&lst);
	if (data != (void *)42 || lst != NULL)
		return (4);
	// Test with multiple nodes
	lst = NULL;
	ft_cl_push(&lst, (void *)42);
	ft_cl_push(&lst, (void *)43);
	ft_cl_push(&lst, (void *)44);
	data = ft_cl_pop(&lst);
	if (data != (void *)44 || lst->data != (void *)43)
		return (5);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	t_cl_pop_back(void)
{
	t_clist	*lst;
	void	*data;

	lst = NULL;
	// Test with NULL node
	data = ft_cl_pop_back(NULL);
	if (data != NULL)
		return (1);
	// Test with empty list
	data = ft_cl_pop_back(&lst);
	if (data != NULL || lst != NULL)
		return (2);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (3);
	data = ft_cl_pop_back(&lst);
	if (data != (void *)42 || lst != NULL)
		return (4);
	// Test with multiple nodes
	lst = NULL;
	ft_cl_push(&lst, (void *)42);
	ft_cl_push(&lst, (void *)43);
	ft_cl_push(&lst, (void *)44);
	data = ft_cl_pop_back(&lst);
	if (data != (void *)42 || lst->data != (void *)44)
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
