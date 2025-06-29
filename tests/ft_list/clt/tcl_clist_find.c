/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:33 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

static int	cmp_data(const void *data1, const void *data2)
{
	return ((long)data1 - (long)data2);
}

int	tcl_find(void)
{
	t_clist	*lst;
	t_clist	*found;

	lst = NULL;
	// Test with NULL list
	found = ft_cl_find(NULL, (void *)42, cmp_data);
	if (found != NULL)
		return (1);
	// Test with empty list
	lst = ft_cl_new();
	if (!lst)
		return (2);
	found = ft_cl_find(lst, (void *)42, cmp_data);
	if (found != NULL)
		return (3);
	ft_free(lst);
	// Test with single node - found
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (4);
	found = ft_cl_find(lst, (void *)42, cmp_data);
	if (!found || found->data != (void *)42)
		return (5);
	// Test with single node - not found
	found = ft_cl_find(lst, (void *)43, cmp_data);
	if (found != NULL)
		return (6);
	// Test with multiple nodes - found
	ft_cl_push(&lst, (void *)43);
	ft_cl_push(&lst, (void *)44);
	found = ft_cl_find(lst, (void *)43, cmp_data);
	if (!found || found->data != (void *)43)
		return (7);
	// Test with multiple nodes - not found
	found = ft_cl_find(lst, (void *)45, cmp_data);
	if (found != NULL)
		return (8);
	// Test with NULL comparator (raw ptrs)
	found = ft_cl_find(lst, (void *)42, NULL);
	if (!found || found->data != (void *)42)
		return (9);
	char *str = ft_strdup("42");
	ft_cl_push(&lst, str);
	found = ft_cl_find(lst, "42", (t_data_cmp)ft_strcmp);
	if (!found || found->data != str)
		return (10);
	ft_free(str);
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
