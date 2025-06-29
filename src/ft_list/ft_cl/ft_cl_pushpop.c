/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_pushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:38 by iron              #+#    #+#             */
/*   Updated: 2025/06/18 19:04:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_string.h"
#include <stdlib.h>

t_clist	*ft_cl_push(t_clist **node, const void *data)
{
	t_clist	*added;
	t_clist	*last;

	if (!node)
		return (NULL);
	added = ft_cl_create(data);
	if (!added)
		return (NULL);
	if (!*node)
		return (*node = added, added);
	last = (*node)->prev;
	added->next = *node;
	(*node)->prev = added;
	added->prev = last;
	last->next = added;
	*node = added;
	return (added);
}

t_clist	*ft_cl_push_back(t_clist **node, const void *data)
{
	t_clist	*added;

	if (!node)
		return (NULL);
	if (!*node)
		return (ft_cl_push(node, data));
	added = ft_cl_create(data);
	if (!added)
		return (NULL);
	added->next = *node;
	added->prev = (*node)->prev;
	(*node)->prev = added;
	added->prev->next = added;
	return (*node);
}

void	*ft_cl_pop(t_clist **node)
{
	const void	*data;
	t_clist		*it;
	t_clist		*nxt;
	t_clist		*prv;

	if (!node || !*node)
		return (NULL);
	data = (*node)->data;
	if ((*node)->next == *node | (*node)->prev == *node)
		return (ft_free_clear((void **)node), (void *)data);
	it = *node;
	nxt = it->next;
	prv = it->prev;
	nxt->prev = prv;
	prv->next = nxt;
	*node = nxt;
	return (ft_free(it), (void *)data);
}

void	*ft_cl_pop_back(t_clist **node)
{
	void	*data;
	t_clist	*it;
	t_clist	*prv;
	t_clist	*nxt;

	data = NULL;
	if (!node || !*node)
		return (NULL);
	if ((*node)->next == *node | (*node)->prev == *node)
		return (ft_cl_pop(node));
	it = (*node)->prev;
	data = it->data;
	nxt = it->next;
	prv = it->prev;
	nxt->prev = prv;
	prv->next = nxt;
	ft_free(it);
	return (data);
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
