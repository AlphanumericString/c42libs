/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ll_tests_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 11:08:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:47:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"
#include "tests/lists_test_utils.h"
#include <stdlib.h>

void	create_2elem_list(t_list **list, void **data1, void **data2)
{
	*data1 = ft_malloc(sizeof(int));
	*data2 = ft_malloc(sizeof(int));
	if (!*data1 || !*data2)
	{
		ft_free_clear(data1);
		ft_free_clear(data2);
		*list = NULL;
		return ;
	}
	*(int *)*data1 = 42;
	*(int *)*data2 = 21;
	*list = NULL;
	ft_ll_push(list, *data1);
	ft_ll_push_back(list, *data2);
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
