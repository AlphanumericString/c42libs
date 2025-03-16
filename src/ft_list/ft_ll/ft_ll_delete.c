/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_delete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:09:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/15 18:38:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_list.h"
#include "ft_list_types.h"
#include <stddef.h>
#include <stdlib.h>

void	ft_ll_delone(t_list *lst, t_data_apply del)
{
	if (!lst)
		return ;
	if (del)
		del(lst->data);
	ft_free(lst);
}

size_t	ft_ll_delete_range(t_list *lst, const t_list *end, t_data_apply del)
{
	t_list	*tmp;
	size_t	i;

	i = 0;
	if (!lst)
		return (i);
	while (lst && lst != end)
	{
		i++;
		tmp = lst->next;
		if (del)
			del(lst->data);
		ft_free(lst);
		lst = tmp;
	}
	return (i);
}

size_t	ft_ll_delete(t_list **head, const t_data_apply del)
{
	size_t	nb;

	if (!head || !*head)
		return (0);
	nb = ft_ll_delete_range(*head, NULL, del);
	*head = NULL;
	return (nb);
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
