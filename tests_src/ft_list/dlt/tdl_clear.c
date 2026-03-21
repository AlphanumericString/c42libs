/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_clear.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:56:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:32 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/tests_lambda_functions.h"
#include "tests/lists_test_utils.h"
#include "tests/list__dl_tests.h"

int	tdl_clear(void)
{
	t_dlist	*list;
	int		*data;

	data = ft_malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	ft_dl_clear(&list, NULL);
	list = ft_dl_create((void *)data);
	ft_dl_clear(&list, ft_free);
	list = ft_dl_create((void *)42);
	ft_dl_clear(&list, do_nothing);
	return (EXIT_SUCCESS);
}
//
//ft_dl_add_back(&list, ft_dl_create(data3))
//	data -> data2 -> data3
//ft_dl_clear_range(list->next, list->next->next, NULL)
//	data -> NULL -> data3
//ft_dl_add_back(&list, ft_dl_create(data2))
//	data -> NULL -> data3 -> data2
//ft_dl_clear_range(list->next->next, NULL, ft_free)
//	data -> NULL -> NULL -> NULL
//ft_dl_delete_range(list, NULL, NULL)
//	delete nodes
//

int	tdl_clear_range(void)
{
	t_dlist		*list;
	const int	data[] = {42, 21, 63};

	list = a_to_dl(data, 3);
	ft_dl_clear_range(list->next, list->next->next, NULL);
	if ((ft_dl_size(list) != 3)
		|| list->data != (void *)42
		|| list->next->data != NULL
		|| list->next->next->data != (void *)63)
		return (ft_dl_delete(&list, NULL), 1);
	ft_dl_push_back(&list, (void *)21);
	ft_dl_clear_range(list->next->next, NULL, do_nothing);
	if (ft_dl_size(list) != 4
		|| list->data != (void *)42
		|| list->next->data
		|| list->next->next->data)
		return (ft_dl_delete(&list, NULL), 2);
	ft_dl_clear_range(list, NULL, do_nothing);
	ft_dl_clear_range(NULL, NULL, do_nothing);
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
