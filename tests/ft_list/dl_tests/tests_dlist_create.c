/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_create.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:58:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 14:17:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "tests/tests.h"
#include "ft_list.h"
#include "ft_list_types.h"

int	t_dl_create(void)
{
	t_dlist	*list;
	int		*data;
	int		prev;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_dl_create(data);
	if (!list)
		return (1);
	else if (list->data != data)
		return (2);
	else if (list->next)
		return (3);
	else if (list->prev)
		return (4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_create(data))
		return (talloc_set_failpoint(prev), 5);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, free);
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
