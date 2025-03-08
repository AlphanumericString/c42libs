/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_apply.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 23:39:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_ll_apply(const t_list *lst, t_data_apply f)
{
	t_list	*it;

	if (!f)
		return ;
	it = (t_list *)lst;
	while (it)
	{
		f(it->data);
		it = it->next;
	}
}

void	ft_ll_apply_range(const t_list *lst, const t_list *end, t_data_apply f)
{
	t_list	*it;

	if (!f)
		return ;
	it = (t_list *)lst;
	while (it && it != end)
	{
		f(it->data);
		it = it->next;
	}
}

// nxt = lst->next;
// f may modify lst->next, we dont know
void	ft_ll_apply_range_node(const t_list *lst, const t_list *end,
		t_lnode_apply f)
{
	t_list	*nxt;
	t_list	*it;

	if (!f)
		return ;
	it = (t_list *)lst;
	while (it && it != end)
	{
		nxt = it->next;
		f(it);
		it = nxt;
	}
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
