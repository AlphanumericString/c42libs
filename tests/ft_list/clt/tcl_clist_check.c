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

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_string.h"
#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

static int	cmp_raw_ptr(const void *ptrL, const void *ptrR)
{
	if ((long)ptrL < (long)ptrR)
		return (-1);
	else if ((long)ptrL == (long)ptrR)
		return (0);
	else
		return (1);
}

static int	local_check_circular_special_cases(void)
{
	t_clist	*lst;

	lst = NULL;
	ft_cl_push(&lst, (void *)1);
	if (ft_cl_check_circular(NULL) != false || \
ft_cl_check_circular(lst) != true)
		return (1);
	ft_cl_push(&lst, (void *)2);
	if (ft_cl_check_circular(lst) != true)
		return (2);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
}

int	tcl_check_circular(void)
{
	t_clist	*lst;
	t_clist	*nodes[10];
	size_t	i;

	lst = NULL;
	i = 10;
	while (i)
		ft_cl_push(&lst, (void *)i--);
	i = 0;
	while (i < 10)
	{
		nodes[i] = ft_cl_at(lst, i);
		i++;
	}
	if (ft_cl_check_circular(lst) != true)
		return (1);
	// Test with a broken circular link
	nodes[5]->next = nodes[0];
	if (ft_cl_check_circular(lst) != true)
		return (2);
	i = 0;
	while (i < 10) // TODO: should be able to call ft_cl_delete >:(
		ft_free(nodes[i++]);
	return (local_check_circular_special_cases());
}

int	tcl_check_sorted(void)
{
	t_clist	*lst;

	lst = NULL;
	if (ft_cl_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != true)
		return (1);
	ft_cl_push(&lst, (void *)9);
	if (ft_cl_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != true)
		return (2);
	ft_cl_push(&lst, (void *)8);
	ft_cl_push(&lst, (void *)7);
	if (ft_cl_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != true)
		return (3);
	ft_cl_push(&lst, (void *)10);
	if (ft_cl_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != false)
		return (4);
	ft_cl_check_sorted(lst, NULL);
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
	// Test with broken prev/next links
	nodes[5]->next = nodes[0];
	if (ft_cl_check_health(lst) != false
		|| ft_cl_check_health(nodes[7]) != false)
		return (2);
	nodes[5]->next = nodes[6];
	nodes[3]->prev = nodes[6];
	if (ft_cl_check_health(nodes[7]) != false
		|| ft_cl_check_health(lst) != false)
		return (3);
	if (ft_cl_check_health(NULL) != true)
		return (4);
	nodes[3]->prev = nodes[2];
	nodes[5]->next = NULL;
	if (ft_cl_check_health(nodes[7]) != false
		|| ft_cl_check_health(lst) != false)
		return (3);
	nodes[5]->next = nodes[6];
	nodes[5]->prev = NULL;
	if (ft_cl_check_health(nodes[7]) != false
		|| ft_cl_check_health(lst) != false)
		return (3);
	nodes[5]->prev = nodes[4];
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
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
