/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:33:59 by iron              #+#    #+#             */
/*   Updated: 2023/12/06 16:27:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_list_dl_clear(t_dlist *head)
{
	return (ft_list_dl_clear_range(head, NULL));
}

size_t	ft_list_dl_clear_range(t_dlist *start, t_dlist *end)
{
	size_t	i;

	i = 0;
	while (start != end)
	{
		start->data = NULL;
		start = start->next;
		i++;
	}
	return (i);
}
