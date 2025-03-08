/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_pushpop.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:02:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 23:48:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_list	*ft_ll_push(t_list **lst, const void *data)
{
	t_list	*new;

	if (!lst)
		return (NULL);
	new = ft_ll_create(data);
	if (!new)
		return (NULL);
	new->next = *lst;
	*lst = new;
	return (*lst);
}

t_list	*ft_ll_push_back(t_list **lst, const void *data)
{
	t_list	*added;

	if (!lst)
		return (NULL);
	added = ft_ll_create(data);
	if (!added)
		return (NULL);
	if (!*lst)
		*lst = added;
	else
		ft_ll_end(*lst)->next = added;
	return (*lst);
}

void	*ft_ll_pop(t_list **lst)
{
	t_list	*tmp;
	void	*data;

	if (!lst || !*lst)
		return (NULL);
	tmp = *lst;
	data = (*lst)->data;
	*lst = (*lst)->next;
	ft_free(tmp);
	return (data);
}

void	*ft_ll_pop_back(t_list **lst)
{
	t_list	*pre_last;
	void	*data;

	if (!lst || !*lst)
		return (NULL);
	if (!(*lst)->next)
		return (ft_ll_pop(lst));
	pre_last = *lst;
	while (pre_last->next->next)
		pre_last = pre_last->next;
	data = pre_last->next->data;
	ft_free(pre_last->next);
	pre_last->next = NULL;
	return (data);
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
