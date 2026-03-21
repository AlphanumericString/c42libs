/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:07:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:53:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "tests/list__dl_tests.h"
#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"

int	tdl_pop(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*ret;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	ret = ft_dl_pop(&list);
	if (!list || ret != data1)
		return (ft_free(data1), ft_free(data2), ft_dl_delete(&list, NULL), 1);
	ret = ft_dl_pop(&list);
	if (ret != data2 || list != NULL)
		return (ft_free(data1), ft_free(data2), ft_dl_delete(&list, NULL), 2);
	ft_free(data1);
	ft_free(data2);
	if (ft_dl_pop(&list) != NULL || ft_dl_pop(NULL) != NULL)
		return (3);
	return (EXIT_SUCCESS);
}

int	tdl_pop_back(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*ret;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	ret = ft_dl_pop_back(&list);
	if (!list || ret != data2)
		return (ft_free(data1), ft_free(data2), ft_dl_delete(&list, NULL), 1);
	ret = ft_dl_pop_back(&list);
	if (list != NULL || ret != data1)
		return (ft_free(data1), ft_free(data2), ft_dl_delete(&list, NULL), 2);
	ft_free(data1);
	ft_free(data2);
	if (ft_dl_pop_back(NULL) != NULL || ft_dl_pop_back(&list) != NULL)
		return (3);
	return (EXIT_SUCCESS);
}

int	tdl_push(void)
{
	t_dlist	*list;
	int		prev;

	list = NULL;
	ft_dl_push(&list, (void *)42);
	if (!list || list->data != (void *)42)
		return (ft_dl_delete(&list, NULL), 1);
	else if (list->next)
		return (ft_dl_delete(&list, NULL), 2);
	ft_dl_push(&list, (void *)84);
	if (!list || !list->next)
		return (ft_dl_delete(&list, NULL), 3);
	else if (list->next->data != (void *)42 || list->data != (void *)84)
		return (ft_dl_delete(&list, NULL), 4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_push(&list, (void *)126))
		return (talloc_set_failpoint(prev), ft_dl_delete(&list, NULL), 5);
	talloc_set_failpoint(prev);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
}

int	tdl_push_back(void)
{
	t_dlist	*list;
	int		prev;

	list = NULL;
	ft_dl_push_back(&list, (void *)42);
	ft_dl_push_back(&list, (void *)84);
	ft_dl_push_back(&list, (void *)126);
	if (ft_dl_size(list) != 3)
		return (ft_dl_delete(&list, NULL), 1);
	else if (list->data != (void *)42 || list->next->data != (void *)84
		|| list->next->next->data != (void *)126)
		return (ft_dl_delete(&list, NULL), 2);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	ft_dl_push_back(&list, (void *)42);
	if (ft_dl_size(list) != 3)
		return (talloc_set_failpoint(prev), ft_dl_delete(&list, NULL), 3);
	talloc_set_failpoint(prev);
	return (ft_dl_delete(&list, NULL), EXIT_SUCCESS);
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
