/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:14:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	// search for a non existing key
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	---
	// search for a non existing key in a full map
	map = ft_map_create(1);
*/

#include "tests/tests__all_modules_tests.h"
#include "ft_map.h"
#include "types/ft_map_types.h"
#include "ft_string.h"
#include <stdlib.h>

static int	test_map_get_ultra_small(void)
{
	char		*str[2];
	t_map		*map;
	void		*ret;

	str[0] = ft_strdup("value");
	str[1] = ft_strdup("value2");
	map = ft_map_create(1);
	ft_map_set(map, "key", str[0], ft_strlen("key"));
	ft_map_set(map, "key2", str[1], ft_strlen("key"));
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (!ret)
		return (1);
	else if (ft_strcmp((char *)ret, "value"))
		return (2);
	ret = ft_map_get(map, "key2", ft_strlen("key2"));
	if (!ret)
		return (3);
	else if (ft_strcmp((char *)ret, "value2"))
		return (4);
	ft_map_destroy_free(map, ft_free);
	return (0);
}

static int	test_map_normal(void)
{
	char		*str;
	t_map		*map;
	void		*ret;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (!ret)
		return (1);
	else if (ft_strcmp((char *)ret, "value"))
		return (2);
	ret = ft_map_get(map, "key2", ft_strlen("key2"));
	if (ret)
		return (3);
	ret = ft_map_get(NULL, "key", ft_strlen("key"));
	if (ret)
		return (4);
	ret = ft_map_get(map, NULL, ft_strlen("key"));
	if (ret)
		return (5);
	ft_map_destroy(map);
	ft_free(str);
	return (0);
}

static int	test_map_get_null(void)
{
	t_map		*map;
	t_map_node	*node;
	void		*ret;

	map = ft_map_create(10);
	ret = ft_map_get(map, "key", ft_strlen("key"));
	if (ret)
		return (1);
	ret = ft_map_get(NULL, "key", ft_strlen("key"));
	if (ret)
		return (2);
	ret = ft_map_get(map, NULL, ft_strlen("key"));
	if (ret)
		return (3);
	node = ft_map_get_node(NULL, "key", ft_strlen("key"));
	if (node)
		return (4);
	ft_map_destroy(map);
	return (0);
}

int	test_map_get(void)
{
	int	ret;

	ret = test_map_get_ultra_small();
	if (ret != 0)
		return (ret + 10 * 0);
	ret = test_map_normal();
	if (ret != 0)
		return (ret + 10 * 1);
	ret = test_map_get_null();
	if (ret != 0)
		return (ret + 10 * 2);
	return (0);
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
