/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_dlist_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:06:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"

#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "tests/tests__all_modules_tests.h"
#include "tests/tests.h"

static int	base_case(void)
{
	t_dlist	*list;
	t_dlist	*map;
	t_dlist	*map2;
	int		*data1;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	map2 = ft_dl_map(list, NULL, ft_free);
	map = ft_dl_map(list, add42_ret, ft_free);
	if (!map)
		return (1);
	else if (*(int *)map->data != 84)
		return (2);
	else if (!map->next)
		return (3);
	else if (*(int *)map->next->data != 63)
		return (4);
	else if (map->next->next)
		return (5);
	else if (map2)
		return (6);
	map2 = ft_dl_map(NULL, NULL, NULL);
	if (map2)
		return (7);
	return (ft_dl_clear(&list, ft_free), ft_dl_delete(&map, ft_free), 0);
}

static int	merror_case(void)
{
	t_dlist	*list;
	t_dlist	*map;
	int		prev;
	int		*data1;
	int		*data2;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	map = ft_dl_map(list, add42_ret, ft_free);
	if (map)
		return (talloc_set_failpoint(prev), 8);
	talloc_set_failpoint(prev);
	ft_dl_clear(&list, ft_free);
	return (0);
}

int	t_dl_map(void)
{
	int	ret;

	ret = base_case();
	if (ret)
		return (ret);
	ret = merror_case();
	if (ret)
		return (ret + 10);
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
