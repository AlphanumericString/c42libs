/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_rev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 15:22:54 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/06 16:25:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_listrev(t_list **head)
{
	t_list	*next;
	t_list	*it;
	t_list	*prev;

	if (!*head)
		return (NULL);
	it = *head;
	prev = NULL;
	next = it->next;
	while (next)
	{
		next = it->next;
		it->next = prev;
		prev = it;
		it = next;
	}
	*head = prev;
	return (*head);
}
