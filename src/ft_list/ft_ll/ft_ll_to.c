/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll_to.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/22 11:46:22 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/22 11:46:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_mem.h"
#include "types/ft_list_types.h"

void	**ft_ll_to_array(t_list **head)
{
	void	**d;

	if (!head || !*head)
		return (NULL);
	d = ft_ll_get_datas(*head);
	if (d)
		ft_ll_delete(head, NULL);
	return (d);
}

t_dlist	*ft_ll_to_dl(t_list	**head)
{
	t_dlist	*head_r;
	t_list	*no_leaks;

	if (!head || !*head)
		return (NULL);
	head_r  = NULL;
	while (*head)
	{
		ft_dl_push(&head_r, (*head)->data);
		no_leaks = *head;
		*head = (*head)->next;
		ft_free(no_leaks);
	}
	ft_dl_rev(&head_r);
	return (head_r);
}

t_clist	*ft_ll_to_cl(t_list	**head)
{
	t_clist	*head_r;
	t_list	*no_leaks;

	if (!head || !*head)
		return (NULL);
	head_r = NULL;
	while (*head)
	{
		ft_dl_push(&head_r, (*head)->data);
		no_leaks = *head;
		*head = (*head)->next;
		ft_free(no_leaks);
	}
	ft_cl_rev(&head_r);
	return (head_r);
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
