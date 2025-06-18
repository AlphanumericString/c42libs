/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_rev.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 19:07:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

int	t_cl_rev(void)
{
	t_clist	*lst;
	t_clist	*reversed;

	lst = NULL;
	// Test with NULL list
	reversed = ft_cl_rev(NULL);
	if (reversed != NULL)
		return (1);
	reversed = ft_cl_rev(&lst);
	if (reversed != NULL)
		return (2);
	// Test with single node
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (3);
	reversed = ft_cl_rev(&lst);
	if (!reversed || reversed->data != (void *)42)
		return (4);
	// Test with multiple nodes
	ft_cl_push_back(&lst, (void *)43);
	ft_cl_push_back(&lst, (void *)44);
	reversed = ft_cl_rev(&lst);
	if (!reversed)
		return (5);
	// Verify reversed order
	if (reversed->data != (void *)44)
		return (6);
	if (reversed->next->data != (void *)43)
		return (7);
	if (reversed->next->next->data != (void *)42)
		return (8);
	// Verify circular links are maintained
	if (reversed->prev->data != (void *)42)
		return (9);
	if (reversed->next->next->next != reversed)
		return (10);
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
