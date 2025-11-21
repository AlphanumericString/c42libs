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

#include "ft_map.h"
#include <stdio.h>

static void	push_to_pool(t_map_node *prev, t_map_node *cur, t_map *m, size_t sh)
{
	if (!prev)
		m->lists[sh % m->capacity] = cur->next;
	else
		prev->next = cur->next;
	cur->next = m->nodes_pool;
	m->nodes_pool = cur;
	m->nb_e_total--;
	m->nb_e[sh % m->capacity]--;
}

void	*ft_map_remove(t_map *m, const void *k, size_t s)
{
	t_map_node	*prev;
	t_map_node	*cur;
	size_t		s_hash;

	if (!m || !k || !s || !m->nb_e_total)
		return (NULL);
	s_hash = m->hash(k, s);
	prev = NULL;
	cur = m->lists[s_hash % m->capacity];
	while (cur)
	{
		if (cur->hash == s_hash && !m->cmp(cur->key, k))
			break ;
		prev = cur;
		cur = cur->next;
	}
	if (!cur)
		return (NULL);
	return (push_to_pool(prev, cur, m, s_hash), cur->data);
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
