/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 13:02:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:37:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAP_TYPES_H
# define FT_MAP_TYPES_H

# include "types/ft_list_types.h"
# include "ft_defs.h"
# include "types/ft_vector_types.h"
# include <stddef.h>

/// @brief Structure representing a node in a map
/// @param data The data of the node
/// @param key The key of the node
/// @param used Whether the node is used or not
typedef struct __attribute__((packed)) s_map_node
{
	void		*data;
	const void	*key;
	size_t		hash;
}				t_map_node;

/// @brief Structure representing a map
/// @param capacity The capacity of the map
/// @param nb_e number of elem in each sublists
/// @param nb_e_total number of elements total
/// @param size The size of the map
/// @param nodes The nodes of the map (array of lists distributed by hash)
/// @param cmp The compare function of the map
/// @param hash The hash function of the map
/// @notes: see ft_map_create tests for example of a usage
typedef struct s_map
{
	size_t		capacity;
	size_t		*nb_e;
	size_t		nb_e_total;
	t_list		**nodes;
	t_data_cmp	cmp;
	t_memhash	hash;
	t_vector	*reserved_nodes;
}				t_map;

#endif /* FT_MAP_TYPES_H */
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
