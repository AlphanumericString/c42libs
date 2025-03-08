/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:36:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 14:42:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#include "ft_list.h"
#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"
#include "ft_vector.h"

static void	setup_map_node(t_map_node *map_node, const void *key,
		const void *value)
{
	map_node->data = (void *)value;
	map_node->key = key;
	map_node->hash = 0;
}

bool	ft_map_set(t_map *map, const void *key, const void *value, size_t k_sz)
{
	t_map_node	*map_node;
	t_list		*reuse_node;

	reuse_node = NULL;
	map_node = ft_map_get_node(map, key, k_sz);
	if (map_node)
		return (map_node->data = (void *)value, true);
	if (map->reserved_nodes && map->reserved_nodes->count)
		reuse_node = ft_vec_pop(map->reserved_nodes);
	else
		map_node = ft_malloc(sizeof(t_map_node));
	if (!map_node && !reuse_node)
		return (false);
	if (!reuse_node && map_node)
		reuse_node = ft_ll_create(map_node);
	map_node = reuse_node->data;
	setup_map_node(map_node, key, value);
	map_node->hash = map->hash(key, k_sz);
	ft_ll_add_front(&map->nodes[map_node->hash % map->capacity], reuse_node);
	map->weights[map_node->hash % map->capacity]++;
	map->w_total++;
	return (true);
}

void	ft_map_set_cmp(t_map *map, t_data_cmp cmp)
{
	map->cmp = cmp;
}

void	ft_map_set_hash(t_map *map, t_memhash hash)
{
	map->hash = hash;
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
