/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:27 by iron              #+#    #+#             */
/*   Updated: 2025/04/06 17:05:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_math.h"

t_clist	*ft_cl_at(const t_clist *head, ssize_t index)
{
	ssize_t	index_it;
	t_clist	*it;
	t_clist	*ret;

	it = (t_clist *)head;
	ret = NULL;
	if (!it)
		return (ret);
	index_it = 0;
	while (index != 0 && index_it != ft_abs_ssize_t(index))
	{
		if ((index < 0 && it->prev == head) || (index > 0 && it->next == head))
			break ;
		if (index < 0)
			it = it->prev;
		else
			it = it->next;
		index_it++;
	}
	if (index_it == ft_abs_ssize_t(index))
		ret = it;
	return (ret);
}

t_clist	*ft_cl_end(const t_clist *head)
{
	if (!head)
		return (NULL);
	return ((t_clist *)head->prev);
}

t_clist	*ft_cl_begin(const t_clist *head)
{
	return ((t_clist *)head);
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
