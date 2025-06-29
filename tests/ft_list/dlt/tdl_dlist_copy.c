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

#include "ft_string.h"
#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"

int	t_dl_copy_node(void)
{
	int		*data;
	t_dlist	*list;
	t_dlist	*copy;
	int		prev;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	copy = ft_dl_copy_node(list);
	if (!copy)
		return (1);
	else if (copy->data != list->data)
		return (2);
	else if (copy->next != list->next)
		return (3);
	else if (copy->prev != list->prev)
		return (4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_copy_node(list))
		return (talloc_set_failpoint(prev), 5);
	talloc_set_failpoint(prev);
	return (ft_dl_clear(&list, ft_free), ft_dl_clear(&copy, NULL), 0);
}

int	t_dl_copy_list(void)
{
	t_dlist	*list;
	t_dlist	*copy;
	int		*data;
	int		*data2;
	int		prev;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	copy = ft_dl_copy_list(list);
	if (!copy || copy->data != list->data)
		return (1);
	else if (!copy->next || copy->next->data != list->next->data)
		return (4);
	else if (copy->next->next)
		return (5);
	else if (copy->next->prev != copy)
		return (6);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_copy_list(list))
		return (talloc_set_failpoint(prev), 7);
	talloc_set_failpoint(prev);
	return (ft_dl_clear(&list, ft_free), ft_dl_clear(&copy, NULL), 0);
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
