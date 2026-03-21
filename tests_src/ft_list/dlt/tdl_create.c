/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"

#include "tests/fixtures.h"
#include "tests/list__dl_tests.h"

int	tdl_create(void)
{
	t_dlist	*list;
	int		*data;
	int		prev;
	int		r;

	data = ft_malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	if (!list || !list->data || list->data != data)
		return (ft_free(data), ft_free(list), 1);
	else if (list->next || list->prev)
		return (ft_free(data), ft_free(list), 2);
	r = EXIT_SUCCESS;
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_create(data))
		r = 5;
	talloc_set_failpoint(prev);
	return (ft_dl_clear(&list, ft_free), r);
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
