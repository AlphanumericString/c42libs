/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"
#include "tests/fixtures.h"

static int	mt_cl_getnodes(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		**datas;
	t_clist		*set1;
	size_t		i;

	i = 0;
	set1 = NULL;
	while (i < 10)
		ft_cl_push_back(&set1, (void *)(long)i++);
	talloc_set_failpoint(0);
	datas = ft_cl_get_nodes(set1);
	if (datas)
		return (1);
	talloc_set_failpoint(fp);
	ft_cl_delete(&set1, NULL);
	return (EXIT_SUCCESS);
}

static int	mt_cl_getdatas(void)
{
	const int	fp = *talloc_get_failpoint();
	void		**datas;
	t_clist		*set1;
	size_t		i;

	i = 0;
	set1 = NULL;
	while (i < 10)
		ft_cl_push_back(&set1, (void *)(long)i++);
	talloc_set_failpoint(0);
	datas = ft_cl_get_datas(set1);
	if (datas)
		return (1);
	talloc_set_failpoint(fp);
	ft_cl_delete(&set1, NULL);
	return (EXIT_SUCCESS);
}

int	tcl_get_datas(void)
{
	t_clist	*lst;
	void	**datas;

	lst = NULL;
	if (ft_cl_get_datas(NULL) != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	datas = ft_cl_get_datas(lst);
	if (!datas || datas[0] != (void *)42 || datas[1] != NULL)
		return (3);
	ft_free(datas);
	(ft_cl_push_back(&lst, (void *)43), ft_cl_push_back(&lst, (void *)44));
	datas = ft_cl_get_datas(lst);
	if (!datas || ft_cl_size(lst) != 3
		|| datas[0] != (void *)42
		|| datas[1] != (void *)43
		|| datas[2] != (void *)44)
		return (6);
	return (ft_free(datas), ft_cl_delete(&lst, NULL), mt_cl_getdatas());
}

int	tcl_get_nodes(void)
{
	t_clist	*lst;
	t_clist	**nodes;

	lst = NULL;
	if (ft_cl_get_nodes(NULL) != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	nodes = ft_cl_get_nodes(lst);
	if (!nodes || nodes[0] != lst || nodes[1] != NULL)
		return (3);
	ft_free(nodes);
	(ft_cl_push_back(&lst, (void *)43), ft_cl_push_back(&lst, (void *)44));
	nodes = ft_cl_get_nodes(lst);
	if (!nodes || ft_cl_size(lst) != 3
		|| nodes[0]->data != (void *)42
		|| nodes[1]->data != (void *)43
		|| nodes[2]->data != (void *)44)
		return (6);
	return (ft_free(nodes), ft_cl_delete(&lst, NULL), mt_cl_getnodes());
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
