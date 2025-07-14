/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_iterators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

int	tcl_at(void)
{
	t_clist	*lst;

	if (ft_cl_at(NULL, 0) != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	if (!ft_cl_at(lst, 0) || ft_cl_at(lst, 0)->data != (void *)42
		|| ft_cl_at(lst, 1) != NULL || ft_cl_at(lst, -1))
		return (ft_cl_delete(&lst, NULL), 3);
	(ft_cl_push_back(&lst, (void *)43), ft_cl_push_back(&lst, (void *)44));
	if (!ft_cl_at(lst, 0) || ft_cl_at(lst, 0)->data != (void *)42)
		return (ft_cl_delete(&lst, NULL), 6);
	if (!ft_cl_at(lst, 1) || ft_cl_at(lst, 1)->data != (void *)43)
		return (ft_cl_delete(&lst, NULL), 7);
	if (!ft_cl_at(lst, 2) || ft_cl_at(lst, 2)->data != (void *)44)
		return (ft_cl_delete(&lst, NULL), 8);
	if (!ft_cl_at(lst, -1) || ft_cl_at(lst, -1)->data != (void *)44)
		return (ft_cl_delete(&lst, NULL), 9);
	if (!ft_cl_at(lst, -2) || ft_cl_at(lst, -2)->data != (void *)43)
		return (ft_cl_delete(&lst, NULL), 10);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_begin(void)
{
	t_clist	*lst;
	t_clist	*begin;

	lst = NULL;
	begin = ft_cl_begin(NULL);
	if (begin != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	begin = ft_cl_begin(lst);
	if (!begin || begin != lst)
		return (3);
	ft_cl_push_back(&lst, (void *)43);
	begin = ft_cl_begin(lst);
	if (!begin || begin != lst)
		return (4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_end(void)
{
	t_clist	*lst;
	t_clist	*end;

	lst = NULL;
	end = ft_cl_end(NULL);
	if (end != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	if (!lst)
		return (2);
	end = ft_cl_end(lst);
	if (!end || end != lst)
		return (3);
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
