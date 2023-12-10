/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:05:32 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 13:05:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_list_dl_find(t_dlist *head, void *data, int (*cmp)())
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it)
	{
		if (cmp(it->data, data) == 0)
			return (it);
		it = it->next;
	}
	return (NULL);
}
