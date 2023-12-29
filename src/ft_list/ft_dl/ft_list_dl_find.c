/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iron <iron@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 13:05:32 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 20:44:18 by iron             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_list_dl_find(t_dlist *head, void *data, int (*cmp)(void *, void *))
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it)
	{
		if (data == it->data || (cmp && !cmp(it->data, data)))
			return (it);
		it = it->next;
	}
	return (NULL);
}
