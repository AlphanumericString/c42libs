/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_iterator.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:27 by iron              #+#    #+#             */
/*   Updated: 2023/12/06 16:27:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_list_dl_at(t_dlist *head, size_t index)
{
	size_t	i;
	t_dlist	*it;

	it = (t_dlist *)head;
	i = 0;
	while (i != index)
	{
		i++;
		it = it->next;
	}
	return (it);
}

t_dlist	*ft_list_dl_end(t_dlist *head)
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it->next)
		it = it->next;
	return (it);
}

t_dlist	*ft_list_dl_begin(const t_dlist *head)
{
	t_dlist	*it;

	it = (t_dlist *)head;
	while (it->prev)
		it = it->prev;
	return (it);
}

size_t	ft_list_dl_count(const t_dlist *head)
{
	size_t	count;
	t_dlist	*it;

	it = (t_dlist *)head;
	count = 0;
	while (it)
	{
		it = it->next;
		count++;
	}
	return (count);
}
