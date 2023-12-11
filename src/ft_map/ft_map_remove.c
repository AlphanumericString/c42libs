/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:09:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_map_remove(t_map *map, void *key, size_t size)
{
	size_t	index[2];

	index[0] = map->hash(key, map->capacity);
	index[1] = index[0];
	while (map->nodes[index[0]].used)
	{
		if (!map->cmp(map->nodes[index[0]].key, key, size))
		{
			map->nodes[index[0]].used = 0;
			map->size--;
			return ;
		}
		index[0] = (index[0] + 1) % map->capacity;
		if (index[1] == index[0])
			return ;
	}
}
