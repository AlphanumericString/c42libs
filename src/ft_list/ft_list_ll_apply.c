/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_apply.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:01:53 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:59:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_listapply(t_list *lst, t_data_apply f)
{
	if (!f)
		return ;
	while (lst)
	{
		f(lst->data);
		lst = lst->next;
	}
}

void	ft_listapply_range(t_list *lst, const t_list *end, t_data_apply f)
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
void	ft_listapply_range_node(t_list *lst, const t_list *end, t_lnode_apply f)
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
