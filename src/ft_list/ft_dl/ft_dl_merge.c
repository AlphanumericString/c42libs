/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_merge.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:21:43 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/22 13:54:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_dl_merge(t_dlist **head, t_dlist *to_append)
{
	if (!head)
		return (NULL);
	if (*head == to_append)
		return (*head);
	if (!*head)
		*head = to_append;
	else
		ft_dl_end(*head)->next = to_append;
	return (*head);
}

static t_dlist	*recursive_merge(t_dlist *head, t_dlist *to_mrg, t_data_cmp cmp,
					int flag)
{
	const t_sort_order	ord = (flag & FT_SORT_ORD_MASK);
	t_dlist				*r;

	if (!head)
		return (to_mrg);
	if (!to_mrg)
		return (head);
	if ((cmp(head->data, to_mrg->data) <= 0 && ord == FT_SORT_ORD_ASC)
		|| (cmp(head->data, to_mrg->data) >= 0 && ord == FT_SORT_ORD_DES))
	{
		r = head;
		r->next = recursive_merge(r->next, to_mrg, cmp, ord);
	}
	else
	{
		r = to_mrg;
		r->next = recursive_merge(head, r->next, cmp, ord);
	}
	if (r->next)
		r->next->prev = r;
	return (r);
}

t_dlist	*ft_dl_merge_sorted(t_dlist **head, t_dlist *to_merge, t_data_cmp cmp,
			int flags)
{
	const t_sort_order	ord = (flags & FT_SORT_ORD_MASK);
	t_dlist				*new_head;

	if (!cmp || !head)
		return (NULL);
	if (!to_merge || to_merge == *head)
		return (*head);
	if (!*head || ord == FT_SORT_ORD_UNO)
		return (ft_dl_merge(head, to_merge));
	new_head = recursive_merge(*head, to_merge, cmp, ord);
	*head = new_head;
	return (new_head);
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
