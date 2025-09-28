/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_find.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:27:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "ft_algorithms.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/list__ll_tests.h"
#include <stdlib.h>

int	t_ll_find(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	int		*data3;
	t_list	*found;

	data3 = ft_malloc(sizeof(int));
	create_2elem_list(&list, (void **)&data, (void **)&data2);
	found = ft_ll_find(list, data2, NULL);
	if (!found || *(int *)found->data != *data2)
		return (1);
	*data3 = 63;
	found = ft_ll_find(list, data3, ft_cmp_int_p);
	if (found)
		return (2);
	found = ft_ll_find(NULL, data2, NULL);
	if (found)
		return (3);
	*data3 = 42;
	found = ft_ll_find(list, data3, ft_cmp_int_p);
	if (!found || *(int *)found->data != *data)
		return (4);
	ft_ll_clear(&list, ft_free);
	free(data3);
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
