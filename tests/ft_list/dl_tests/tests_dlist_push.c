/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_push.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/tests__all_modules_tests.h"
#include "tests/lists_test_utils.h"
#include "tests/tests.h"
#include <stdlib.h>

int	t_dl_pop(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*ret;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	ret = ft_dl_pop(&list);
	if (!list)
		return (1);
	else if (ret != data1)
		return (2);
	ret = ft_dl_pop(&list);
	if (ret != data2)
		return (3);
	if (list)
		return (4);
	ret = ft_dl_pop(&list);
	if (ret)
		return (5);
	ret = ft_dl_pop(NULL);
	if (ret)
		return (6);
	return (free(data1), free(data2), 0);
}

int	t_dl_pop_back(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*data3;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	data3 = ft_dl_pop_back(&list);
	if (!list)
		return (1);
	else if (data3 != data2)
		return (1);
	data3 = ft_dl_pop_back(&list);
	if (list)
		return (1);
	else if (data3 != data1)
		return (1);
	data3 = ft_dl_pop_back(NULL);
	if (data3)
		return (1);
	data3 = ft_dl_pop_back(&list);
	if (data3)
		return (1);
	free(data1);
	free(data2);
	return (0);
}

int	t_dl_push(void)
{
	t_dlist	*list;
	int		prev;

	list = NULL;
	ft_dl_push(&list, (void *)42);
	if (!list || list->data != (void *)42)
		return (1);
	else if (list->next)
		return (2);
	prev = *talloc_get_failpoint();
	ft_dl_push(&list, (void *)84);
	if (!list || !list->next)
		return (5);
	else if (list->next->data != (void *)42 || list->data != (void *)84)
		return (6);
	talloc_set_failpoint(0);
	if (ft_dl_push(&list, (void *)126))
		return (talloc_set_failpoint(prev), 4);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, NULL);
	return (0);
}

int	t_dl_push_back(void)
{
	t_dlist	*list;
	int		prev;

	list = NULL;
	ft_dl_push_back(&list, (void *)42);
	ft_dl_push_back(&list, (void *)84);
	ft_dl_push_back(&list, (void *)126);
	if (ft_dl_size(list) != 3)
		return (1);
	else if (list->data != (void *)42 || list->next->data != (void *)84 || \
	list->next->next->data != (void *)126)
		return (2);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ft_dl_push_back(&list, (void *)42);
	if (ft_dl_size(list) != 3)
		return (talloc_set_failpoint(prev), 3);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, NULL);
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
