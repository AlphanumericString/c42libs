/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_create.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:11:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:23:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_map.h"
#include "ft_string.h"

t_map	*ft_map_create(size_t capacity)
{
	t_map	*map;

	if (!capacity)
		return (NULL);
	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (NULL);
	map->hash = ft_hash_djb2;
	map->cmp = (t_any) ft_strcmp;
	map->nb_e = ft_calloc(capacity, sizeof(size_t));
	map->lists = ft_calloc(capacity, sizeof(t_map_node));
	if (!map->nb_e || !map->lists)
		return (ft_free(map->nb_e), ft_free(map->lists), ft_free(map), NULL);
	map->capacity = capacity;
	return (map);
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
