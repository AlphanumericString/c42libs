/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_traverse.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 14:00:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/04 14:00:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "types/ft_tree_types.h"
#include "ft_tree.h"

void	ft_tree_traverse(t_tree *tmp, t_data_apply loc_put, t_traversal_method tm)
{
	if (!tmp || !loc_put)
		return ;
	if (tm == POSFIX)
		loc_put(tmp->data);
	if (tm != POSFIX)
		ft_tree_traverse(tmp->l, loc_put, tm);
	if (tm == PREFIX)
		ft_tree_traverse(tmp->r, loc_put, tm);
	if (tm == INFIX)
		loc_put(tmp->data);
	if (tm == POSFIX)
		ft_tree_traverse(tmp->l, loc_put, tm);
	if (tm != PREFIX)
		ft_tree_traverse(tmp->r, loc_put, tm);
	if (tm == PREFIX)
		loc_put(tmp->data);
}
