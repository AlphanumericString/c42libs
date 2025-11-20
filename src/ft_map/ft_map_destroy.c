/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 15:37:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_mem.h"

void	ft_map_destroy(t_map *map)
{
	ft_map_destroy_free(map, NULL);
}

static t_map_node	*pop_f(t_map_node *mn, t_data_apply f)
{
	t_map_node	*nxt;

	if (f)
		f(mn->data);
	nxt = mn->next;
	ft_free(mn);
	return (nxt);
}

void	ft_map_destroy_free(t_map *m, t_data_apply f)
{
	size_t		i;
	t_map_node	*cur;

	i = 0;
	if (!f || !m)
		return ;
	while (i < m->capacity)
	{
		cur = m->lists[i++];
		while (cur)
			cur = pop_f(cur, f);
	}
	cur = m->nodes_pool;
	while (cur)
		cur = pop_f(cur, NULL);
	ft_free(m->nb_e);
	ft_free(m);
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
