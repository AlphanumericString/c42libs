/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_deletors.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:25:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//	ft_ll_delone(NULL, NULL); // null resiliency

#include "ft_allocator__dev.h"
#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/list__ll_tests.h"

int	tll_delone(void)
{
	t_list	*list;
	int		*data;

	data = ft_malloc(sizeof(int));
	*data = 42;
	list = ft_ll_create(data);
	ft_ll_delone(list, NULL);
	list = ft_ll_create(data);
	ft_ll_delone(list, ft_free);
	ft_ll_delone(NULL, NULL);
	return (EXIT_SUCCESS);
}

int	tll_delete_range(void)
{
	t_list	*list;
	t_list	*nxt;
	int		*data;
	int		*data2;
	int		nb_deleted;

	data = ft_malloc(sizeof(int));
	data2 = ft_malloc(sizeof(int));
	list = ft_ll_create(data);
	ft_ll_add_back(&list, ft_ll_create(data2));
	nxt = list->next;
	nb_deleted = ft_ll_delete_range(list, list->next, ft_free);
	if (nb_deleted != 1)
		return (ft_ll_delete(&list, ft_free), 1);
	nb_deleted = ft_ll_delete_range(NULL, nxt, ft_free);
	if (nb_deleted != 0)
		return (ft_ll_delete(&list, ft_free), 1);
	return (ft_ll_delete(&nxt, ft_free), EXIT_SUCCESS);
}

int	tll_delete(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int		nb_del;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	nb_del = ft_ll_delete(&list, NULL);
	if (nb_del != 2 || list)
		return (ft_ll_delete(&list, NULL), 1);
	list = ft_ll_create(data);
	ft_ll_push_back(&list, data2);
	nb_del = ft_ll_delete(&list, ft_free);
	if (list || nb_del != 2)
		return (ft_ll_delete(&list, NULL), 2);
	if (ft_ll_delete(&list, ft_free) != 0)
		return (3);
	if (ft_ll_delete(NULL, NULL) != 0)
		return (4);
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
