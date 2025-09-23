/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:01:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "ft_sort.h"

#include <stdlib.h>

#include "tests/list__dl_tests.h"
#include "tests/lists_test_utils.h"

/*
ft_dl_add_back(&list, ft_dl_create(data2));
// data-> data2
*/

int	t_dl_find(void)
{
	t_dlist	*list;
	t_dlist	*found_ret[3];
	int		*data;
	int		*data2;
	int		*data3;

	data3 = ft_malloc(sizeof(int));
	*data3 = 21;
	create_2elem_dlist(&list, (void **)&data, (void **)&data2);
	found_ret[0] = ft_dl_find(list, data2, NULL);
	found_ret[1] = ft_dl_find(list, data3, NULL);
	found_ret[2] = ft_dl_find(list, data3, ft_cmp_int_p);
	if (ft_dl_size(found_ret[0]) != 1 || found_ret[0]->data != data2)
		return (1);
	else if (found_ret[1])
		return (1);
	else if (ft_dl_size(found_ret[2]) != 1 || found_ret[2]->data != data2)
		return (1);
	return (ft_dl_clear(&list, ft_free), free(data3), 0);
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
