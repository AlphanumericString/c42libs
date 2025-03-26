/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:36:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"
#include "ft_string.h"
#include "tests/lists_test_utils.h"
#include "tests/tests.h"
#include "tests/tests_lambda_functions.h"
#include "tests/tests__all_modules_tests.h"
#include <stdlib.h>

int	t_ll_map(void)
{
	t_list	*list;
	int		*datas[2];
	t_list	*map;
	t_list	*map_err[3];
	int		prev;

	create_2elem_list(&list, (void **)&datas[0], (void **)&datas[1]);
	map = ft_ll_map(list, add42_ret, free);
	map_err[0] = ft_ll_map(list, NULL, ft_free);
	map_err[1] = ft_ll_map(NULL, add42_ret, ft_free);
	map_err[2] = ft_ll_map(list, add42_ret, NULL);
	if (!map || *(int *)map->data != 84 || !map->next)
		return (1);
	else if (*(int *)map->next->data != 63)
		return (2);
	else if (map->next->next)
		return (3);
	else if (map_err[0] || map_err[1] || map_err[2])
		return (4);
	prev = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	if (ft_ll_map(list, add42_ret, ft_free))
		return (talloc_set_failpoint(prev), 5);
	talloc_set_failpoint(prev);
	return (ft_ll_clear(&list, ft_free), ft_ll_clear(&map, ft_free), 0);
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
