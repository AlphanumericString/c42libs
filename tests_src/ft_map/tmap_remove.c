/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/map_tests.h"
#include "ft_map.h"
#include "ft_string.h"
#include "types/ft_map_types.h"
#include "ft_string.h"

static size_t	colision_prone_hash(const void *p, size_t s)
{
	(void)p;
	(void)s;
	return (42);
}

// map of size 1 to check list handling
static int	tmap_remove_normal(void)
{
	const void	*data = (void *)0xDEADBEAF;
	const void	*data2 = (void *)0xBEAFCAFE;
	void		*ret;
	t_map		*map;

	map = ft_map_create(1);
	if (ft_map_remove(NULL, "key", ft_strlen("key")) != NULL
		|| ft_map_remove(map, NULL, ft_strlen("key")) != NULL
		|| ft_map_remove(map, "key", 0) != NULL
		|| ft_map_remove(map, "empty_map", ft_strlen("empty_map")) != NULL)
		return (ft_map_destroy(map), 1);
	ft_map_set(map, "key", data, ft_strlen("key"));
	ft_map_set(map, "key2", data2, ft_strlen("key2"));
	ret = ft_map_remove(map, "key", ft_strlen("key"));
	if (!ret || ret != data)
		return (ft_map_destroy(map), 2 + (ret != NULL));
	if (ft_map_remove(map, "badkey", ft_strlen("badkey")) != NULL)
		return (ft_map_destroy(map), 4);
	ret = ft_map_remove(map, "key2", ft_strlen("key2"));
	if (!ret || ret != data2)
		return (ft_map_destroy(map), 5);
	return (ft_map_destroy(map), EXIT_SUCCESS);
}

static int	tmap_remove_colision(void)
{
	const char		*key = "key_target";
	const size_t	kl = ft_strlen(key);
	t_map			*map;
	void			*ret;
	const void		*data = (void *)0xDEADCAFE;

	map = ft_map_create(10);
	ft_map_set_hash(map, colision_prone_hash);
	ft_map_set(map, key, data, kl);
	ft_map_set(map, "colision", &ft_map_create, ft_strlen("colision"));
	ft_map_set(map, "colision2", &ft_map_remove, ft_strlen("colision2"));
	if (ft_map_get(map, key, kl) != data)
		return (ft_map_destroy(map), 1);
	ret = ft_map_remove(map, key, kl);
	if (ret != data)
		return (ft_map_destroy(map), 2);
	return (ft_map_destroy(map), EXIT_SUCCESS);
}

int	tmap_remove(void)
{
	int	ret;

	ret = tmap_remove_normal();
	if (ret != 0)
		return (ret);
	ret = tmap_remove_colision();
	if (ret != 0)
		return (ret + 10);
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
