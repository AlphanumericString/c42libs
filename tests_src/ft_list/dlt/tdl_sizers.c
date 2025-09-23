/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tdl_dlist_sizers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 17:09:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:05:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"
#include "ft_mem.h"

#include "tests/lists_test_utils.h"
#include "tests/tests_lambda_functions.h"
#include "tests/list__dl_tests.h"

#include <stddef.h>
#include <stdlib.h>

int	t_dl_size(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	size_ret[0] = ft_dl_size(NULL);
	size_ret[1] = ft_dl_size(list->next);
	size_ret[2] = ft_dl_size(list);
	if (size_ret[0] != 0)
		return (1);
	else if (size_ret[1] != 1)
		return (1);
	else if (size_ret[2] != 2)
		return (1);
	ft_dl_clear(&list, ft_free);
	return (EXIT_SUCCESS);
}

int	t_dl_size_datais(void)
{
	t_dlist	*list;
	int		*data1;
	int		*data2;
	size_t	size_ret[3];

	create_2elem_dlist(&list, (void **)&data1, (void **)&data2);
	size_ret[0] = ft_dl_size_data_is(NULL, is42);
	size_ret[1] = ft_dl_size_data_is(list->next, is42);
	size_ret[2] = ft_dl_size_data_is(list, is42);
	if (size_ret[0] != 0)
		return (1);
	else if (size_ret[1] != 0)
		return (2);
	else if (size_ret[2] != 1)
		return (3);
	ft_dl_clear(&list, ft_free);
	return (EXIT_SUCCESS);
}

int	t_dl_size_cmp(void)
{
	const char	*strs_data[] = {"this", "is", "an", "example", "this", NULL};
	t_dlist		*lst;
	size_t		i;

	i = 0;
	lst = NULL;
	while (strs_data[i])
		ft_dl_push(&lst, strs_data[i++]);
	if (!lst)
		return (1);
	if (ft_dl_size_cmp(lst, "this", (t_data_cmp)ft_strcmp) != 2)
		return (2);
	ft_dl_clear(&lst, NULL);
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
