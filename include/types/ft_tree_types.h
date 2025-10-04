/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 13:33:44 by bgoulard          #+#    #+#             */
/*   Updated: 2025/10/03 13:33:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TREE_TYPES_H
# define FT_TREE_TYPES_H

#include "ft_defs.h"

typedef	enum e_tree_type {
	LEFT_BIAS = 0,
	RIGHT_BIAS,
	UNIQUE,
} t_tree_type;

typedef struct s_tree_info {
	t_tree_type	type;
	size_t		depth;
} t_tree_info;

// typedef	struct	s_tree_inode {
// 	struct s_tree_inode	*l;
// 	struct s_tree_inode	*r;
// 	t_tree_type			type;
// } t_itree;

typedef struct s_tree_node {
	struct s_tree_node	*l;
	struct s_tree_node	*r;
	t_tree_info			infos;
	void				*data;
} t_tree;

typedef enum s_traversal_method {
	INFIX = 0,
	PREFIX,
	POSFIX,
} t_traversal_method;

#endif /* FT_TREE_TYPES_H */
