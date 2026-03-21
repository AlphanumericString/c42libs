/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_get.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:14:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	// search for a non existing key
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	---
	// search for a non existing key in a full map
	map = ft_map_create(1);
*/

#include "tests/map_tests.h"
#include "ft_mem.h"
#include "ft_map.h"
#include "types/ft_map_types.h"
#include "ft_string.h"
#include <stdlib.h>

static size_t	colision_prone_hash(const void *p, size_t s)
{
	(void)p;
	(void)s;
	return (42);
}

static int	tmap_get_ultra_small(void)
{
	char		*str[2];
	t_map		*map;
	void		*ret;

	str[0] = ft_strdup("value");
	str[1] = ft_strdup("value2");
	map = ft_map_create(1);
	ft_map_set(map, "my_specific_key", str[0], ft_strlen("my_specific_key"));
	ft_map_set(map, "key2", str[1], ft_strlen("key2"));
	ret = ft_map_get(map, "my_specific_key", ft_strlen("my_specific_key"));
	if (!ret)
		return (ft_map_destroy_free(map, ft_free), 1);
	else if (ft_strcmp((char *)ret, "value"))
		return (ft_map_destroy_free(map, ft_free), 2);
	ret = ft_map_get(map, "key2", ft_strlen("key2"));
	if (!ret)
		return (ft_map_destroy_free(map, ft_free), 3);
	else if (ft_strcmp((char *)ret, "value2"))
		return (ft_map_destroy_free(map, ft_free), 4);
	return (ft_map_destroy_free(map, ft_free), EXIT_SUCCESS);
}

static int	tmap_normal(void)
{
	char		*str;
	t_map		*map;
	void		*ret;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ft_map_set(map, "differing_key", str, ft_strlen("differing_key"));
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (!ret || ft_strcmp((char *)ret, "value"))
		return (ft_map_destroy_free(map, ft_free), 1);
	if (ft_map_get(map, "key2", ft_strlen("key2")) != NULL)
		return (ft_map_destroy_free(map, ft_free), 2);
	ft_map_destroy(map);
	map = ft_map_create(10);
	ft_map_set_hash(map, colision_prone_hash);
	ft_map_set(map, "key", "value_prime", ft_strlen("key"));
	ft_map_set(map, "differing_key2", str, ft_strlen("differing_key2"));
	ret = ft_map_get(map, "differing_key2", ft_strlen("differing_key2"));
	if (!ret || ft_strcmp((char *)ret, "value"))
		return (ft_map_destroy(map), ft_free(str), 3);
	return (ft_map_destroy(map), ft_free(str), EXIT_SUCCESS);
}

static int	tmap_get_null(void)
{
	t_map		*map;

	map = ft_map_create(10);
	if (ft_map_get(map, "badkey", ft_strlen("badkey")) != NULL)
		return (ft_map_destroy(map), 1);
	if (ft_map_get(NULL, "empty_map", ft_strlen("empty_map")) != NULL)
		return (ft_map_destroy(map), 2);
	if (ft_map_get(map, NULL, ft_strlen("bad_arg")) != NULL
		|| ft_map_get(map, "bad_arg", 0) != NULL)
		return (ft_map_destroy(map), 3);
	return (ft_map_destroy(map), EXIT_SUCCESS);
}

// missing code coverage on hash collisions
int	tmap_get(void)
{
	int	ret;

	ret = tmap_get_ultra_small();
	if (ret != EXIT_SUCCESS)
		return (ret + 10 * 0);
	ret = tmap_normal();
	if (ret != EXIT_SUCCESS)
		return (ret + 10 * 1);
	ret = tmap_get_null();
	if (ret != EXIT_SUCCESS)
		return (ret + 10 * 2);
	return (EXIT_SUCCESS);
}
/*
GPL-3.0 License:
c42libs - Library for c projects at 42.
Copyright (C) 2025  baptiste GOULARD

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/
