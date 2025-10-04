/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:20:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/04 14:20:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_tree.h"

void	ft_tree_del(t_tree **tree, t_data_apply del)
{
	if (!tree || !*tree)
		return ;
	if ((*tree)->l)
		ft_tree_del(&(*tree)->l, del);
	if ((*tree)->r)
		ft_tree_del(&(*tree)->r, del);
	if ((*tree)->data && del)
		del((*tree)->data);
	ft_free(*tree);
	*tree = NULL;
}
