/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:30:32 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/06 16:39:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_string.h"

t_list	*ft_listnew(const void *content)
{
	t_list	*elem;

	elem = ft_calloc(sizeof(t_list), 1);
	if (!elem)
		return (NULL);
	elem->content = (void *)content;
	return (elem);
}
