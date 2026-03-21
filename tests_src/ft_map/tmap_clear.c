/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:11:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "types/ft_map_types.h"
#include "ft_string.h"
#include "tests/map_tests.h"

// clear the map and check if the value is still present
// try to double clear the map

int	tmap_clear(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set(map, "key", "value", ft_strlen("key"));
	ft_map_clear(map);
	if (ft_map_get(map, "key", ft_strlen("key")) != NULL)
		return (ft_map_destroy(map), 1);
	ft_map_clear(map);
	return (ft_map_destroy(map), EXIT_SUCCESS);
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
