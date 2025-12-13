/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_apply.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:51:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "tests/list__dl_tests.h"

int	tdl_apply(void)
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
	ft_dl_clear(&list, ft_free);
	return (EXIT_SUCCESS);
}

int	tdl_apply_range(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply_range(list, list->next, add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84 || *(int *)list->next->data != 21)
		return (2);
	return (ft_dl_clear(&list, ft_free), 0);
}

int	tdl_apply_range_node(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	ft_dl_apply_range_node(list, list->next, dnode_add42);
	if (ft_dl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84 || *(int *)list->next->data != 21)
		return (2);
	return (ft_dl_clear(&list, ft_free), 0);
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
