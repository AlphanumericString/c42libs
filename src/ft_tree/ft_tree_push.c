/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_push.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 02:43:46 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/04 02:43:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_defs.h"
#include "ft_tree.h"
#include "types/ft_tree_types.h"

bool	ft_tree_push(t_tree **tree, void *data, t_data_cmp cmp)
{
	t_tree_info	infos;
	int			r;

	if (!tree)
		return (false);
	ft_bzero(&infos, sizeof(infos));
	if (*tree)
		infos.type = (*tree)->infos.type;
	while (*tree)
	{
		r = (infos.depth++, cmp(data, (*tree)->data));
		if (r == 0 && infos.type == UNIQUE)
			return (false);
		if (r < 0 || (infos.type == LEFT_BIAS && r == 0))
			tree = &(*tree)->l;
		else
			tree = &(*tree)->r;
	}
	*tree = ft_calloc(sizeof(t_tree), 1);
	(*tree)->data = data;
	(*tree)->infos = infos;
	return (true);
}
