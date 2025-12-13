/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/13 21:33:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/fixtures.h"
#include "tests/map_tests.h"
#include "ft_map.h"
#include "ft_string.h"

static int	tmap_set_normal(void)
{
	const void	*data1 = (void *)0xDEAD;
	const void	*data2 = (void *)0xBEEF;
	t_map		*map;

	map = ft_map_create(1);
	if (ft_map_set(map, "key", data1, ft_strlen("key")) != true)
		return (ft_map_destroy(map), 1);
	if (ft_map_get(map, "key", ft_strlen("key")) != data1)
		return (ft_map_destroy(map), 2);
	if (ft_map_set(map, "key", data2, ft_strlen("key")) != true
		|| ft_map_get(map, "key", ft_strlen("key")) != data2)
		return (ft_map_destroy(map), 3);
	return (ft_map_destroy(map), EXIT_SUCCESS);
}

static int	tmap_set_null(void)
{
	const void	*data1 = (void *)0xDEAD;
	t_map		*map;

	map = ft_map_create(1);
	if (ft_map_set(NULL, "key", data1, ft_strlen("key")) != false)
		return (ft_map_destroy(map), 1);
	if (ft_map_set(map, NULL, data1, ft_strlen("key")) != false)
		return (ft_map_destroy(map), 2);
	if (ft_map_set(map, "key", NULL, ft_strlen("key")) != true)
		return (ft_map_destroy(map), 3);
	if (ft_map_set(map, "key", data1, 0) != false)
		return (ft_map_destroy(map), 4);
	return (ft_map_destroy(map), EXIT_SUCCESS);
}

static int	tmap_reuse_node(void)
{
	const void	*data1 = (void *)0xDEAD;
	const void	*data2 = (void *)0xBEEF;
	t_map		*map;
	t_map_node	*mn;

	map = ft_map_create(1);
	ft_map_set(map, "key1", data1, ft_strlen("key1"));
	ft_map_set(map, "key2", data2, ft_strlen("key2"));
	mn = map->lists[0];
	if (map->nodes_pool != NULL)
		return (ft_map_destroy(map), 1);
	ft_map_remove(map, "key2", ft_strlen("key2"));
	if (map->nodes_pool == NULL)
		return (ft_map_destroy(map), 2);
	if (mn != map->nodes_pool)
		return (ft_map_destroy(map), 3);
	ft_map_set(map, "key2", data2, ft_strlen("key2"));
	if (map->nodes_pool != NULL)
		return (ft_map_destroy(map), 4);
	return (ft_map_destroy(map), EXIT_SUCCESS);
}

static int	tmap_alloc_fail(void)
{
	const size_t	fp = *talloc_get_failpoint();
	const void		*data1 = (void *)0xDEAD;
	t_map			*map;
	int				res;

	map = ft_map_create(1);
	res = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	if (ft_map_set(map, "key", data1, ft_strlen("key")) != false)
		res = 1;
	talloc_set_failpoint(fp);
	return (ft_map_destroy(map), res);
}

int	tmap_set(void)
{
	int	ret;

	ret = tmap_set_normal();
	if (ret)
		return (ret + 10 * 0);
	ret = tmap_set_null();
	if (ret)
		return (ret + 10 * 1);
	ret = tmap_reuse_node();
	if (ret)
		return (ret + 10 * 2);
	ret = tmap_alloc_fail();
	if (ret)
		return (ret + 10 * 3);
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
