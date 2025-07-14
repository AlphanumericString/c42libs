/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dl_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 02:11:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 17:45:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_list_types.h"
#include "ft_list.h"
#include <stdbool.h>

static bool	ft_dl_check_circular_bward(const t_dlist *_lst)
{
	const t_dlist	*it2;
	const t_dlist	*lst;

	it2 = _lst->prev;
	lst = _lst;
	while (it2 && lst != it2)
	{
		lst = lst->prev;
		if (it2->prev)
			it2 = it2->prev->prev;
		else
			it2 = NULL;
	}
	if (it2 == lst && it2 != NULL)
		return (true);
	return (false);
}

static bool	ft_dl_check_circular_fward(const t_dlist *_lst)
{
	const t_dlist	*it2;
	const t_dlist	*lst;

	it2 = _lst->next;
	lst = _lst;
	while (it2 && lst != it2)
	{
		lst = lst->next;
		if (it2->next)
			it2 = it2->next->next;
		else
			it2 = NULL;
	}
	if (it2 == lst && it2 != NULL)
		return (true);
	return (ft_dl_check_circular_bward(lst));
}

bool	ft_dl_check_circular(const t_dlist *_lst)
{
	if (_lst && (_lst->prev == _lst || _lst->next == _lst
			|| ft_dl_check_circular_fward(_lst)))
		return (true);
	return (false);
}

bool	ft_dl_check_sorted(const t_dlist *lst, const t_data_cmp cmp)
{
	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) < 0)
			return (false);
		lst = lst->next;
	}
	return (true);
}

bool	ft_dl_check_health(const t_dlist *_lst)
{
	const t_dlist	*lst_prev;
	const t_dlist	*lst_next;
	const t_dlist	*lst;

	if (!_lst)
		return (true);
	lst = _lst;
	while (lst)
	{
		lst_prev = lst;
		lst = lst->next;
		if (lst && lst->prev != lst_prev)
			return (false);
	}
	lst = _lst;
	while (lst)
	{
		lst_next = lst;
		lst = lst->prev;
		if (lst && lst->next != lst_next)
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
