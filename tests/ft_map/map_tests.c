/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:27:46 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 19:28:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void	test_map_create(void)
{
	t_map	*map;

	map = ft_map_create(10);
	if (map == NULL)
		printf("ft_map_create: [FAIL] returned NULL\n");
	else
		printf("ft_map_create: [OK]\n");
	ft_map_destroy(map);
}

void	test_map_destroy(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_destroy(map);
	printf("ft_map_destroy: [OK]\n");
}

void	test_map_destroy_free(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_destroy_free(map, NULL);
	printf("ft_map_destroy_free: [OK]\n");
}

void	test_map_clear(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_clear(map);
	printf("ft_map_clear: [OK]\n");
	ft_map_destroy(map);
}

void	test_map_set(void)
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
		printf("ft_map_set: [FAIL] returned 1\n");
	else if (map->size != 1)
		printf("ft_map_set: [FAIL] map->size != 1\n");
	else if (map->nodes[map->hash("key", map->capacity, key_size)].used != true)
		printf("ft_map_set: [FAIL] map->nodes[map->hash(\"key\", map->capacity, key_size)].used != true (%d != 1)\n", map->nodes[map->hash("key", map->capacity, key_size)].used);
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].key, "key"))
		printf("ft_map_set: [FAIL] map->nodes[map->hash(\"key\", map->capacity, key_size)].key != \"key\"\n");
	else if (strcmp(map->nodes[map->hash("key", map->capacity, key_size)].data, "value"))
		printf("ft_map_set: [FAIL] strcmp(map->nodes[map->hash(\"key\", map->capacity, key_size)].data, \"value\")\n");
	else
		printf("ft_map_set: [OK]\n");
	ft_map_destroy(map);
	free(str);
}

void	test_map_set_cmp(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set_cmp(map, NULL);
	if (map->cmp != NULL)
		printf("ft_map_set_cmp: [FAIL] cmp is not NULL\n");
	else
		printf("ft_map_set_cmp: [OK]\n");
	ft_map_destroy(map);
}

void	test_map_set_hash(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set_hash(map, NULL);
	if (map->hash != NULL)
		printf("ft_map_set_hash: [FAIL] hash is not NULL\n");
	else
		printf("ft_map_set_hash: [OK]\n");
	ft_map_destroy(map);
}

void	test_map_get(void)
{
	char	*str;
	t_map	*map;
	char	*ret;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen(str) + 1);
	ret = ft_map_get(map, "key", strlen("key") + 1);
	if (ret == NULL)
		printf("ft_map_get: [FAIL] returned NULL\n");
	else if (strcmp(ret, "value"))
		printf("ft_map_get: [FAIL] strcmp(ret, \"value\")\n");
	else
		printf("ft_map_get: [OK]\n");
	ft_map_destroy(map);
	free(str);
}

void	test_map_size(void)
{
	char	*str;
	t_map	*map;
	size_t	ret;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen(str) + 1);
	ret = ft_map_size(map);
	if (ret != 1)
		printf("ft_map_size: [FAIL] ret != 1\n");
	else
		printf("ft_map_size: [OK]\n");
	ft_map_destroy(map);
	free(str);
}

void	test_map_capacity(void)
{
	char	*str;
	t_map	*map;
	size_t	ret;

	str = strdup("value");
	map = ft_map_create(10);
	ret = ft_map_capacity(map);
	if (ret != 10)
		printf("ft_map_capacity: [FAIL] ret != 10\n");
	else
		printf("ft_map_capacity: [OK]\n");
	ft_map_destroy(map);
	free(str);
}

void	test_map_remove(void)
{
	char	*str;
	t_map	*map;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen(str) + 1);
	ft_map_remove(map, "key", strlen("key") + 1);
	if (map->size != 0)
		printf("ft_map_remove: [FAIL] map->size != 0\n");
	else if (map->nodes[map->hash("key", map->capacity, 5)].used != false)
		printf("ft_map_remove: [FAIL] map->nodes[map->hash(\"key\", map->capacity, 5)].used != false\n");
	else
		printf("ft_map_remove: [OK]\n");
	ft_map_destroy(map);
	free(str);
}

void	test_map_hash(void)
{
	size_t	ret;

	ret = ft_map_hash("key", 10, strlen("key") + 1);
	printf("ft_map_hash: [OK]\n");
}

int		main(void)
{
	test_map_create();
	test_map_destroy();
	test_map_destroy_free();
	test_map_clear();
	test_map_set();
	test_map_set_cmp();
	test_map_set_hash();
	test_map_get();
	test_map_size();
	test_map_capacity();
	test_map_remove();
	test_map_hash();
	return (0);
}
