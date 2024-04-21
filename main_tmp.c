/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tmp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:27:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/04/21 17:54:25 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "tests/tests.h"

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
	char	*key;
	char	*value;

	key		= strdup("keys");
	value	= strdup("values");

	map	= ft_map_create(10);
	ft_map_set(map, key, value, strlen(key));
	ft_map_destroy_free(map, NULL);
	// check we can still access the data
	key[0] = 'k';
	value[0] = 'v';

	map = ft_map_create(15);
	ft_map_set(map, key, value, strlen(key));
	ft_map_destroy_free(map, free); // free the data -> value
	
	free(key);
	return (0);
}

int	test_map_clear(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_clear(map);
	ft_map_destroy(map);
	return (0);
}

int	test_map_set(void)
{
	char	*str;
	char	*str2;
	t_map	*map;
	int		ret;
	size_t	key_size;

	str = strdup("value");
	str2 = strdup("value2");
	map = ft_map_create(10);
	key_size = strlen("key") + 1;
	ret = ft_map_set(map, "key", str, key_size);
	if (ret == 1)
		return (1);
	else if (map->size != 1)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->used != true)
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->key, "key"))
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->data, "value"))
		return (1);
	ft_map_destroy(map);
	// set a key in a full map
	map = ft_map_create(1);
	ft_map_set(map, "key", str, key_size);
	ret = ft_map_set(map, "key2", str, key_size);
	if (ret == 0)
		return (1);
	else if (map->size != 2)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->used != true)
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->key, "key"))
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->data, "value"))
		return (1);
	// set a key already existing to a new value
	ret = ft_map_set(map, "key", str2, key_size);
	if (ret == 1)
		return (1);
	else if (map->size != 1)
		return (1);
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->used != true)
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->key, "key"))
		return (1);
	else if (strcmp(((t_map_node *)map->nodes[map->hash("key", map->capacity, key_size)].data)->data, "value2"))
		return (1);
	ft_map_destroy(map);
	free(str);
	free(str2);
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
	else if (((t_map_node *)map->nodes[map->hash("key", map->capacity, 5)].data)->used != false)
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
	ft_map_destroy(map);
	free(str);
	return (0);
}

// we dont really test the hash function, we just test that 
// it doesn't overflow our map
int	test_map_hash(void)
{
	size_t	ret;

	ret = ft_hash_djb2("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	ret = ft_hash_sdbm("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	ret = ft_hash_fnv1a("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	ret = ft_hash_dummy("key", 10, strlen("key") + 1);
	if (ret >= 10)
		return (1);
	return (0);
}

int		main(void)
{
	t_test test[] = {
		{"test_map_create", test_map_create},
		{"test_map_destroy", test_map_destroy},
		{"test_map_destroy_free", test_map_destroy_free},
		{"test_map_clear", test_map_clear},
		{"test_map_set", test_map_set},
		{"test_map_set_cmp", test_map_set_cmp},
		{"test_map_set_hash", test_map_set_hash},
		{"test_map_get", test_map_get},
		{"test_map_size", test_map_size},
		{"test_map_capacity", test_map_capacity},
		{"test_map_remove", test_map_remove},
		{"test_map_hash", test_map_hash},
		{NULL, NULL}
	};
	int	collect;
	int i = 0;

	collect = 0;
	for (; test[i].name != NULL; i++)
	{
		if (test[i].test() == 0)
			printf("%s: \033[0;32mOK\033[0m\n", test[i].name);
		else
		{
			printf("%s: \033[0;31mKO\033[0m\n", test[i].name);
			collect++;
		}
	}
	return (collect);
}

//  gcc src/ft_map/*.c src/ft_list/ft_ll/*.c src/ft_string/ft_str/*.c src/ft_string/ft_mem/*.c tools/main_tmp.c -g2 -Iinclude -Wall -Wextra