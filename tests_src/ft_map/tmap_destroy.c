/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/map_tests.h"
#include "ft_map.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "types/ft_map_types.h"
#include <stdlib.h>

// check valgrind for no memory leak
// setting nodes to check node freeing path
// removing node to check node reuse pool freeing path
int	tmap_destroy(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set(map, "key1", "value1", ft_strlen("key1"));
	ft_map_set(map, "key2", "value2", ft_strlen("key2"));
	ft_map_remove(map, "key1", ft_strlen("key1"));
	ft_map_destroy(map);
	map = NULL;
	ft_map_destroy(map);
	ft_map_destroy(NULL);
	return (EXIT_SUCCESS);
}

// accessing to key[0] and value[0] after the call to check
// that no ft_free occured on the data at first call
int	tmap_destroy_free(void)
{
	t_map	*map;
	char	*key;
	char	*value;

	ft_map_destroy_free(NULL, NULL);
	ft_map_destroy_free(NULL, ft_free);
	key = ft_strdup("keys");
	value = ft_strdup("values");
	map = ft_map_create(10);
	ft_map_set(map, key, value, ft_strlen(key));
	ft_map_destroy_free(map, NULL);
	key[0] = 'k';
	value[0] = 'v';
	map = ft_map_create(15);
	ft_map_set(map, key, value, ft_strlen(key));
	ft_map_destroy_free(map, ft_free);
	ft_free(key);
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
