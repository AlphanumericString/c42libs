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

#include "types/ft_map_types.h"
#include "ft_list.h"
#include "ft_map.h"
#include "ft_mem.h"

#include <stdlib.h>

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
	t_list		*list_node;

	list_node = NULL;
	map_node = ft_map_get_node(map, key, k_sz);
	if (map_node)
		return (map_node->data = (void *)value, true);
	map_node = ft_malloc(sizeof(t_map_node));
	if (!map_node)
		return (false);
	list_node = ft_ll_create(map_node);
	map_node = list_node->data;
	setup_map_node(map_node, key, value);
	map_node->hash = map->hash(key, k_sz);
	ft_ll_add_front(&map->nodes[map_node->hash % map->capacity], list_node);
	map->nb_e[map_node->hash % map->capacity]++;
	map->nb_e_total++;
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
