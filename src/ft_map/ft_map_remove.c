/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 16:11:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_map_remove(t_map *map, const void *key, size_t size)
{
	size_t		index;
	t_list		*node;
	t_map_node	*map_node;

	index = map->hash(key, map->capacity, size);
	node = &map->nodes[index];
	map_node = (t_map_node *)node->data;
	while (node && map_node->used && map->cmp(map_node->key, key))
	{
		node = node->next;
		map_node = (t_map_node *)node->data;
	}
	if (node && map_node->used)
	{
		map_node->used = false;
		map->size--;
	}
}
