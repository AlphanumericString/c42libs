/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/12 11:29:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_map_node	*ft_map_get(t_map *map, void *key, size_t size)
{
	size_t	index[2];

	index[0] = map->hash(key, map->capacity, size);
	index[1] = index[0];
	while (map->nodes[index[0]].used)
	{
		if (!map->cmp(map->nodes[index[0]].key, key))
			return (map->nodes[index[0]].data);
		index[0]++;
		index[0] %= map->capacity;
		if (index[1] == index[0])
			return (NULL);
	}
	return (NULL);
}

size_t	ft_map_size(t_map *map)
{
	return (map->size);
}

size_t	ft_map_capacity(t_map *map)
{
	return (map->capacity);
}
