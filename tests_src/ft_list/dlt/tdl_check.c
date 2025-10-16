/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_check.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:55 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include "ft_list.h"
#include "ft_algorithms.h"
#include "types/ft_list_types.h"

#include "tests/list__dl_tests.h"

static int	local_check_circular_special_cases(void)
{
	t_dlist	*lst;

	lst = NULL;
	ft_dl_push(&lst, (void *)1);
	if (ft_dl_check_circular(NULL) != false
		|| ft_dl_check_circular(lst) != false)
		return (1);
	lst->next = lst;
	if (ft_dl_check_circular(lst) != true)
		return (2);
	lst->next = NULL;
	lst->prev = lst;
	if (ft_dl_check_circular(lst) != true)
		return (3);
	lst->prev = NULL;
	ft_dl_push(&lst, (void *)2);
	if (ft_dl_check_circular(lst) != false)
		return (4);
	lst->prev = lst;
	if (ft_dl_check_circular(lst->next) != true)
		return (5);
	return (ft_free(lst->next), ft_free(lst), EXIT_SUCCESS);
}

int	tdl_check_circular(void)
{
	t_dlist	*lst;
	t_dlist	*nodes[11];
	size_t	i;

	lst = NULL;
	i = 10;
	while (i)
		ft_dl_push(&lst, (void *)i--);
	i = 11;
	while (i--)
		nodes[i] = ft_dl_at(lst, i);
	if (ft_dl_check_circular(lst) == true)
		return (1);
	nodes[5]->next = nodes[0];
	if (ft_dl_check_circular(lst) != true
		|| ft_dl_check_circular(nodes[4]) != true)
		return (2);
	nodes[5]->next = nodes[6];
	nodes[3]->prev = nodes[6];
	if (ft_dl_check_circular(nodes[7]) != true
		|| ft_dl_check_circular(lst) != true)
		return (3);
	return (ft_aapply((void **)nodes, ft_free),
		local_check_circular_special_cases());
}

int	tdl_check_sorted(void)
{
	t_dlist	*lst;

	lst = NULL;
	if (ft_dl_check_sorted(lst, ft_cmp_ptr) != true)
		return (1);
	ft_dl_push(&lst, (void *)7);
	if (ft_dl_check_sorted(lst, ft_cmp_ptr) != true)
		return (2);
	ft_dl_push(&lst, (void *)8);
	ft_dl_push(&lst, (void *)9);
	if (ft_dl_check_sorted(lst, ft_cmp_ptr) != true)
		return (3);
	ft_dl_push(&lst, (void *)3);
	if (ft_dl_check_sorted(lst, ft_cmp_ptr) != false)
		return (4);
	return (ft_dl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tdl_check_health(void)
{
	t_dlist	*lst;
	t_dlist	*nodes[11];
	size_t	i;

	lst = NULL;
	i = 10;
	while (i)
		ft_dl_push(&lst, (void *)i--);
	i = 11;
	while (i--)
		nodes[i] = ft_dl_at(lst, i);
	if (ft_dl_check_health(lst) != true)
		return (1);
	nodes[5]->next = nodes[0];
	if (ft_dl_check_health(lst) != false
		|| ft_dl_check_health(nodes[4]) != false)
		return (2);
	nodes[5]->next = nodes[6];
	nodes[3]->prev = nodes[6];
	if (ft_dl_check_health(nodes[7]) != false
		|| ft_dl_check_health(lst) != false)
		return (3);
	if (ft_dl_check_health(NULL) != true)
		return (4);
	return (ft_aapply((void **)nodes, ft_free), EXIT_SUCCESS);
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
