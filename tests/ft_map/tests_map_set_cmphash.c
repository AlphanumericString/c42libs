/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_set_cmphash.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:13:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests__all_modules_tests.h"
#include "ft_map.h"
#include "types/ft_map_types.h"

int	tm_set_cmp(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set_cmp(map, NULL);
	if (map->cmp)
		return (1);
	ft_map_destroy(map);
	return (0);
}

int	tm_set_hash(void)
{
	t_map	*map;

	map = ft_map_create(10);
	ft_map_set_hash(map, NULL);
	if (map->hash)
		return (1);
	ft_map_destroy(map);
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
