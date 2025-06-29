/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:05 by iron              #+#    #+#             */
/*   Updated: 2025/06/18 14:00:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"

t_clist	*ft_cl_create(const void *data)
{
	t_clist	*ret;

	ret = ft_cl_new();
	if (!ret)
		return (ret);
	ret->data = (void *)data;
	ret->next = ret;
	ret->prev = ret;
	return (ret);
}

t_clist	*ft_cl_copy_node(const t_clist *const other)
{
	t_clist	*ret;

	if (!other)
		return (NULL);
	ret = ft_cl_new();
	if (!ret)
		return (ret);
	ret->data = (void *)other->data;
	ret->next = (t_clist *)other->next;
	ret->prev = (t_clist *)other->prev;
	return (ret);
}

t_clist	*ft_cl_copy_list(const t_clist *const other)
{
	const t_clist	*it;
	t_clist			*ret;
	t_clist			*r_head;

	r_head = NULL;
	ret = NULL;
	it = other;
	while (it)
	{
		ret = ft_cl_copy_node(it);
		if (!ret)
			return (ft_cl_clear(&r_head, NULL), NULL);
		ft_cl_add_back(&r_head, ret);
		if (it->next == other)
			break ;
		it = it->next;
	}
	return (r_head);
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
