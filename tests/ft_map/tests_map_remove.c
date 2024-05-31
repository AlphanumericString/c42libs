/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:53 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 16:14:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include "ft_string.h"
#include <stdlib.h>

/*
	// remove a non existing key
	ft_map_remove(map, "key", ft_strlen("key") + 1);
	---
	// remove a non existing key in a full map
	ft_map_destroy(map);
*/

int	test_map_remove(void)
{
	char	*str;
	t_map	*map;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key") + 1);
	ft_map_remove(map, "key", ft_strlen("key") + 1);
	if (map->size != 0)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, \
	ft_strlen("key") + 1)].data)->used != false)
		return (1);
	ft_map_remove(map, "key", ft_strlen("key") + 1);
	if (map->size != 0)
		return (1);
	ft_map_destroy(map);
	map = ft_map_create(1);
	ft_map_set(map, "key", str, ft_strlen("key") + 1);
	ft_map_remove(map, "key2", ft_strlen("key2") + 1);
	if (map->size != 1)
		return (1);
	ft_map_destroy(map);
	free(str);
	return (0);
}
