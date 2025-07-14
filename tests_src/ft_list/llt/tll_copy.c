/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_copy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:24:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_list.h"
#include "tests/lists_test_utils.h"
#include "tests/list__ll_tests.h"
#include "tests/fixtures.h"
#include <stdlib.h>

int	t_ll_copy_node(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;
	int		prev;

	data = ft_malloc(sizeof(int));
	*data = 42;
	list = ft_ll_create(data);
	copy = ft_ll_copy_node(list);
	if (!copy)
		return (1);
	else if (copy->data != list->data)
		return (2);
	else if (copy->next != list->next)
		return (3);
	free(copy);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_ll_copy_node(list))
		return (talloc_set_failpoint(prev), ft_free(data), ft_free(list), 4);
	talloc_set_failpoint(prev);
	return (ft_free(data), ft_free(list), 0);
}

int	t_ll_copy_list(void)
{
	t_list	*list;
	t_list	*copy;
	int		*data;
	int		*data2;
	int		prev;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	copy = ft_ll_copy_list(list);
	if (!copy || copy->data != list->data)
		return (1);
	else if (!copy->next || copy->next->data != list->next->data)
		return (4);
	else if (copy->next->next)
		return (5);
	ft_ll_clear(&copy, NULL);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_ll_copy_list(list))
		return (talloc_set_failpoint(prev), ft_ll_clear(&list, ft_free), 6);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	if (ft_ll_copy_list(list))
		return (talloc_set_failpoint(prev), ft_ll_clear(&list, ft_free), 7);
	talloc_set_failpoint(prev);
	ft_ll_clear(&list, ft_free);
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
