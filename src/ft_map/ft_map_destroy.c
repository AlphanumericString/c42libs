/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:32:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdlib.h>

void	ft_map_destroy(t_map *map)
{
	free(map->nodes);
	free(map);
}

void	ft_map_destroy_free(t_map *map, void (*free_data)(void *))
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		if (map->nodes[i].used && free_data)
			free_data(map->nodes[i].data);
		i++;
	}
	ft_map_destroy(map);
}
