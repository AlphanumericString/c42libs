/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:05:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/11 14:23:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

t_map_node	*ft_map_get_node(const t_map *m, const void *k, size_t s)
{
	t_map_node	*cur;
	size_t		s_hash;

	if (!m || !k || !s)
		return (NULL);
	s_hash = m->hash(k, s);
	cur = m->lists[s_hash % m->capacity];
	while (cur)
	{
		if (cur->hash == s_hash && m->cmp(cur->key, k) == 0)
			break ;
		cur = cur->next;
	}
	return (cur);
}

void	*ft_map_get(const t_map *map, const void *k, size_t size)
{
	t_map_node	*mn;

	mn = ft_map_get_node(map, k, size);
	if (mn)
		return (mn->data);
	return (NULL);
}

size_t	ft_map_size(const t_map *restrict map)
{
	return (map->nb_e_total);
}

size_t	ft_map_capacity(const t_map *restrict map)
{
	return (map->capacity);
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
