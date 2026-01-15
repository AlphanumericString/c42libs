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

typedef struct s_graph_node
{
	void	*data;
}	t_graph_node;

typedef struct s_ngraph
{
	void	*data;
	t_dlist	*connected_nodes;
}	t_ngraph;

// nodes is a vector of vector to graph nodes
//
// eg: the following non-directed graph
// a--b
// |  |
// c--d--e
// would translate to
// 'nodes': [
//		[0] aka nodes::a: [[1], [2]]
//		[1] aka nodes::b: [[0], [3]]
//		[2] aka nodes::c: [[0], [3]]
//		[3] aka nodes::d: [[1], [2], [4]]
//		[4] aka nodes::e: [[3]]
// ] buuilding an adjency matrix 'inplace' to store the nodes
typedef struct s_graph
{
	t_vector	data;		// vec of datas
	t_vector	indecies;	// vec of vec of indecies
	void		*metadata;	//
}	t_graph;
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
