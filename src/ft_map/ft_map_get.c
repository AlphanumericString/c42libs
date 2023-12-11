/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:06:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	*ft_map_get(t_map *map, void *key, size_t size)
{
	size_t	index[2];

	index[0] = map->hash(key, map->capacity);
	index[1] = index[0];
	while (map->nodes[index[0]].used)
	{
		if (!map->cmp(map->nodes[index[0]].key, key, size))
			return (map->nodes[index[0]].data);
		index[0]++;
		index[0] %= map->capacity;
		if (index[1] == index[0])
			return (NULL);
	}
	return (NULL);
}
