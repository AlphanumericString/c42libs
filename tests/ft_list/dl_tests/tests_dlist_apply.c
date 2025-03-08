/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:38:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include <stdlib.h>

static void	dnode_add42(t_dlist *node)
{
	*(int *)node->data += 42;
}

int	t_dl_apply(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply(list, add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84)
		return (2);
	else if (*(int *)list->next->data != 63)
		return (3);
	ft_dl_clear(&list, free);
	return (0);
}

int	t_dl_apply_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply_range(list, list->next, add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84 || \
	*(int *)list->next->data != 21)
		return (1);
	return (ft_dl_clear(&list, free), 0);
}

int	t_dl_apply_range_node(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply_range_node(list, list->next, dnode_add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84 || \
	*(int *)list->next->data != 21)
		return (1);
	return (ft_dl_clear(&list, free), 0);
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
