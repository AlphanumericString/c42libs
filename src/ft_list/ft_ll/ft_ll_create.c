/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:40:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 00:13:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_ll_create(const void *const data)
{
	t_list	*ret;

	ret = ft_ll_new();
	if (!ret)
		return (ret);
	ret->data = (void *)data;
	return (ret);
}

t_list	*ft_ll_copy_node(const t_list *const other)
{
	t_list	*ret;

	ret = ft_ll_new();
	if (!ret)
		return (ret);
	ret->data = (void *)other->data;
	ret->next = (t_list *)other->next;
	return (ret);
}

t_list	*ft_ll_copy_list(const t_list *const other)
{
	t_list	*node;
	t_list	*head;
	t_list	*prev;
	t_list	*it;

	it = (t_list *)other;
	head = ft_ll_copy_node(it);
	if (!head)
		return (head);
	prev = head;
	head->next = NULL;
	it = (t_list *)it->next;
	while (it)
	{
		node = ft_ll_copy_node(it);
		if (!node)
			return (ft_ll_clear(&head, NULL), NULL);
		prev->next = node;
		prev = node;
		it = (t_list *)it->next;
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
