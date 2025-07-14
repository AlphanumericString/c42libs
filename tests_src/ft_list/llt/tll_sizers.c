/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tll_list_sizers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:43:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"
#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "tests/list__ll_tests.h"

#include <stdlib.h>

int	t_ll_size(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_ll_size(NULL);
	size_ret[1] = ft_ll_size(list->next);
	size_ret[2] = ft_ll_size(list);
	if (size_ret[0] != 0)
		return (1);
	if (size_ret[1] != 1)
		return (1);
	if (size_ret[2] != 2)
		return (1);
	ft_ll_clear(&list, ft_free);
	return (0);
}

int	t_ll_size_match(void)
{
	t_list	*list;
	int		*data;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_list(&list, (void **)&data, (void **)&data2);
	size_ret[0] = ft_ll_size_data_is(NULL, is42);
	size_ret[1] = ft_ll_size_data_is(list, is42);
	size_ret[2] = ft_ll_size_data_is(list->next, is42);
	if (size_ret[0] != 0)
		return (1);
	if (size_ret[1] != 1)
		return (1);
	if (size_ret[2] != 0)
		return (1);
	ft_ll_clear(&list, ft_free);
	return (0);
}

int	t_ll_size_cmp(void)
{
	const char	*datas[] = {"this", "is", "a", "test", "zod", NULL};
	t_list		*list;
	size_t		offset;

	offset = 0;
	list = NULL;
	while (datas[offset])
		ft_ll_push_back(&list, datas[offset++]);
	if (ft_ll_size_cmp(list, "test", cmp_string_length) != 2)
		return (1);
	if (ft_ll_size_cmp(list, "this", (t_data_cmp)ft_strcmp) != 1)
		return (2);
	if (ft_ll_size_cmp(list, "zod", (t_data_cmp)ft_strcmp) != 1)
		return (3);
	ft_ll_clear(&list, NULL);
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
