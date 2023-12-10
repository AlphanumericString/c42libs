/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_last.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:43:27 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:45:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_listlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

t_list	*ft_listat(t_list *lst, size_t index)
{
	size_t	i;

	i = 0;
	while (lst && i < index)
	{
		lst = lst->next;
		i++;
	}
	if (i != index)
		return (NULL);
	return (lst);
}
