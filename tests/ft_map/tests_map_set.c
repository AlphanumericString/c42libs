/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_set.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:25:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include <string.h>

/*
	// set a key in a full map
	map = ft_map_create(1);
	ft_map_set(map, "key", str, key_size);

	// set a key already existing to a new value
	ret = ft_map_set(map, "key", str2, key_size);
*/

int	test_map_set(void)
{
	const char	*str = "value";
	const char	*str2 = "value2";
	t_map		*map;
	int			ret;
	size_t		key_size;

	map = ft_map_create(10);
	key_size = strlen("key") + 1;
	ret = ft_map_set(map, "key", str, key_size);
	if (ret == 1 || map->size != 1)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, \
	key_size)].data)->used != true)
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", \
	map->capacity, key_size)].data)->key, "key"))
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", \
	map->capacity, key_size)].data)->data, "value"))
		return (1);
	ft_map_destroy(map);
	map = ft_map_create(1);
	ft_map_set(map, "key", str, key_size);
	ret = ft_map_set(map, "key2", str, key_size);
	if (ret == 1 || map->size != 2)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, \
	key_size)].data)->used != true)
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", \
	map->capacity, key_size)].data)->key, "key"))
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", \
	map->capacity, key_size)].data)->data, "value"))
		return (1);
	ret = ft_map_set(map, "key", str2, key_size);
	if (ret == 1)
		return (1);
	else if (map->size != 2)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, \
	key_size)].data)->used != true)
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, \
	key_size)].data)->key, "key"))
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, \
	key_size)].data)->data, "value2"))
		return (1);
	ft_map_destroy(map);
	return (0);
}
