/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 18:29:23 by bgoulard          #+#    #+#             */
/*   Updated: 2023/12/11 18:29:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"

void	ft_map_clear(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->capacity)
	{
		map->nodes[i].used = false;
		i++;
	}
	map->size = 0;
}
