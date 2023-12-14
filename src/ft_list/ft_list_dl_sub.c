/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_sub.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:45 by iron              #+#    #+#             */
/*   Updated: 2023/12/14 15:17:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_list_dl_subrange(t_dlist *src, t_dlist *to)
{
	t_dlist	*ret;
	t_dlist	*prev;
	t_dlist	*new_node;
	t_dlist	*it;

	ret = NULL;
	if (!src)
		return (ret);
	ret = ft_list_dl_create(src->data);
	prev = ret;
	if (src == to || src->next == to)
		return (ret);
	it = src->next;
	while (it != to)
	{
		new_node = ft_list_dl_create(it->data);
		new_node->prev = prev;
		new_node->next = NULL;
		prev->next = new_node;
		prev = new_node;
		it = it->next;
	}
	return (ret);
}
