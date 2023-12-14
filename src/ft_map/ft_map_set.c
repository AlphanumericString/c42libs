/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:36:14 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/14 15:29:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

int	ft_map_set(t_map *map, void *key, void *value, size_t size)
{
	size_t		index[2];

	index[0] = map->hash(key, map->capacity, size);
	index[1] = index[0];
	while (map->nodes[index[0]].used)
	{
		if (!map->cmp(map->nodes[index[0]++].key, key))
		{
			index[0]--;
			break ;
		}
		index[0] %= map->capacity;
		if (index[1] == index[0])
			return (1);
	}
	if (!map->nodes[index[0]].used)
	{
		map->nodes[index[0]].key = key;
		map->size++;
	}
	map->nodes[index[0]].used = true;
	map->nodes[index[0]].data = value;
	return (0);
}

void	ft_map_set_cmp(t_map *map, int (*cmp)(void *, void *))
{
	map->cmp = cmp;
}

void	ft_map_set_hash(t_map *map, size_t (*hash)(void *, size_t, size_t))
{
	map->hash = hash;
}
