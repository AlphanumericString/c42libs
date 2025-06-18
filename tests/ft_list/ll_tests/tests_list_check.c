/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_list_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 16:21:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 19:25:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

#include "tests/lists_test_utils.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"

static int	cmp_raw_ptr(const void *ptrL, const void *ptrR)
{
	if ((long)ptrL < (long)ptrR)
		return (-1);
	else if ((long)ptrL == (long)ptrR)
		return (0);
	else
		return (1);
}

int	t_ll_check_circular(void)
{
	t_list	*lst;
	t_list	*nodes[11];
	size_t	i;

	lst = NULL;
	i = 10;
	if (ft_ll_check_circular(lst) == true)
		return (1);
	while (i--)
		ft_ll_push(&lst, (void *)i);
	i = 11;
	while (i--)
		nodes[i] = ft_ll_at(lst, i);
	if (ft_ll_check_circular(lst) == true)
		return (2);
	nodes[5]->next = nodes[0];
	i = 10;
	while (i--)
		if ((ft_ll_check_circular(nodes[i]) != true && i < 6)
			|| (ft_ll_check_circular(nodes[i]) != false && i >= 6))
			return (i + 10);
	return (ft_aapply((void **)nodes, ft_free), EXIT_SUCCESS);
}

int	t_ll_check_sorted(void)
{
	t_list	*lst;

	lst = NULL;
	ft_ll_push(&lst, (void *)8);
	if (ft_ll_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != true)
		return (1);
	ft_ll_push(&lst, (void *)7);
	if (ft_ll_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != true)
		return (2);
	ft_ll_push(&lst, (void *)9);
	if (ft_ll_check_sorted(NULL, (t_data_cmp)cmp_raw_ptr) != true)
		return (3);
	if (ft_ll_check_sorted(lst, (t_data_cmp)cmp_raw_ptr) != false)
		return (4);
	return (ft_ll_delete(&lst, NULL), EXIT_SUCCESS);
}

int	t_ll_check_health(void)
{
	t_list	*lst;

	lst = NULL;
	if (ft_ll_check_health(lst) == true)
		return (1);
	ft_ll_push(&lst, (void *)42);
	if (ft_ll_check_health(lst) == false)
		return (2);
	ft_ll_clear(&lst, NULL);
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
