/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_rev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:08:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:53:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "tests/lists_test_utils.h"
#include "tests/list__dl_tests.h"
#include <stdlib.h>

int	tdl_rev(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	int		*original_data1;
	int		*original_data2;

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	original_data1 = data1;
	original_data2 = data2;
	ft_dl_rev(&list);
	if (ft_dl_size(list) != 2)
		return (ft_dl_delete(&list, NULL), ft_free(data1), ft_free(data2), 1);
	else if (list->data != original_data2 || list->next->data != original_data1)
		return (ft_dl_delete(&list, ft_free), 2);
	ft_dl_delete(&list, ft_free);
	list = NULL;
	if (ft_dl_rev(NULL) || ft_dl_rev(&list))
		return (3);
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
