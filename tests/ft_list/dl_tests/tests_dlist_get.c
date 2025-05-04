/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:04:21 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 14:19:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"

#include <stdlib.h>

int	t_dl_get_datas(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	void	**datas;
	int		prev;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	datas = ft_dl_get_datas(list);
	if (!datas)
		return (1);
	else if (datas[0] != data)
		return (2);
	else if (datas[1] != data2)
		return (3);
	if (ft_dl_get_datas(NULL))
		return (4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_get_datas(list))
		return (talloc_set_failpoint(prev), \
		ft_dl_clear(&list, ft_free), 5);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, ft_free);
	free(datas);
	return (0);
}

int	t_dl_get_nodes(void)
{
	t_dlist	*list;
	int		*data;
	int		*data2;
	t_dlist	**nodes;
	int		prev;

	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	nodes = ft_dl_get_nodes(list);
	if (!nodes)
		return (1);
	else if (nodes[0] != list)
		return (2);
	else if (nodes[1] != list->next)
		return (3);
	if (ft_dl_get_nodes(NULL))
		return (4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_get_nodes(list))
		return (talloc_set_failpoint(prev), \
		ft_dl_clear(&list, ft_free), 5);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, ft_free);
	free(nodes);
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
