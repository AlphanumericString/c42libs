/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 12:39:07 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/05 12:39:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "internal/algo_util.h"
#include <stdio.h>

bool	ft_ll_issort(const t_list *head, const t_data_cmp cmp, int flag)
{
	t_sort_order	ord;
	int				ret;

	if (!flag)
		flag = FT_SORT_ORD_ASC;
	ord = (flag & FT_SORT_ORD_MASK);
	if (ord == FT_SORT_ORD_UNO || !head || !head->next)
		return (true);
	if (!cmp)
		return (false);
	ret = cmp(head->data, head->next->data);
	while (head->next && ft_isord_ok(ord, ret))
	{
		ret = cmp(head->data, head->next->data);
		head = head->next;
	}
	if (ft_isord_ok(ord, ret) == false)
		return (false);
	return (head->next == NULL);
}

static t_list	*recursive_sort(t_list **head, const t_data_cmp cmp, int flg)
{
	t_list				*mid;
	t_list				*tmp;

	if (!*head || !(*head)->next)
		return (*head);
	mid = ft_ll_mid(*head);
	if (!mid)
		return (*head);
	tmp = mid->next;
	mid->next = NULL;
	mid = tmp;
	recursive_sort(head, cmp, flg);
	recursive_sort(&mid, cmp, flg);
	return (ft_ll_merge_sorted(head, mid, cmp, flg));
}

t_list	*ft_ll_sort(t_list **head, const t_data_cmp cmp, int flags)
{
	const t_sort_order	ord = (flags & FT_SORT_ORD_MASK);

	if (!head || !cmp)
		return (NULL);
	if (!*head || ord == FT_SORT_ORD_UNO || !(*head)->next)
		return (*head);
	if (!flags)
		return (ft_ll_sort(head, cmp, FT_SORT_ORD_ASC));
	return (recursive_sort(head, cmp, flags));
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
