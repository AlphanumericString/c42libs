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

#include "ft_string.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>
#include "tests/tests__all_modules_tests.h"

int	t_dl_clear(void)
{
	t_dlist	*list;
	int		*data;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	ft_dl_clear(&list, NULL);
	list = ft_dl_create(data);
	ft_dl_clear(&list, ft_free);
	return (0);
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

int	t_dl_clear_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	int		*data3;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	data3 = malloc(sizeof(int));
	*data3 = 63;
	ft_dl_add_back(&list, ft_dl_create(data3));
	ft_dl_clear_range(list->next, list->next->next, NULL);
	if ((ft_dl_size(list) != 3) || (list->data != data || list->next->data \
|| list->next->next->data != data3))
		return (1);
	ft_dl_add_back(&list, ft_dl_create(data2));
	ft_dl_clear_range(list->next->next, NULL, ft_free);
	if (ft_dl_size(list) != 4 || list->data != data \
|| list->next->data || list->next->next->data)
		return (2);
	ft_dl_clear_range(list, NULL, ft_free);
	ft_dl_clear_range(NULL, NULL, ft_free);
	ft_dl_delete_range(list, NULL, NULL);
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
