/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_clist_new.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 15:35:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "types/ft_list_types.h"

#include "tests/tests__all_modules_tests.h"

static int	mt_cl_new(void)
{
	t_clist		*node;
	const int	talloc_fp = *talloc_get_failpoint();

	talloc_set_failpoint(0);
	node = ft_cl_new();
	if (node)
		return (1);
	talloc_set_failpoint(talloc_fp);
	return (EXIT_SUCCESS);
}

int	t_cl_new(void)
{
	t_clist	*node;
	size_t	i;

	i = 0;
	while (i < 10)
	{
		node = ft_cl_new();
		if (!node)
			return (5);
		if (node->data != NULL || node->next != node || node->prev != node)
			return (6);
		ft_free(node);
		i++;
	}
	return (mt_cl_new());
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
