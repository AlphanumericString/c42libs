/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:27:46 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/14 15:30:01 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int	test_map_create(void)
{
	t_map	*map;

	map = ft_map_create(10);
	if (map == NULL)
		return (1);	
	ft_map_destroy(map);
	return (0);
}

int	test_map_destroy(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_destroy(map);
	return (0);
}

int	test_map_destroy_free(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_destroy_free(map, NULL);
	return (0);
}

int	test_map_clear(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_clear(map);
	return (0);
	ft_map_destroy(map);
	return (0);
}

int	test_map_set(void)
{
	char	*str;
	t_map	*map;
	int		ret;
	size_t	key_size;

	str = strdup("value");
	map = ft_map_create(10);
	key_size = strlen("key") + 1;
	ret = ft_map_set(map, "key", str, key_size);
	if (ret == 1)
		return (1);
	else if (map->size != 1)
		return (1);
	else if (map->nodes[map->hash("key", map->capacity, key_size)].used != true)
		return (1);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].key, "key"))
		return (1);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].data, "value"))
		return (1);
	ft_map_destroy(map);
	// set a key in a full map
	map = ft_map_create(1);
	ft_map_set(map, "key", str, key_size);
	ret = ft_map_set(map, "key2", str, key_size);
	if (ret == 0)
		return (1);
	else if (map->size != 1)
		return (1);
	else if (map->nodes[map->hash("key", map->capacity, key_size)].used != true)
		return (1);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].key, "key"))
		return (1);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].data, "value"))
		return (1);
	// set a key already existing to a new value
	ret = ft_map_set(map, "key", str, key_size);
	if (ret == 1)
		return (1);
	else if (map->size != 1)
		return (1);
	else if (map->nodes[map->hash("key", map->capacity, key_size)].used != true)
		return (1);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].key, "key"))
		return (1);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].data, "value"))
		return (1);
	ft_map_destroy(map);
	free(str);
	return (0);
}

int	test_map_set_cmp(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set_cmp(map, NULL);
	if (map->cmp != NULL)
		return (1);
	
	ft_map_destroy(map);
	return (0);
}

int	test_map_set_hash(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set_hash(map, NULL);
	if (map->hash != NULL)
		return (1);
	
	ft_map_destroy(map);
	return (0);
}

int	test_map_get(void)
{
	char		*str;
	t_map		*map;
	t_map_node	*ret;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen("key") + 1);
	ret = ft_map_get(map, "key", strlen("key") + 1);
	if (ret == NULL)
		return (1);
	else if (strcmp((char *)ret->data, "value"))
		return (1);
	// search for a non existing key
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	if (ret != NULL)
		return (1);
	ft_map_destroy(map);
	// search for a non existing key in a full map
	map = ft_map_create(1);
	ft_map_set(map, "key", str, strlen("key") + 1);
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	if (ret != NULL)
		return (1);
	ft_map_destroy(map);
	free(str);
	return (0);
}

int	test_map_size(void)
{
	char	*str;
	t_map	*map;
	size_t	ret;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen(str) + 1);
	ret = ft_map_size(map);
	if (ret != 1)
		return (1);
	
	ft_map_destroy(map);
	free(str);
	return (0);
}

int	test_map_capacity(void)
{
	char	*str;
	t_map	*map;
	size_t	ret;

	str = strdup("value");
	map = ft_map_create(10);
	ret = ft_map_capacity(map);
	if (ret != 10)
		return (1);
	
	ft_map_destroy(map);
	free(str);
	return (0);
}

int	test_map_remove(void)
{
	char	*str;
	t_map	*map;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen("key") + 1);
	ft_map_remove(map, "key", strlen("key") + 1);
	if (map->size != 0)
		return (1);
	else if (map->nodes[map->hash("key", map->capacity, 5)].used != false)
		return (1);
	// remove a non existing key
	ft_map_remove(map, "key", strlen("key") + 1);
	if (map->size != 0)
		return (1);
	// remove a non existing key in a full map
	ft_map_destroy(map);
	map = ft_map_create(1);
	ft_map_set(map, "key", str, strlen("key") + 1);
	ft_map_remove(map, "key2", strlen("key2") + 1);
	if (map->size != 1)
		return (1);
	free(str);
	return (0);
}

int	test_map_hash(void)
{
	size_t	ret;

	ret = ft_map_hash("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	return (0);
}

int		tests_map(void)
{
	int	ret;

	ret = 0;
	if (test_map_create())
	{
		printf("test_map_create: [KO]\n");
		ret++;
	}
	if (test_map_destroy())
	{
		printf("test_map_destroy: [KO]\n");
		ret++;
	}
	if (test_map_destroy_free())
	{
		printf("test_map_destroy_free: [KO]\n");
		ret++;
	}
	if (test_map_clear())
	{
		printf("test_map_clear: [KO]\n");
		ret++;
	}
	if (test_map_set())
	{
		printf("test_map_set: [KO]\n");
		ret++;
	}
	if (test_map_set_cmp())
	{
		printf("test_map_set_cmp: [KO]\n");
		ret++;
	}
	if (test_map_set_hash())
	{
		printf("test_map_set_hash: [KO]\n");
		ret++;
	}
	if (test_map_get())
	{
		printf("test_map_get: [KO]\n");
		ret++;
	}
	if (test_map_size())
	{
		printf("test_map_size: [KO]\n");
		ret++;
	}
	if (test_map_capacity())
	{
		printf("test_map_capacity: [KO]\n");
		ret++;
	}
	if (test_map_remove())
	{
		printf("test_map_remove: [KO]\n");
		ret++;
	}
	if (test_map_hash())
	{
		printf("test_map_hash: [KO]\n");
		ret++;
	}
	return (ret);
}
