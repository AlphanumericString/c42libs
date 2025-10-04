/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 14:31:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/03 14:31:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_H
# define FT_TREE_H

#include "ft_defs.h"
#include "types/ft_tree_types.h"

void	ft_tree_del(t_tree **tree, t_data_apply del);
bool	ft_tree_push(t_tree **tree, void *data, t_data_cmp cmp);
void	ft_tree_traverse(t_tree *tmp, t_data_apply loc_put, t_traversal_method tm);
void	*ft_tree_get_min(t_tree	*head);
void	*ft_tree_get_max(t_tree	*head);

#endif /* FT_TREE_H */
