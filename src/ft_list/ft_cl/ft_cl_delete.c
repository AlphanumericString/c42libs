/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:10 by iron              #+#    #+#             */
/*   Updated: 2025/06/18 17:19:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_mem.h"
#include <stdlib.h>

// !target -> error list is circular, NULL is not the end of list
// to delete the whole list use ->cl_delete

size_t	ft_cl_delete_range(t_clist *start, const t_clist *target,
		t_data_apply del)
{
	t_clist	*prev_r;
	t_clist	*next_r;
	t_clist	*nxt_it;
	int		i;

	i = 0;
	if (!start || !target)
		return (0);
	prev_r = start->prev;
	next_r = target->next;
	while (start != target)
	{
		i++;
		if (del)
			del(start->data);
		nxt_it = start->next;
		ft_free(start);
		start = nxt_it;
	}
	if (del)
		del(start->data);
	ft_free(start);
	prev_r->next = next_r;
	next_r->prev = prev_r;
	return (i + 1);
}

size_t	ft_cl_delete(t_clist **head, t_data_apply del)
{
	int		ret;
	void	*data;

	ret = 0;
	while (*head)
	{
		data = ft_cl_pop(head);
		if (del)
			del(data);
		ret++;
	}
	*head = NULL;
	return (ret);
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
