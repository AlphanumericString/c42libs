/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:12:59 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 14:28:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_listfind(t_list *list, void *data, int (*cmp)(void *, void *))
{
	while (list)
	{
		if (data == list->data || (cmp && cmp(list->data, data) == 0))
			return (list->data);
		list = list->next;
	}
	return (NULL);
}
