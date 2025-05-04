/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:48:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 16:55:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/tests__all_modules_tests.h"
#include "ft_string.h"

#include <stdlib.h>

int	t_cl_add_front(void)
{
	t_clist	*list;
	t_clist	*node;

	list = NULL;
	node = ft_cl_create((void *)42);
	if (!node)
		return (1);
	ft_cl_add_front(&list, node);
	if (!list || list->data != (void *)42 || list->next != list || \
	list->prev != list)
		return (2);
	node = ft_cl_create((void *)43);
	if (!node)
		return (3);
	ft_cl_add_front(&list, node);
	if (!list || list->data != (void *)43 || list->next == list || \
	list->prev == list || list->next->data != (void *)42)
		return (4);
	ft_cl_delete(&list, NULL);
	return (0);
}

int	t_cl_add_back(void)
{
	return (0);
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
