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

#include "ft_list.h"
#include "ft_string.h"
#include "ft_mem.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"
#include "tests/tests_lambda_functions.h"

static int	tcl_find2(t_clist *lst)
{
	t_clist	*found;

	ft_cl_push(&lst, ft_strdup("42"));
	found = ft_cl_find(lst, "42", (t_data_cmp)ft_strcmp);
	if (!found || !found->data || ft_strcmp(found->data, "42") != 0)
		return (ft_cl_delete(&lst, NULL), 5);
	return (ft_free(found->data), ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_find(void)
{
	t_clist	*lst;
	t_clist	*found;

	lst = ft_cl_new();
	if (ft_cl_find(NULL, (void *)42, cmp_ptr_as_long) != NULL
		|| ft_cl_find(lst, (void *)42, cmp_ptr_as_long) != NULL || !lst)
		return (ft_cl_delete(&lst, NULL), 1);
	ft_cl_delete(&lst, NULL);
	lst = ft_cl_create((void *)42);
	found = ft_cl_find(lst, (void *)42, cmp_ptr_as_long);
	if (!found || found->data != (void *)42 || !lst
		|| ft_cl_find(lst, (void *)43, cmp_ptr_as_long) != NULL)
		return (ft_cl_delete(&lst, NULL), 2);
	(ft_cl_push(&lst, (void *)43), ft_cl_push(&lst, (void *)44));
	found = ft_cl_find(lst, (void *)43, cmp_ptr_as_long);
	if (!found || found->data != (void *)43
		|| ft_cl_find(lst, (void *)45, cmp_ptr_as_long) != NULL)
		return (ft_cl_delete(&lst, NULL), 3);
	found = ft_cl_find(lst, (void *)42, NULL);
	if (!found || found->data != (void *)42)
		return (ft_cl_delete(&lst, NULL), 4);
	return (tcl_find2(lst));
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
