/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 15:37:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_map.h"
#include "ft_mem.h"
#include "ft_vector.h"
#include <stdlib.h>

static t_data_apply	singleton_custom_destroy(const t_data_apply custom_destroy,
		bool set)
{
	static t_data_apply	f_ptr = NULL;

	if (set == true)
		f_ptr = custom_destroy;
	return (f_ptr);
}

static void	wrapper_destroy(void *restrict data)
{
	t_data_apply	destroy;
	t_map_node		*map_node;

	destroy = singleton_custom_destroy(NULL, false);
	map_node = (t_map_node *)data;
	if (destroy)
		(*destroy)(map_node->data);
	ft_free(map_node);
}

void	ft_map_destroy(t_map *map)
{
	ft_map_destroy_free(map, NULL);
}

static void	rsv_del(void *data)
{
	t_list	*node;

	node = (t_list *)data;
	wrapper_destroy(node->data);
	ft_free(node);
}

void	ft_map_destroy_free(t_map *map, t_data_apply free_fun)
{
	size_t	i;

	singleton_custom_destroy(free_fun, true);
	i = 0;
	if (!map)
		return ;
	while (i < map->capacity)
		ft_ll_clear(&map->nodes[i++], wrapper_destroy);
	ft_free(map->nodes);
	ft_free(map->weights);
	ft_vec_apply(map->reserved_nodes, rsv_del);
	ft_vec_destroy(&map->reserved_nodes);
	ft_free(map);
	singleton_custom_destroy(NULL, true);
}
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
