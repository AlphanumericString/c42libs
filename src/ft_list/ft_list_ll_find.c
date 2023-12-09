/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_find.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 11:12:59 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/08 15:01:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	*ft_listfind(t_list *list, void *data, int (*cmp)(void *, void *))
{
	while (list)
	{
		if (cmp(list->content, data) == 0)
			return (list->content);
	}
	return (NULL);
}
