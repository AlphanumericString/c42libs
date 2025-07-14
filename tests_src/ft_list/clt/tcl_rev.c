/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tcl_clist_rev.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 12:58:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"

#include "tests/list__cl_tests.h"

// lst => 42,43,44
// rev => 44,43,42
int	tcl_rev(void)
{
	t_clist	*lst;
	t_clist	*reversed;

	lst = NULL;
	if (ft_cl_rev(NULL) != NULL || ft_cl_rev(&lst) != NULL)
		return (1);
	lst = ft_cl_create((void *)42);
	reversed = ft_cl_rev(&lst);
	if (!reversed || reversed->data != (void *)42)
		return (ft_cl_delete(&lst, NULL), 2);
	(ft_cl_push_back(&lst, (void *)43), ft_cl_push_back(&lst, (void *)44));
	reversed = ft_cl_rev(&lst);
	if (!reversed || ft_cl_size(reversed) != 3
		|| reversed->data != (void *)44
		|| reversed->next->data != (void *)43
		|| reversed->next->next->data != (void *)42)
		return (ft_cl_delete(&lst, NULL), 3);
	if (reversed->next->next->next != reversed
		|| reversed->prev->data != (void *)42
		|| reversed->prev->prev->data != (void *)43
		|| reversed->prev->prev->prev != reversed)
		return (ft_cl_delete(&lst, NULL), 4);
	return (ft_cl_delete(&lst, NULL), EXIT_SUCCESS);
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
