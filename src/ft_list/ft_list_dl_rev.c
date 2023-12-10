/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:20:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:27:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_dl_rev(t_dlist **head)
{
	t_dlist	*it;
	t_dlist	*tmp;

	if (!head || !*head)
		return ;
	it = *head;
	while (it)
	{
		tmp = it->next;
		it->next = it->prev;
		it->prev = tmp;
		it = tmp;
	}
	*head = ft_list_dl_last(*head);
}
