/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_ll_clear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 03:12:14 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/06 15:17:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stdlib.h>

void	ft_listclear(t_list **lst, t_data_apply del)
{
	t_list	*runner;
	t_list	*next;

	if (!lst || !del)
		return ;
	runner = *lst;
	while (runner)
	{
		next = runner->next;
		del(runner->content);
		free(runner);
		runner = next;
	}
	*lst = NULL;
}
