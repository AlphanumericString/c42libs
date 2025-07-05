/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_add.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:48:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include <stdlib.h>
#include "tests/tests__all_modules_tests.h"

int	t_dl_add_front(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	data = malloc(sizeof(int));
	data2 = malloc(sizeof(int));
	*data = 42;
	*data2 = 21;
	list = ft_dl_create(data2);
	ft_dl_add_front(&list, NULL);
	if (!list || list->next)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 1);
	ft_dl_add_front(&list, ft_dl_create(data));
	if (!list || list->data != data || !list->next)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 2);
	else if (list->next->data != data2 || list->next->next)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 3);
	else if (list->next->prev != list)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 4);
	ft_dl_clear(&list, ft_free);
	ft_dl_add_front(NULL, NULL);
	return (0);
}

int	t_dl_add_back(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	list = NULL;
	data = malloc(sizeof(int));
	data2 = malloc(sizeof(int));
	*data = 42;
	*data2 = 21;
	ft_dl_add_back(&list, ft_dl_create(data));
	ft_dl_add_back(&list, NULL);
	if (!list || list->next)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 1);
	ft_dl_add_back(&list, ft_dl_create(data2));
	if (!list || list->data != data || !list->next
		|| list->next->data != data2)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 2);
	else if (list->next->next || list->next->prev != list)
		return (ft_free(data), ft_free(data2), ft_dl_clear(&list, NULL), 3);
	ft_dl_clear(&list, ft_free);
	ft_dl_add_back(NULL, NULL);
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
