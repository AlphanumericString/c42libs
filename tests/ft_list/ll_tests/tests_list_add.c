/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:15:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:39:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include <stdlib.h>

/*
	list = NULL;
	ft_ll_add_front(&list, ft_ll_create(data2)); // (21)-> NULL
	ft_ll_add_front(&list, ft_ll_create(data)); // (42)-> (21)-> NULL
	---
	ft_ll_add_front(NULL, list); // null resiliency
	ft_ll_clear(&list, free);
*/

int	t_ll_add_front(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = NULL;
	ft_ll_add_front(&list, ft_ll_create(data2));
	ft_ll_add_front(&list, ft_ll_create(data));
	if (!list || list->data != data || !list->next
		|| list->next->data != data2 || list->next->next)
		return (1);
	ft_ll_add_front(NULL, list);
	ft_ll_clear(&list, free);
	return (0);
}

int	t_ll_add_back(void)
{
	t_list	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	*data = 42;
	data2 = malloc(sizeof(int));
	*data2 = 21;
	list = ft_ll_create(data);
	ft_ll_add_back(&list, ft_ll_create(data2));
	if (!list || list->data != data || !list->next)
		return (1);
	else if (list->next->data != data2 || list->next->next)
		return (1);
	ft_ll_clear(&list, free);
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
