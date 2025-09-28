/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:29:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/28 22:09:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_vector.h"

void	ft_map_clear(t_map *restrict map)
{
	size_t	i;
	t_list	*cur;

	i = 0;
	while (i < map->capacity)
	{
		while (map->nodes[i])
		{
			cur = map->nodes[i];
			map->nodes[i] = map->nodes[i]->next;
			ft_vec_add(&map->reserved_nodes, cur);
		}
		map->nb_e[i] = 0;
		i++;
	}
	map->nb_e_total = 0;
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
