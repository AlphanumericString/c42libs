/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:59:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:04:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_list_types.h"

size_t	ft_cl_apply(const t_clist *start, t_data_apply applied)
{
	return (ft_cl_apply_range(start, NULL, applied));
}

size_t	ft_cl_apply_range(const t_clist *start, const t_clist *end,
		t_data_apply applied)
{
	t_clist			*it;
	const t_clist	*hold = end;
	t_clist			*tmp;
	size_t			i;

	i = 0;
	it = (t_clist *)start;
	if (!hold)
		hold = it->prev;
	while (it != hold)
	{
		tmp = it->next;
		(applied(it->data), i++);
		it = tmp;
	}
	if (!end)
		(applied(it->data), i++);
	return (i);
}

size_t	ft_cl_apply_range_node(const t_clist *start, const t_clist *end,
		t_cnode_apply applied)
{
	t_clist			*it;
	const t_clist	*hold = end;
	t_clist			*tmp;
	size_t			i;

	i = 0;
	it = (t_clist *)start;
	if (!hold)
		hold = it->prev;
	while (it != hold)
	{
		tmp = it->next;
		(applied(it), i++);
		it = tmp;
	}
	if (!end)
		(applied(it), i++);
	return (i);
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
