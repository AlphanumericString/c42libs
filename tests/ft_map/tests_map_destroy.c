/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_destroy.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 13:53:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_string.h"
#include "ft_map_types.h"
#include <stdlib.h>

// check valgrind for no memory leak
int	test_map_destroy(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_destroy(map);
	map = NULL;
	ft_map_destroy(map);
	ft_map_destroy(NULL);
	return (0);
}

// accessing to key[0] and value[0] after the call to check
// that no ft_free occured on the data at first call
int	test_map_destroy_free(void)
{
	t_map	*map;
	char	*key;
	char	*value;

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
