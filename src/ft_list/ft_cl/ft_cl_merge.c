/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 14:49:53 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/22 14:49:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdio.h>

t_clist	*ft_cl_merge(t_clist **head, t_clist *to_append)
{
	t_clist	*lst;

	if (!head)
		return (NULL);
	if (!*head || *head == to_append)
		*head = to_append;
	else if (*head && to_append && (*head)->next == (*head))
	{
		lst = to_append->prev;
		to_append->prev = *head;
		(*head)->next = to_append;
		lst->next = (*head);
		(*head)->prev = lst;
	}
	else if (*head && to_append && (*head)->next != (*head))
	{
		lst = (*head)->prev;
		lst->next = to_append;
		lst = to_append->prev;
		to_append->prev = (*head)->prev;
		lst->next = (*head);
		(*head)->prev = lst;
	}
	return (*head);
}

static t_clist *lcl_xtractor(t_clist **head)
{
	t_clist	*x;

	if (!head || !*head)
		return (NULL);
	x = *head;
	if (*head != (*head)->next)
	{
		printf("[%s:%d %s] *head:%p(%ld) prv:%p(%ld) nxt:%p(%ld)\n",
			__FILE__, __LINE__, __func__,
			*head, (*head) ? (long)(*head)->data : 0,
			(*head)->prev, (*head)->prev ? (long)(*head)->prev->data : 0,
			(*head)->next, (*head)->next ? (long)(*head)->next->data : 0);

		*head = (*head)->next;
		(*head)->prev = x->prev;
		if ((*head)->next == x)
			(*head)->next = (*head);
	}
	else
	{
		printf("[%s:%d %s] <1> *head:%p prv:%p nxt:%p\n", __FILE__, __LINE__, __func__, *head, (*head)->prev, (*head)->next);

	   *head = NULL;
	}
	*x = (t_clist){.prev = 0, .data = x->data, .next = 0};
	return (x);

}

static t_clist	*actual_merge(t_clist *head, t_clist *to_mrg, t_data_cmp cmp,
					int flag)
{
	const t_sort_order	ord = (flag & FT_SORT_ORD_MASK);
	t_clist				*xtracted;
	t_clist				*ret;

	ret = NULL;
	while (to_mrg)
	{
		while ((cmp(head->data, to_mrg->data) <= 0 && ord == FT_SORT_ORD_ASC)
			|| (cmp(head->data, to_mrg->data) >= 0 && ord == FT_SORT_ORD_DES))
			head = head->next;
		// we are at place where head->data >= to_mrg->data;
		xtracted = lcl_xtractor(&to_mrg);
		ft_cl_push(&head, xtracted);
	}
	return (ret);
}

t_clist	*ft_cl_merge_sorted(t_clist **head, t_clist *to_merge, t_data_cmp cmp,
			int flags)
{
	const t_sort_order	ord = (flags & FT_SORT_ORD_MASK);

	if (!cmp || !head)
		return (NULL);
	if (!to_merge || to_merge == *head)
		return (*head);
	if (!*head || ord == FT_SORT_ORD_UNO)
		return (ft_cl_merge(head, to_merge));
	actual_merge(*head, to_merge, cmp, ord);
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
