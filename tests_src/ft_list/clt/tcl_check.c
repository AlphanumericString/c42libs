/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:48:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_arr.h"
#include "ft_sort.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

// maybe answer circular yes due to bward links ?
int	tcl_check_circular(void)
{
	t_clist	*lst;
	t_clist	**nodes;
	size_t	i;

	lst = NULL;
	i = 10;
	while (i)
		ft_cl_push(&lst, (void *)i--);
	if (!lst)
		return (1);
	nodes = ft_cl_get_nodes(lst);
	if (!nodes || ft_cl_check_circular(lst) != true)
		return (2);
	nodes[5]->next = nodes[0];
	if (ft_cl_check_circular(lst) != true)
		return (3);
	nodes[5]->next = NULL;
	nodes[5]->prev = NULL;
	if (ft_cl_check_circular(lst) != false)
		return (4);
	ft_afree((void **)nodes);
	return (EXIT_SUCCESS);
}

int	tcl_check_sorted(void)
{
	t_clist	*lst;

	lst = NULL;
	if (ft_cl_check_sorted(lst, ft_cmp_ptr) != true)
		return (1);
	ft_cl_push(&lst, (void *)9);
	if (ft_cl_check_sorted(lst, ft_cmp_ptr) != true)
		return (2);
	ft_cl_push(&lst, (void *)8);
	ft_cl_push(&lst, (void *)7);
	if (ft_cl_check_sorted(lst, ft_cmp_ptr) != true)
		return (3);
	ft_cl_push(&lst, (void *)10);
	if (ft_cl_check_sorted(lst, ft_cmp_ptr) != false)
		return (4);
	ft_cl_check_sorted(lst, NULL);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

static int	tcl_check_health_p2(t_clist *lst, t_clist **nodes)
{
	if (ft_cl_check_health(NULL) != true)
		return (4);
	nodes[5]->next = NULL;
	if (ft_cl_check_health(nodes[7]) != false
		|| ft_cl_check_health(lst) != false)
		return (5);
	nodes[5]->next = nodes[6];
	nodes[5]->prev = NULL;
	if (ft_cl_check_health(nodes[7]) != false
		|| ft_cl_check_health(lst) != false)
		return (6);
	nodes[5]->prev = nodes[4];
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_check_health(void)
{
	t_clist	*lst;
	t_clist	*nodes[11];
	size_t	i;

	lst = NULL;
	i = 10;
	while (i)
		ft_cl_push(&lst, (void *)i--);
	i = 11;
	while (i--)
		nodes[i] = ft_cl_at(lst, i);
	if (ft_cl_check_health(lst) != true)
		return (1);
	nodes[5]->next = nodes[0];
	if (ft_cl_check_health(lst) != false
		|| ft_cl_check_health(nodes[7]) != false)
		return (2);
	nodes[5]->next = nodes[6];
	nodes[3]->prev = nodes[6];
	if (ft_cl_check_health(nodes[7]) != false
		|| ft_cl_check_health(lst) != false)
		return (3);
	nodes[3]->prev = nodes[2];
	return (tcl_check_health_p2(lst, nodes));
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
