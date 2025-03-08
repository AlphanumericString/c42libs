/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:05 by iron              #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_create(const void *data)
{
	t_dlist	*ret;

	ret = ft_dl_new();
	if (!ret)
		return (ret);
	ret->data = (void *)data;
	return (ret);
}

t_dlist	*ft_dl_copy_node(const t_dlist *const other)
{
	t_dlist	*ret;

	ret = ft_dl_new();
	if (!ret)
		return (ret);
	ret->data = (void *)other->data;
	ret->next = (t_dlist *)other->next;
	ret->prev = (t_dlist *)other->prev;
	return (ret);
}

t_dlist	*ft_dl_copy_list(const t_dlist *const other)
{
	t_dlist	*node;
	t_dlist	*head;
	t_dlist	*prev;
	t_dlist	*it;

	it = (t_dlist *)other;
	node = NULL;
	head = NULL;
	prev = NULL;
	while (it)
	{
		node = ft_dl_copy_node(it);
		if (!node)
			return (ft_dl_delete(&head, NULL), head);
		node->prev = prev;
		if (prev)
			prev->next = node;
		else
			head = node;
		if (it->next)
			prev = node;
		it = it->next;
	}
	return (head);
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
