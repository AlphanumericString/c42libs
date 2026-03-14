/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_sizers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:43:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/06 21:58:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"
#include "ft_mem.h"

#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "tests/list__ll_tests.h"

#include <stdlib.h>

int	tll_size(void)
{
	t_list	*list;

	list = NULL;
	if (ft_ll_size(list) != 0)
		return (1);
	ft_ll_push(&list, (t_any)42);
	if (ft_ll_size(list) != 1)
		return (ft_ll_delete(&list, NULL), 2);
	ft_ll_push(&list, (t_any)43);
	ft_ll_push(&list, (t_any)44);
	if (ft_ll_size(list) != 3)
		return (ft_ll_delete(&list, NULL), 3);
	return (ft_ll_delete(&list, NULL), EXIT_SUCCESS);
}

int	tll_nsize(void)
{
	t_list	*list;

	list = NULL;
	if (ft_ll_nsize(list, 12) != 0 || ft_ll_nsize((t_any)0xDEAD, 0) != 0)
		return (1);
	ft_ll_push(&list, (t_any)42);
	if (ft_ll_nsize(list, 0) != 0 || ft_ll_nsize(list, 12) != 1)
		return (ft_ll_delete(&list, NULL), 2);
	ft_ll_push(&list, (t_any)43);
	ft_ll_push(&list, (t_any)44);
	if (ft_ll_nsize(list, 0) != 0 || ft_ll_nsize(list, 1) != 1
		|| ft_ll_nsize(list, -1) != 3)
		return (ft_ll_delete(&list, NULL), 3);
	return (ft_ll_delete(&list, NULL), EXIT_SUCCESS);
}

int	tll_size_match(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_ll_size_data_is(NULL, is42);
	size_ret[1] = ft_ll_size_data_is(list, is42);
	size_ret[2] = ft_ll_size_data_is(list->next, is42);
	ft_ll_delete(&list, ft_free);
	if (size_ret[0] != 0)
		return (ft_ll_delete(&list, ft_free), 1);
	if (size_ret[1] != 1)
		return (ft_ll_delete(&list, ft_free), 2);
	if (size_ret[2] != 0)
		return (ft_ll_delete(&list, ft_free), 3);
	return (ft_ll_delete(&list, ft_free), EXIT_SUCCESS);
}

int	tll_size_cmp(void)
{
	const char	*datas[] = {"this", "is", "a", "test", "zod", NULL};
	t_list		*list;
	size_t		offset;

	offset = 0;
	list = NULL;
	while (datas[offset])
		ft_ll_push_back(&list, datas[offset++]);
	if (ft_ll_size_cmp(list, "test", cmp_string_length) != 2)
		return (ft_ll_delete(&list, NULL), 1);
	if (ft_ll_size_cmp(list, "this", (t_data_cmp)ft_strcmp) != 1)
		return (ft_ll_delete(&list, NULL), 2);
	if (ft_ll_size_cmp(list, "zod", (t_data_cmp)ft_strcmp) != 1)
		return (ft_ll_delete(&list, NULL), 3);
	return (ft_ll_delete(&list, NULL), EXIT_SUCCESS);
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
