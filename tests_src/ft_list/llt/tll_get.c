/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_get.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:32:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include "ft_list.h"
#include "ft_mem.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/fixtures.h"
#include "tests/list__ll_tests.h"

int	tll_get_datas(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	void	**datas;
	int		prev;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	datas = ft_ll_get_datas(list);
	if (!datas || datas[2] || datas[0] != data || datas[1] != data2)
		return (ft_ll_delete(&list, NULL), ft_afree(datas), 1);
	if (ft_ll_get_datas(NULL))
		return (ft_ll_delete(&list, NULL), ft_afree(datas), 2);
	ft_free_clear((void **)&datas);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	datas = ft_ll_get_datas(list);
	talloc_set_failpoint(prev);
	ft_ll_delete(&list, ft_free);
	if (datas != NULL)
		return (ft_free(datas), 3);
	return (EXIT_SUCCESS);
}

int	tll_get_nodes(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	t_list	**nodes;
	int		prev;

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	nodes = ft_ll_get_nodes(list);
	if (!nodes || nodes[2] || nodes[0] != list || nodes[1] != list->next)
		return (ft_ll_delete(&list, ft_free), ft_free(nodes), 1);
	if (ft_ll_get_nodes(NULL))
		return (ft_ll_delete(&list, ft_free), ft_free(nodes), 2);
	ft_free_clear((void **)&nodes);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	nodes = ft_ll_get_nodes(list);
	talloc_set_failpoint(prev);
	ft_ll_clear(&list, ft_free);
	if (nodes)
		return (ft_free(nodes), 3);
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
