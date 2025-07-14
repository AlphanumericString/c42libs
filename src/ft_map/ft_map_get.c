/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 14:23:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_map_node	*ft_map_get_node(t_map *map, const void *key, size_t size)
{
	t_list		*bucket;
	t_map_node	*map_node;

	if (!map || !key)
		return (NULL);
	bucket = map->nodes[map->hash(key, size) % map->capacity];
	map_node = NULL;
	while (bucket)
	{
		map_node = bucket->data;
		if (map->cmp(map_node->key, key) == 0)
			break ;
		bucket = bucket->next;
	}
	if (map_node && map->cmp(map_node->key, key) == 0)
		return (map_node);
	return (NULL);
}

void	*ft_map_get(t_map *map, const void *key, size_t size)
{
	t_map_node	*map_node;

	if (!map)
		return (NULL);
	map_node = ft_map_get_node(map, key, size);
	if (!map_node)
		return (NULL);
	return (map_node->data);
}

size_t	ft_map_size(const t_map *map)
{
	return (map->w_total);
}

size_t	ft_map_capacity(const t_map *map)
{
	return (map->capacity);
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
