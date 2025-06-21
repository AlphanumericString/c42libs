/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_add.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:48:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:04:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/tests__all_modules_tests.h"
#include "ft_string.h"

#include <stdio.h>
#include <stdlib.h>

int	t_cl_add_front(void)
{
	t_clist	*cl;
	t_clist	*node[3];

	cl = NULL;
	node[0] = ft_cl_create((void *)42);
	node[1] = ft_cl_create((void *)43);
	node[2] = ft_cl_create((void *)44);
	if (!node[0] || !node[1] || !node[2])
		return (1);
	ft_cl_add_front(&cl, node[0]);
	if (!cl || cl->data != (void *)42 || cl->next != cl
		|| cl->prev != cl)
		return (2);
	ft_cl_add_front(&cl, node[1]);
	if (!cl || cl->data != (void *)43 || cl->next != node[0]
		|| cl->prev != node[0])
		return (3);
	ft_cl_add_front(&cl, node[2]);
	if (!cl || cl->data != (void *)44 || cl->next != node[1]
		|| cl->prev != node[0])
		return (4);
	ft_cl_add_front(&cl, NULL);
	ft_cl_add_front(NULL, node[0]);
	return (ft_cl_delete(&cl, NULL), 0);
}

int	t_cl_add_back(void)
{
	t_clist	*cl;
	t_clist	*node[3];

	cl = NULL;
	node[0] = ft_cl_create((void *)42);
	node[1] = ft_cl_create((void *)43);
	node[2] = ft_cl_create((void *)44);
	if (!node[0] || !node[1] || !node[2])
		return (1);
	ft_cl_add_back(&cl, node[0]);
	if (!cl || cl->data != (void *)42 || cl->next != cl
		|| cl->prev != cl)
		return (2);
	ft_cl_add_back(&cl, node[1]);
	if (!cl || cl->data != (void *)42 || cl->next != node[1]
		|| cl->prev != node[1])
		return (3);
	ft_cl_add_back(&cl, node[2]);
	if (!cl || cl->data != (void *)42 || cl->next != node[1]
		|| cl->prev != node[2])
		return (4);
	ft_cl_add_back(&cl, NULL);
	ft_cl_add_back(NULL, node[0]);
	return (ft_cl_delete(&cl, NULL), 0);
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
