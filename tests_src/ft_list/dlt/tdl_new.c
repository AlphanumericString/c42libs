/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:05:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_mem.h"
#include "tests/fixtures.h"
#include "tests/list__dl_tests.h"
#include "ft_list.h"
#include "types/ft_list_types.h"

int	tdl_new(void)
{
	t_dlist	*list;
	int		prev;

	list = ft_dl_new();
	if (!list)
		return (1);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_dl_new())
		return (talloc_set_failpoint(prev), 2);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, ft_free);
	return (EXIT_SUCCESS);
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
