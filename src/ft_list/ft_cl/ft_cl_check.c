/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 02:11:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 00:10:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_list_types.h"
#include "ft_list.h"
#include <stdbool.h>

bool	ft_cl_check_circular(const t_clist *lst)
{
	return (ft_dl_check_circular((const t_dlist *)lst));
}

bool	ft_cl_check_sorted(const t_clist *lst, const t_data_cmp cmp)
{
	const t_clist	*it;

	if (!lst || !cmp || lst->next == lst || lst->prev == lst)
		return (true);
	it = (t_clist *)lst;
	while (it)
	{
		if (it->next == lst)
			break ;
		if (cmp(it->data, it->next->data) > 0)
			return (false);
		it = it->next;
	}
	return (true);
}

bool	ft_cl_check_health(const t_clist *_lst)
{
	const t_clist	*lst_prev;
	const t_clist	*lst_next;
	const t_clist	*lst;

	if (!_lst)
		return (true);
	lst = _lst;
	while (lst && lst->next != _lst)
	{
		lst_prev = lst;
		lst = lst->next;
		if (lst->prev != lst_prev)
			return (false);
	}
	while (lst && lst->prev != _lst)
	{
		lst_next = lst;
		lst = lst->prev;
		if (lst->next != lst_next)
			return (false);
	}
	return (true);
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
