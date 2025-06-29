/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_subrange.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:25 by bgoulard         ###   ########.fr       */
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

static int	mt_clsubrange(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*cl;
	t_clist		*sub;

	cl = NULL;
	ft_cl_push(&cl, "toto");
	ft_cl_push(&cl, "titi");
	ft_cl_push(&cl, "tutu");
	talloc_set_failpoint(0);
	sub = ft_cl_subrange(cl, cl->prev);
	if (sub)
		return (1);
	talloc_set_failpoint(fp);
	ft_cl_delete(&cl, NULL);
	return (EXIT_SUCCESS);
}

int	tcl_subrange(void)
{
	t_clist	*lst;
	t_clist	*subrange;
	t_clist	*it;

	lst = NULL;
	// Test with NULL list
	subrange = ft_cl_subrange(NULL, NULL);
	if (subrange != NULL)
		return (1);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	subrange = ft_cl_subrange(lst, NULL);
	if (!subrange || subrange->data != (void *)42)
		return (3);
	ft_cl_delete(&subrange, NULL);
	// Test with multiple nodes - single node
	ft_cl_push_back(&lst, (void *)43);
	ft_cl_push_back(&lst, (void *)44);
	subrange = ft_cl_subrange(lst, lst);
	if (!subrange)
		return (4);
	if (subrange->data != (void *)42)
		return (5);
	ft_cl_delete(&subrange, NULL);
	// Test with multiple nodes - full range
	subrange = ft_cl_subrange(lst, NULL);
	if (!subrange)
		return (4);
	it = subrange;
	if (it->data != (void *)42)
		return (5);
	it = it->next;
	if (it->data != (void *)43)
		return (6);
	it = it->next;
	if (it->data != (void *)44)
		return (7);
	ft_cl_delete(&subrange, NULL);
	// Test with partial range
	subrange = ft_cl_subrange(lst, lst->next->next);
	if (!subrange)
		return (8);
	it = subrange;
	if (it->data != (void *)42)
		return (9);
	it = it->next;
	if (it->data != (void *)43)
		return (10);
	if (it->next != subrange)
		return (11);
	return (ft_cl_delete(&lst, NULL), ft_cl_delete(&subrange, NULL),
		mt_clsubrange());
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
