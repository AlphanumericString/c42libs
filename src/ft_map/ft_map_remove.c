/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_remove.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:08:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:23:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_map_types.h"
#include "types/ft_list_types.h"

#include "ft_map.h"
#include "ft_vector.h"

void	*ft_map_remove(t_map *map, const void *key, size_t size)
{
	size_t		hash;
	t_list		*prev;
	t_list		*cur;

	hash = map->hash(key, size) % map->capacity;
	prev = NULL;
	cur = map->nodes[hash];
	while (cur)
	{
		if (map->cmp(((t_map_node *)cur->data)->key, key) == 0)
			break ;
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (NULL);
	if (!prev)
		map->nodes[hash] = cur->next;
	else
		prev->next = cur->next;
	cur->next = NULL;
	ft_vec_add(map->reserved_nodes, &cur);
	map->nb_e[hash]--;
	map->nb_e_total--;
	return (((t_map_node *)cur->data)->data);
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
