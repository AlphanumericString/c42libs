/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_iterator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:43:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:25:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "types/ft_list_types.h"

t_list	*ft_ll_begin(const t_list *lst)
{
	if (!lst)
		return (NULL);
	return ((t_list *)lst);
}

t_list	*ft_ll_end(const t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return ((t_list *)lst);
}

t_list	*ft_ll_at(const t_list *const lst, size_t index)
{
	const t_list	*it;
	size_t			i;

	i = 0;
	it = lst;
	while (it && i < index)
	{
		it = it->next;
		i++;
	}
	if (i != index)
		return (NULL);
	return ((t_list *)it);
}

t_list	*ft_ll_mid(const t_list *const lst)
{
	const t_list	*a;
	const t_list	*b;

	if (!lst)
		return (NULL);
	if (!lst->next)
		return ((t_list *)lst);
	a = lst;
	b = lst;
	while (b)
	{
		if (b->next)
			b = b->next->next;
		else
			b = b->next;
		if (b)
			a = a->next;
	}
	return ((t_list *)a);
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
