/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_dl_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 12:21:43 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/10 12:25:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_dlist	*ft_list_dl_map(t_dlist *lst, void *(*f)(void *), t_data_apply del)
{
	t_dlist	*ret;
	t_dlist	*tmp;

	if (!lst || !f)
		return (NULL);
	ret = NULL;
	while (lst)
	{
		tmp = ft_list_dl_create(f(lst->data));
		if (!tmp)
			return (ft_list_dl_clear(&ret, del), NULL);
		ft_list_dl_add_back(&ret, tmp);
		lst = lst->next;
	}
	return (ret);
}
