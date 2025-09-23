/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 15:31:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/21 15:31:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_list_types.h"
#include "types/ft_vector_types.h"

typedef struct s_graph_node {
	void	*data;
} t_graph_node;

typedef struct s_ngraph {
	void	*data;
	t_dlist	*connected_nodes;
} t_ngraph;

// nodes is a vector of vector to graph nodes
//
// eg: the following non-directed graph
// a--b
// |  |
// c--d--e
// would translate to
// vector 'nodes': [
//		[0] aka nodes::a: [b, c]
//		[1] aka nodes::b: [a, d]
//		[2] aka nodes::c: [a, d]
//		[3] aka nodes::d: [b, c, e]
//		[4] aka nodes::e: [e]
// ]
typedef struct s_graph {
	t_vector	**nodes;
	void		*metadata;
	// other fields needed;
} t_graph;
