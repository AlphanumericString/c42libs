/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_sort.c                                       :+:      :+:    :+:   */
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

bool	ft_dl_issort(const t_dlist *head, const t_data_cmp cmp, int flag)
{
	t_sort_order	ord;
	int				ret;

	if (!cmp)
		return (false);
	if (!flag)
		flag = FT_SORT_ORD_ASC;
	ord = (flag & FT_SORT_ORD_MASK);
	if (ord == FT_SORT_ORD_UNO || !head->next || !head)
		return (true);
	ret = cmp(head->data, head->next->data);
	while (head->next && ft_isord_ok(ord, ret))
	{
		ret = cmp(head->data, head->next->data);
		head = head->next;
	}
	if (ret && ft_isord_ok(ord, ret))
		return (false);
	return (head->next == NULL);
}

t_dlist	*ft_dl_sort(t_dlist **head, const t_data_cmp cmp, int flags)
{
	const t_sort_order	ord = (flags & FT_SORT_ORD_MASK);
	t_dlist				*runner;
	t_dlist				*elem;

	if (!head || !*head || !cmp)
		return (NULL);
	if (ord == FT_SORT_ORD_UNO)
		return (*head);
	if (!flags)
		return (ft_dl_sort(head, cmp, FT_SORT_ORD_ASC));
	runner = *head;
	while (runner && ft_dl_issort(runner, cmp, flags) == false)
	{
		if (ord == FT_SORT_ORD_ASC)
			elem = ft_dl_extract_min_node(runner, cmp);
		else
			elem = ft_dl_extract_max_node(runner, cmp);
		if (elem)
			ft_swap(&elem->data, &runner->data, sizeof(runner->data));
		runner = runner->next;
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
