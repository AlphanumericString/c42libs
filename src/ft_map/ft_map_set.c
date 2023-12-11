/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:36:14 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:05:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int ft_map_set(t_map *map, void *key, void *value, size_t size)
{
	size_t		index[2];
	t_map_node	node;

	index[0] = map->hash(key, map->capacity);
	index[1] = index[0];
	while (map->nodes[index[0]].used)
	{
		if (!map->cmp(map->nodes[index[0]++].key, key, size))
		{
			node = map->nodes[index[0] - 1];
			break;
		}
		index[0] %= map->capacity;
		if (index[1] == index[0])
			return (1);
	}
	if (!node.used)
		node.key = key;
	return (map->size++, node.used = true, node.data = value, 0);
}

void ft_map_set_cmp(t_map *map, int (*cmp)(void *, void *, size_t))
{
	map->cmp = cmp;
}


void ft_map_set_hash(t_map *map, size_t (*hash)(void *, size_t))
{
	map->hash = hash;
}
