/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:05:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/list__ll_tests.h"
#include <stdlib.h>

/*
	list = NULL;
	ft_ll_add_front(&list, ft_ll_create(data2)); // (21)-> NULL
	ft_ll_add_front(&list, ft_ll_create(data)); // (42)-> (21)-> NULL
	---
	ft_ll_add_front(NULL, list); // null resiliency
	ft_ll_clear(&list, ft_free);
*/

int	tll_add_front(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = ft_malloc(sizeof(int));
	*data = 42;
	data2 = ft_malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_ll_add_front(&list, ft_ll_create(data2));
	ft_ll_add_front(&list, ft_ll_create(data));
	if (!list)
		return (ft_free(data), ft_free(data2), 1);
	if (list->data != data || !list->next
		|| list->next->data != data2 || list->next->next)
		return (ft_free(data), ft_free(data2), ft_free(list->next),
			ft_free(list), 2);
	ft_ll_add_front(NULL, list);
	return (ft_ll_clear(&list, ft_free), 0);
}

int	tll_add_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = ft_malloc(sizeof(int));
	*data = 42;
	data2 = ft_malloc(sizeof(int));
	*data2 = 21;
	list = ft_ll_create(data);
	ft_ll_add_back(&list, ft_ll_create(data2));
	if (!list)
		return (ft_free(data), ft_free(data2), 1);
	if (list->data != data || !list->next)
		return (ft_free(data), ft_free(data2), ft_free(list->next),
			ft_free(list), 2);
	else if (list->next->data != data2 || list->next->next)
		return (ft_free(data), ft_free(data2), ft_ll_clear(&list, NULL), 3);
	ft_ll_clear(&list, ft_free);
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
