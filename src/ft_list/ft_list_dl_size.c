/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 21:34:50 by iron              #+#    #+#             */
/*   Updated: 2023/12/06 16:31:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

size_t	ft_list_dl_size(t_dlist *head)
{
	size_t	i;

	i = 0;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

size_t	ft_list_dl_size_of_data(t_dlist *head, t_data_is function)
{
	size_t	i;

	i = 0;
	while (head)
	{
		if (function(head->data))
			i++;
		head = head->next;
	}
	return (i);
}
