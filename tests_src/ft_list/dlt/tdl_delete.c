/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_delete.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:01:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:52:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>
#include "tests/list__dl_tests.h"

int	tdl_delete_self(void)
{
	int		*data;
	int		*data2;
	int		*data3;
	t_dlist	*list;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	data3 = ft_malloc(sizeof(int));
	*data3 = 63;
	ft_dl_add_back(&list, ft_dl_create(data3));
	ft_dl_delete_self(list->next, NULL);
	if (!list || list->data != data || !list->next
		|| list->next->data != data3 || list->next->next)
		return (1);
	ft_dl_clear(&list, ft_free);
	data3 = ft_malloc(sizeof(int));
	*data3 = 63;
	*data2 = 21;
	list = ft_dl_create(data3);
	ft_dl_add_back(&list, ft_dl_create(data2));
	ft_dl_delete_self(list->next, ft_free);
	if (list->next || list->data != data3)
		return (2);
	return (ft_dl_clear(&list, ft_free), ft_dl_delete_self(NULL, NULL),
		ft_dl_delete_self(ft_dl_create(data3), NULL), 0);
}

/*
	ft_dl_add_back(&list, ft_dl_create(data3));
		// NULL <-(42)<=>(21)<=>(63)-> NULL
	list2 = list->next;
		// 42 <-(21)<=>(63)-> NULL
	nb_deleted = ft_dl_delete_range(list, list->next, NULL);
		// NULL <-(21)<=>(63)-> NULL
	ft_dl_add_front(&list2, ft_dl_create(data));
		// NULL <-(42)<=>(21)<=>(63)-> NULL
	list = list2;
	nb_deleted = ft_dl_delete_range(list->next, list->next->next, ft_free);
		// NULL <-(42)<=>(63)-> NULL
*/

int	tdl_delete_range(void)
{
	t_dlist	*list;
	t_dlist	*list2;
	int		*data_array[3];
	int		nb_deleted;

	create_2elem_dlist(&list, (void **)&data_array[0], (void **)&data_array[1]);
	data_array[2] = ft_malloc(sizeof(int));
	*data_array[2] = 63;
	ft_dl_add_back(&list, ft_dl_create(data_array[2]));
	list2 = list->next;
	nb_deleted = ft_dl_delete_range(list, list->next, NULL);
	if (nb_deleted != 1 || ft_dl_size(list2) != 2
		|| *(int *)list2->data != *data_array[1]
		|| *(int *)list2->next->data != *data_array[2])
		return (1);
	ft_dl_add_front(&list2, ft_dl_create(data_array[0]));
	list = list2;
	nb_deleted = ft_dl_delete_range(list->next, list->next->next, ft_free);
	if (nb_deleted != 1 || ft_dl_size(list) != 2
		|| *(int *)list2->data != *data_array[0]
		|| *(int *)list2->next->data != *data_array[2])
		return (2);
	ft_dl_clear(&list2, ft_free);
	return (ft_dl_delete_range(NULL, NULL, ft_free), EXIT_SUCCESS);
}

int	tdl_delete(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	int		*data3;
	int		nb_deleted;

	data3 = ft_malloc(sizeof(int));
	*data3 = 63;
	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_add_back(&list, ft_dl_create(data3));
	nb_deleted = ft_dl_delete(&list, NULL);
	if (nb_deleted != 3)
		return (1);
	else if (list)
		return (2);
	ft_dl_add_front(&list, ft_dl_create(data));
	ft_dl_add_back(&list, ft_dl_create(data2));
	ft_dl_add_back(&list, ft_dl_create(data3));
	nb_deleted = ft_dl_delete(&list, ft_free);
	if (nb_deleted != 3)
		return (3);
	else if (list)
		return (4);
	ft_dl_delete(NULL, ft_free);
	return (EXIT_SUCCESS);
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
