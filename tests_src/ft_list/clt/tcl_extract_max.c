/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_extract_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 20:39:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/10 14:46:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "tests/list__cl_tests.h"
#include <stdio.h>

int	tcl_extract_max(void)
{
	const char	*arr[] = {"a", "b", "c", "d", "e", "f", NULL};
	t_clist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_cl_push(&list, (void *)arr[i++]);
	if (ft_cl_extract_max(list, list->prev, (t_any)ft_strcmp)
		!= (t_any)arr[i - 1])
		return (1);
	if (ft_cl_extract_max(NULL, list->prev, (t_any)ft_strcmp) != NULL
		|| ft_cl_extract_max(list, list->prev, NULL) != NULL)
		return (2);
	return (ft_cl_delete(&list, NULL), EXIT_SUCCESS);
}

int	tcl_extract_max_node(void)
{
	const char	*arr[] = {"a", "b", "c", "d", "e", "f", NULL};
	t_clist		*list;
	size_t		i;

	i = 0;
	list = NULL;
	while (arr[i])
		ft_cl_push_back(&list, (t_any)arr[i++]);
	if (ft_cl_extract_max_node(list, NULL, (t_any)ft_strcmp)->data
		!= (t_any)arr[i - 1])
		return (1);
	if (ft_cl_extract_max_node(NULL, NULL, (t_any)ft_strcmp) != NULL
		|| ft_cl_extract_max_node(list, list->prev, NULL) != NULL)
		return (2);
	return (ft_cl_delete(&list, NULL), EXIT_SUCCESS);
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
