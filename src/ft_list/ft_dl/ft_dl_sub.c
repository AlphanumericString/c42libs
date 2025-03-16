/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:45 by iron              #+#    #+#             */
/*   Updated: 2025/03/16 16:49:48 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_subrange(const t_dlist *src, const t_dlist *to)
{
	t_dlist	*ret;
	t_dlist	*prev;
	t_dlist	*new_node;
	t_dlist	*it;

	ret = NULL;
	if (!src)
		return (ret);
	ret = ft_dl_create(src->data);
	if (src == to)
		return (ret);
	prev = ret;
	it = src->next;
	while (it != to)
	{
		new_node = ft_dl_create(it->data);
		if (!new_node)
			return (ft_dl_delete(&ret, NULL), NULL);
		new_node->prev = prev;
		new_node->next = NULL;
		prev->next = new_node;
		prev = new_node;
		it = it->next;
	}
	return (ret);
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
