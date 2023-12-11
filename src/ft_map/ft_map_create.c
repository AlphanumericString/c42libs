/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:11:41 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:26:07 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_string.h"

t_map	*ft_map_create(size_t size)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->capacity = size;
	map->size = 0;
	map->nodes = ft_calloc(sizeof(map->nodes), size);
	map->hash = &ft_map_hash;
	map->cmp = (int (*)(void *, void *, size_t)) & ft_strncmp;
	if (!map->nodes)
		return (free(map), NULL);
	return (map);
}
