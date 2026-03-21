/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_iterators.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/list__dl_tests.h"

int	tdl_at(void)
{
	t_dlist	*list;
	t_dlist	*at;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	at = ft_dl_at(list, 1);
	if (!at || at == list)
		return (ft_dl_delete(&list, ft_free), 1);
	else if (at->data != data2 || at->next || at->prev != list)
		return (ft_dl_delete(&list, ft_free), 2);
	at = ft_dl_at(list, 0);
	if (!at || at != list)
		return (ft_dl_delete(&list, ft_free), 3);
	else if (at->data != data || at->next != list->next || at->prev)
		return (ft_dl_delete(&list, ft_free), 4);
	at = ft_dl_at(list, 32);
	if (at)
		return (ft_dl_delete(&list, ft_free), 5);
	return (ft_dl_delete(&list, ft_free), EXIT_SUCCESS);
}

int	tdl_begin(void)
{
	t_dlist	*list;
	t_dlist	*begin;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	begin = ft_dl_begin(list->next);
	if (!begin)
		return (ft_dl_delete(&list, ft_free), 1);
	else if (begin != list)
		return (ft_dl_delete(&list, ft_free), 2);
	else if (begin->data != data)
		return (ft_dl_delete(&list, ft_free), 3);
	else if (begin->next != list->next)
		return (ft_dl_delete(&list, ft_free), 4);
	else if (begin->prev)
		return (ft_dl_delete(&list, ft_free), 5);
	return (ft_dl_delete(&list, ft_free), EXIT_SUCCESS);
}

int	tdl_end(void)
{
	t_dlist	*list;
	t_dlist	*end;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	end = ft_dl_end(list);
	if (!end)
		return (ft_dl_delete(&list, ft_free), 1);
	else if (end->data != data2)
		return (ft_dl_delete(&list, ft_free), 2);
	else if (end->next)
		return (ft_dl_delete(&list, ft_free), 3);
	else if (end->prev != list)
		return (ft_dl_delete(&list, ft_free), 4);
	return (ft_dl_delete(&list, ft_free), EXIT_SUCCESS);
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
