/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"
#include "tests/list__dl_tests.h"

int	tdl_copy_node(void)
{
	int		*data;
	t_dlist	*list;
	t_dlist	*copy;
	int		prev;
	int		r;

	data = ft_malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	copy = ft_dl_copy_node(list);
	r = EXIT_SUCCESS;
	if (!copy)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 1);
	else if (copy->data != list->data)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 2);
	else if (copy->next != list->next)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 3);
	else if (copy->prev != list->prev)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_copy_node(list))
		r = 5;
	talloc_set_failpoint(prev);
	return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), r);
}

int	tdl_copy_list(void)
{
	t_dlist	*list;
	t_dlist	*copy;
	int		*data;
	int		*data2;
	int		ints[2];

	ints[0] = EXIT_SUCCESS;
	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	copy = ft_dl_copy_list(list);
	if (!copy || copy->data != list->data)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 1);
	else if (!copy->next || copy->next->data != list->next->data)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 2);
	else if (copy->next->next)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 3);
	else if (copy->next->prev != copy)
		return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), 4);
	ints[1] = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_copy_list(list))
		ints[0] = 7;
	talloc_set_failpoint(ints[1]);
	return (ft_dl_delete(&list, ft_free), ft_dl_delete(&copy, NULL), ints[0]);
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
