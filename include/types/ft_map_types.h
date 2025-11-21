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

typedef struct __attribute__((packed)) s_map_node
{
	void				*data;
	const void			*key;
	size_t				key_size;
	size_t				hash;
	struct s_map_node	*next;
}		t_map_node;

typedef struct s_map
{
	size_t		capacity;	// cap - useful for nb lists
	t_map_node	**lists;
	size_t		*nb_e;
	size_t		nb_e_total; // total nb elem - useful for list imbalance
	t_data_cmp	cmp;		// user must either provide the func or use default strcmp
	t_memhash	hash;
	t_map_node	*nodes_pool;// pool of 'saved' nodes for reuse
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
