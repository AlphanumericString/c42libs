/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:20:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 17:10:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_list_dl_rev(t_dlist **head)
{
	t_dlist	*it;
	t_dlist	*tmp;

	it = *head;
	while (it)
	{
		tmp = it->next;
		it->next = it->prev;
		it->prev = tmp;
		if (!tmp)
			*head = it;
		it = tmp;
	}
	return (*head);
}
