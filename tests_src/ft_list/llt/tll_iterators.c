/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_iterators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:33:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/list__ll_tests.h"
#include <stdlib.h>

int	t_ll_begin(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*first;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	first = ft_ll_begin(list);
	if (!first)
		return (1);
	else if (first->data != data)
		return (2);
	else if (first->next != list->next)
		return (3);
	first = ft_ll_begin(NULL);
	if (first)
		return (4);
	ft_ll_clear(&list, ft_free);
	return (0);
}

int	t_ll_end(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*last;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	last = ft_ll_end(list);
	if (!last)
		return (1);
	else if (last->data != data2)
		return (2);
	else if (last->next)
		return (3);
	last = ft_ll_end(NULL);
	if (last)
		return (4);
	ft_ll_clear(&list, ft_free);
	return (0);
}

int	t_ll_at(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	*at;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	at = ft_ll_at(list, 1);
	if (!at || at == list)
		return (1);
	else if (at->data != data2 || at->next)
		return (2);
	at = ft_ll_at(list, 0);
	if (!at || at != list)
		return (3);
	else if (at->data != data || at->next != list->next)
		return (4);
	if (ft_ll_at(list, 32) || ft_ll_at(NULL, 0))
		return (5);
	ft_ll_clear(&list, ft_free);
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
