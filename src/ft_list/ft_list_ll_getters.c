/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_getters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 11:54:40 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:28:10 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	**ft_list_ll_get_datas(const t_list *src)
{
	t_list	**datas;
	size_t	i;

	datas = ft_calloc(sizeof(void *), ft_listsize(src) + 1);
	if (!datas)
		return (NULL);
	i = 0;
	while (src)
	{
		datas[i] = src->data;
		src = src->next;
		i++;
	}
	return (datas);
}

t_list	**ft_list_ll_get_nodes(const t_list *src)
{
	t_list	**nodes;
	size_t	i;

	nodes = ft_calloc(sizeof(t_list *), ft_listsize(src) + 1);
	if (!nodes)
		return (NULL);
	i = 0;
	while (src)
	{
		nodes[i] = src;
		src = src->next;
		i++;
	}
	return (nodes);
}
