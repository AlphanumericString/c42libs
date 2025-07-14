/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_apply.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:55:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "tests/list__cl_tests.h"

int	tcl_apply(void)
{
	t_clist	*list;
	int		data;
	int		data2;

	create_2elem_clist(&list, (void *)&data, (void *)&data2);
	ft_cl_apply(list, add42);
	if (ft_cl_size(list) != 2)
		return (1);
	else if (*(int *)list->data != 84)
		return (2);
	else if (*(int *)list->next->data != 63)
		return (3);
	return (ft_cl_delete(&list, NULL), 0);
}

int	tcl_apply_range(void)
{
	t_clist			*list;
	t_clist			*pair[2];
	const size_t	pair_idx[2] = {3, 6};
	int				nbrs[10];
	size_t			i;

	list = NULL;
	i = 10;
	set_up_continuous_int_tab(nbrs, sizeof(nbrs) / sizeof(nbrs[0]));
	while (i--)
		ft_cl_push(&list, (void *)&nbrs[i]);
	pair[0] = ft_cl_at(list, pair_idx[0]);
	pair[1] = ft_cl_at(list, pair_idx[1]);
	ft_cl_apply_range(pair[0], pair[1], add42);
	while (i < 10)
	{
		if (((i < pair_idx[0] || i > pair_idx[1])
				&& *(int *)ft_cl_at(list, i)->data != (int)i)
			|| ((pair_idx[0] < i && i < pair_idx[1])
				&& *(int *)ft_cl_at(list, i)->data != (int)(i + 42)))
			return (i);
		i++;
	}
	return (ft_cl_delete(&list, NULL), 0);
}

int	tcl_apply_range_node(void)
{
	t_clist			*list;
	t_clist			*pair[2];
	int				nbrs[10];
	size_t			i;

	list = NULL;
	i = sizeof(nbrs) / sizeof(nbrs[0]);
	set_up_continuous_int_tab(nbrs, sizeof(nbrs) / sizeof(nbrs[0]));
	while (i--)
		ft_cl_push(&list, (void *)&nbrs[i]);
	if (list && ft_cl_check_health(list) == false)
		return (1);
	pair[0] = ft_cl_at(list, 2);
	pair[1] = ft_cl_at(list, 5);
	ft_cl_apply_range_node(pair[0], pair[1], add42_clnode);
	while (i < sizeof(nbrs) / sizeof(nbrs[0]))
	{
		if (((i >= 2 && i <= 5) && ft_cl_at(list, i) != (void *)(i + 42)) ||
		(!(i >= 2 && i <= 5) && ft_cl_at(list, i) != (void *)(i)))
			return (i);
		i++;
	}
	ft_cl_apply_range_node(NULL, pair[1], add42_clnode);
	ft_cl_apply_range_node(pair[0], pair[1], NULL);
	return (ft_cl_delete(&list, NULL), 0);
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
