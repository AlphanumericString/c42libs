/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:17:48 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:27:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_dl_add_back(t_dlist **head, t_dlist *added)
{
	t_dlist	*last;

	if (!head || !added)
		return ;
	if (!*head)
		return (ft_list_dl_add_front(head, added));
	last = ft_list_dl_last(*head);
	last->next = added;
	added->prev = last;
}

void	ft_list_dl_add_front(t_dlist **head, t_dlist *added)
{
	if (!head || !added)
		return ;
	if (!*head)
	{
		*head = added;
		return ;
	}
	added->next = *head;
	(*head)->prev = added;
	*head = added;
}
