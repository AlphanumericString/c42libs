/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cl_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 02:11:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/18 19:23:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_list_types.h"
#include "ft_list.h"
#include <stdbool.h>
#include <stdio.h>

bool	ft_cl_check_circular(const t_clist *lst)
{
	return (ft_dl_check_circular((const t_dlist *)lst));
}

bool	ft_cl_check_sorted(const t_clist *lst, const t_data_cmp cmp)
{
	const t_clist	*it;

	if (!lst || !cmp || lst->next == lst | lst->prev == lst)
		return (true);
	it = (t_clist *)lst;
	while (it->next != lst)
	{
		if (cmp(it->data, it->next->data) > 0)
			return (false);
		it = it->next;
	}
	return (true);
}

// some checks on second loop are not mandatory as most errors will be caught
// by first loop (plus being a circularlist it doesn't matter that the error
// is right on prev from list, it'll be caught on forwrd loop still)
// 
// legacy full sec version::
//		const t_clist	*lst_prev;
//		const t_clist	*lst_next;
//		const t_clist	*lst;
//
//		if (!_lst)
//			return (true);
//		lst = _lst;
//		while (lst && lst->next != _lst)
//		{
//			lst_prev = lst;
//			lst = lst->next;
//			if (lst && lst->prev != lst_prev)
//				return (false);
//		}
//		if (lst && _lst->prev != lst)
//			return (false);
//		while (lst && lst->prev != _lst)
//		{
//			lst_next = lst;
//			lst = lst->prev;
//			if (lst && lst->next != lst_next)
//				return (false);
//		}
//		if (lst && _lst->next != lst)
//			return (false);
//		return (lst != NULL);
//
//
//
bool	ft_cl_check_health(const t_clist *_lst)
{
	const t_clist	*lst_prev;
	const t_clist	*lst;

	if (!_lst)
		return (true);
	lst = _lst;
	while (lst && lst->next != _lst)
	{
		lst_prev = lst;
		lst = lst->next;
		if (lst && lst->prev != lst_prev)
			return (false);
	}
	if (lst && _lst->prev != lst)
		return (false);
	while (lst && lst->prev != _lst)
		lst = lst->prev;
	return (lst != NULL);
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
