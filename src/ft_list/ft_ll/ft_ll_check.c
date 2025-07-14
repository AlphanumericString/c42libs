/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 01:59:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 22:28:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_list_types.h"
#include "ft_list.h"

bool	ft_ll_check_circular(const t_list *lst)
{
	const t_list	*it2;

	if (!lst || !lst->next)
		return (false);
	it2 = lst->next->next;
	while (it2 && lst != it2)
	{
		lst = lst->next;
		if (it2->next)
			it2 = it2->next->next;
		else
			it2 = it2->next;
	}
	if (it2 == lst)
		return (true);
	return (false);
}

bool	ft_ll_check_sorted(const t_list *lst, const t_data_cmp cmp)
{
	while (lst && lst->next)
	{
		if (cmp(lst->data, lst->next->data) > 0)
			return (false);
		lst = lst->next;
	}
	return (true);
}

bool	ft_ll_check_health(const t_list *lst)
{
	if (lst)
		return (true);
	return (false);
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
