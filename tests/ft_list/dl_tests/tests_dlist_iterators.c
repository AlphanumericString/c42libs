/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_iterators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:04:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 14:18:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests__all_modules_tests.h"
#include <stdio.h>
#include <stdlib.h>

int	t_dl_at(void)
{
	t_dlist	*list;
	t_dlist	*at;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	at = ft_dl_at(list, 1);
	if (!at || at == list)
		return (1);
	else if (at->data != data2 || at->next || at->prev != list)
		return (2);
	at = ft_dl_at(list, 0);
	if (!at || at != list)
		return (3);
	else if (at->data != data || at->next != list->next || at->prev)
		return (4);
	at = ft_dl_at(list, 32);
	if (at)
		return (5);
	ft_dl_clear(&list, ft_free);
	return (0);
}

int	t_dl_begin(void)
{
	t_dlist	*list;
	t_dlist	*begin;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	begin = ft_dl_begin(list->next);
	if (!begin)
		return (1);
	else if (begin != list)
		return (2);
	else if (begin->data != data)
		return (3);
	else if (begin->next != list->next)
		return (4);
	else if (begin->prev)
		return (5);
	ft_dl_clear(&list, ft_free);
	return (0);
}

int	t_dl_end(void)
{
	t_dlist	*list;
	t_dlist	*end;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	end = ft_dl_end(list);
	if (!end)
		return (1);
	else if (end->data != data2)
		return (2);
	else if (end->next)
		return (3);
	else if (end->prev != list)
		return (4);
	ft_dl_clear(&list, ft_free);
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
