/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 20:12:46 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/24 20:12:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_mem.h"
#include "types/ft_list_types.h"
#include "internal/algo_util.h"

bool	ft_cl_issort(const t_clist *head, const t_data_cmp cmp, int flag)
{
	const t_clist	*start = head;
	t_sort_order	ord;
	int				ret;

	if (!cmp)
		return (false);
	if (!flag)
		flag = FT_SORT_ORD_ASC;
	ord = (flag & FT_SORT_ORD_MASK);
	if (ord == FT_SORT_ORD_UNO || !head || !head->next)
		return (true);
	ret = cmp(head->data, head->next->data);
	while (head->next && head->next != start && ft_isord_ok(ord, ret))
	{
		ret = cmp(head->data, head->next->data);
		head = head->next;
	}
	if (ft_isord_ok(ord, ret) == false)
		return (false);
	return (head->next == NULL || head->next == start);
}

// checks if list "valid" in loop by checkint if it != NULL but to speed up
// we likely could say that user is responsible for maintaining the list's
// health
// ...
// same for checking if it2 exists, extract_min/max_node should always
// return a valid node if list is valid and cmp is provided
t_clist	*ft_cl_sort(t_clist **head, const t_data_cmp cmp, int flags)
{
	const t_sort_order	ord = (flags & FT_SORT_ORD_MASK);
	t_clist				*it;
	t_clist				*it2;

	if (!head || !cmp)
		return (NULL);
	if (!*head || ord == FT_SORT_ORD_UNO)
		return (*head);
	if (!flags)
		flags = FT_SORT_ORD_ASC;
	it = *head;
	while (it && it->next != *head && ft_cl_issort(it, cmp, flags) == false)
	{
		if (ord == FT_SORT_ORD_ASC)
			it2 = ft_cl_extract_min_node(it, *head, cmp);
		else
			it2 = ft_cl_extract_max_node(it, *head, cmp);
		if (it2)
			ft_swap(&it2->data, &it->data, sizeof(it->data));
		it = it->next;
	}
	return (*head);
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
