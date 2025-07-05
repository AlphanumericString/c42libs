/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_create.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:23:08 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_list.h"
#include "tests/ll_tests.h"
#include "tests/tests.h"

#include <stdlib.h>

int	t_ll_create(void)
{
	t_list	*list;
	int		*data;
	int		prev;

	data = malloc(sizeof(int));
	*data = 42;
	list = ft_ll_create(data);
	if (!list || !list->data || list->data != data)
		return (ft_free(data), ft_free(list), 1);
	else if (list->next)
		return (ft_free(data), ft_free(list), 2);
	ft_ll_delete(&list, ft_free);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_ll_create(data))
		return (talloc_set_failpoint(prev), 4);
	talloc_set_failpoint(prev);
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
