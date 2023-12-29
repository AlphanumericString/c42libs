/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:33:24 by iron              #+#    #+#             */
/*   Updated: 2023/12/11 09:47:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_list_dl_apply(t_dlist *start, t_data_apply applied)
{
	return (ft_list_dl_apply_range(start, NULL, applied));
}

size_t	ft_list_dl_apply_range(t_dlist *start, const t_dlist *end,
		t_data_apply applied)
{
	size_t	i;
	t_dlist	*it;

	it = start;
	i = 0;
	while (it != end)
	{
		applied(it->data);
		it = it->next;
		i++;
	}
	return (i);
}

size_t	ft_list_dl_apply_range_node(t_dlist *start, const t_dlist *end,
		t_dnode_apply applied)
{
	size_t	i;
	t_dlist	*it;

	it = start;
	i = 0;
	while (it != end)
	{
		applied(it);
		it = it->next;
		i++;
	}
	return (i);
}
