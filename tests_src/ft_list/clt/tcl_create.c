/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_create.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:48:37 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include "tests/fixtures.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

static int	mt_cl_create(void)
{
	const int	fp = *talloc_get_failpoint();
	t_clist		*node;
	int			r;

	r = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	node = ft_cl_create(NULL);
	if (node)
		r = 1;
	talloc_set_failpoint(fp);
	return (r);
}

int	tcl_create(void)
{
	t_clist	*node;

	node = ft_cl_create(NULL);
	if (!node || node->data != NULL
		|| node->next != node || node->prev != node)
		return (ft_free(node), 1);
	ft_free(node);
	node = ft_cl_create((void *)42);
	if (!node || node->data != (void *)42
		|| node->next != node || node->prev != node)
		return (ft_free(node), 2);
	ft_free(node);
	return (mt_cl_create());
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
