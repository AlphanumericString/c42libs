/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:36:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 14:42:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_map.h"

void	ft_map_set_cmp(t_map *map, t_data_cmp cmp)
{
	map->cmp = cmp;
}

void	ft_map_set_hash(t_map *map, t_memhash hash)
{
	map->hash = hash;
}

bool	ft_map_set(t_map *m, const void *k, const void *v, size_t s)
{
	t_map_node	*mn;

	if (!k || !v || !m || !s)
		return (false);
	mn = ft_map_get_node(m, k, s);
	if (mn)
		return (mn->data = (void *)v, true);
	mn = m->nodes_pool;
	if (m->nodes_pool)
		m->nodes_pool = m->nodes_pool->next;
	if (!mn)
		mn = ft_calloc(sizeof(t_map_node), 1);
	if (!mn)
		return (false);
	mn->key = k;
	mn->data = (void *)v;
	mn->hash = m->hash(k, s);
	mn->next = m->lists[mn->hash % m->capacity];
	m->lists[mn->hash % m->capacity] = mn;
	m->nb_e[mn->hash % m->capacity]++;
	m->nb_e_total++;
	return (true);
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
