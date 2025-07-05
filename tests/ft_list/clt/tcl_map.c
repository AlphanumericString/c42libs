/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:57:59 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "internal/debug_defs.h"
#include "tests/tests_lambda_functions.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"

static void	*double_data(const void *data)
{
	return ((void *)((long)data * 2));
}

static int	mt_clmap(void)
{
	t_clist		*lst;
	t_clist		*mapped;
	const int	fp = *talloc_get_failpoint();

	lst = NULL;
	ft_cl_push_back(&lst, (void *)42);
	ft_cl_push_back(&lst, (void *)43);
	ft_cl_push_back(&lst, (void *)44);
	talloc_set_failpoint(0);
	mapped = ft_cl_map(lst, double_data, NULL);
	if (mapped)
		return (1);
	talloc_set_failpoint(fp);
	ft_cl_delete(&lst, NULL);
	return (EXIT_SUCCESS);
}

int	tcl_map(void)
{
	t_clist	*lst;
	t_clist	*mapped;

	if (ft_cl_map(NULL, double_data, NULL) != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	mapped = ft_cl_map(lst, double_data, NULL);
	if (!mapped || mapped->data != (void *)84)
		return (3);
	ft_cl_delete(&mapped, NULL);
	(ft_cl_push_back(&lst, (void *)43), ft_cl_push_back(&lst, (void *)44));
	mapped = ft_cl_map(lst, double_data, NULL);
	if (!mapped || ft_cl_size(mapped) != 3 || mapped->data != (void *)84
		|| mapped->next->data != (void *)86
		|| mapped->next->next->data != (void *)88)
		return (4);
	ft_cl_delete(&mapped, NULL);
	mapped = ft_cl_map(lst, double_data, do_nothing);
	if (!mapped)
		return (5);
	ft_cl_delete(&mapped, NULL);
	if (ft_cl_map(lst, NULL, do_nothing) != NULL)
		return (6);
	return (ft_cl_delete(&lst, NULL), ft_cl_delete(&mapped, NULL), mt_clmap());
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
