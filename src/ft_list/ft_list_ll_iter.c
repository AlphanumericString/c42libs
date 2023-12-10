/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_iter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:53 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:26:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_listiter(t_list *lst, t_data_apply f)
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

void	ft_listiter_range(t_list *lst, const t_list *end, t_data_apply f)
{
	if (!f)
		return ;
	while (lst && lst != end)
	{
		f(lst->data);
		lst = lst->next;
	}
}

// nxt = lst->next;
// 		f may modify lst->next
void	ft_listiter_range_node(t_list *lst, const t_list *end, t_lnode_apply f)
{
	t_list	*nxt;

	if (!f)
		return ;
	while (lst && lst != end)
	{
		nxt = lst->next;
		f(lst);
		lst = nxt;
	}
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
