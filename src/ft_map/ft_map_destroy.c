/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/31 19:21:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_list.h"
#include "ft_map.h"
#include "ft_vector.h"
#include <stdlib.h>

t_data_apply singleton_custom_destroy(t_data_apply custom_destroy)
{
	static t_data_apply f_ptr = NULL;

	if (custom_destroy)
		f_ptr = custom_destroy;
	return (f_ptr);
}

static void wrapper_destroy(void *data)
{
	t_data_apply	destroy = singleton_custom_destroy(NULL);
	t_list			*node = (t_list *)data;
	t_map_node		*map_node = (t_map_node *)node->data;

	if (destroy)
		(*destroy)(map_node->data);
	free(map_node);
	free(node);
}

void	ft_map_destroy(t_map *map)
{
	ft_map_destroy_free(map, NULL);
}

void	ft_map_destroy_free(t_map *map, t_data_apply free_fun)
{
	size_t	i;

	singleton_custom_destroy(free_fun);
	i = 0;
	while (i < map->size)
		ft_listapply(map->nodes[i++], wrapper_destroy);
	ft_map_destroy(map);
	free(map->nodes);
	ft_vec_destroy(&map->reserved_nodes);
	free(map);
}
