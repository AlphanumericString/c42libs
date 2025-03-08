/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_pushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:38 by iron              #+#    #+#             */
/*   Updated: 2025/02/10 14:58:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"
#include <stdlib.h>

t_dlist	*ft_dl_push(t_dlist **node, const void *data)
{
	t_dlist	*added;

	added = ft_dl_create(data);
	if (!added)
		return (NULL);
	added->next = *node;
	if (*node)
		(*node)->prev = added;
	*node = added;
	return (added);
}

t_dlist	*ft_dl_push_back(t_dlist **node, const void *data)
{
	t_dlist	*added;
	t_dlist	*it;

	it = *node;
	if (!*node)
		return (ft_dl_push(node, data));
	added = ft_dl_create(data);
	if (!added)
		return (NULL);
	while (it->next)
		it = it->next;
	it->next = added;
	added->prev = it;
	return (*node);
}

void	*ft_dl_pop(t_dlist **node)
{
	void	*data;
	t_dlist	*it;

	data = NULL;
	if (!node || !*node)
		return (NULL);
	it = *node;
	*node = (*node)->next;
	data = it->data;
	ft_free(it);
	if (*node)
		(*node)->prev = NULL;
	return (data);
}

void	*ft_dl_pop_back(t_dlist **node)
{
	void	*data;
	t_dlist	*it;
	t_dlist	*prev;

	data = NULL;
	prev = NULL;
	if (!node || !*node)
		return (NULL);
	it = ft_dl_end(*node);
	data = it->data;
	prev = it->prev;
	if (prev)
		prev->next = NULL;
	else
		*node = NULL;
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
