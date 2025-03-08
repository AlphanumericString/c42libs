/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 18:59:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_dl_apply(const t_dlist *start, t_data_apply applied)
{
	return (ft_dl_apply_range(start, NULL, applied));
}

size_t	ft_dl_apply_range(const t_dlist *start, const t_dlist *end,
		t_data_apply applied)
{
	size_t	i;
	t_dlist	*it;

	it = (t_dlist *)start;
	i = 0;
	while (it != end)
	{
		applied(it->data);
		it = it->next;
		i++;
	}
	return (i);
}

size_t	ft_dl_apply_range_node(const t_dlist *start, const t_dlist *end,
		t_dnode_apply applied)
{
	size_t	i;
	t_dlist	*it;

	it = (t_dlist *)start;
	i = 0;
	while (it != end)
	{
		applied(it);
		it = it->next;
		i++;
	}
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
