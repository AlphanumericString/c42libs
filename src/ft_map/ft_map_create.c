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

#include "ft_map.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "ft_vector.h"

t_map	*ft_map_create(size_t size)
{
	t_map	*map;

	map = ft_calloc(1, sizeof(t_map));
	if (!map)
		return (0);
	map->capacity = size;
	map->w_total = 0;
	map->weights = ft_calloc(size, sizeof(size_t));
	if (!map->weights)
		return (ft_free(map), NULL);
	map->nodes = ft_calloc(size, sizeof(t_list *));
	if (!map->nodes)
		return (ft_free(map->weights), ft_free(map), NULL);
	map->hash = &ft_hash_djb2;
	map->cmp = (int (*)(const void *, const void *)) & ft_strcmp;
	map->reserved_nodes = ft_vec_new();
	if (!map->reserved_nodes)
		return (ft_free(map->weights), ft_free(map->nodes), ft_free(map), NULL);
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
