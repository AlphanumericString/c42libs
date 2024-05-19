/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_get.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:14:47 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:15:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	// search for a non existing key
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	---
	// search for a non existing key in a full map
	map = ft_map_create(1);
*/

#include "ft_map.h"
#include "ft_map_types.h"
#include <stdlib.h>
#include <string.h>

int	test_map_get(void)
{
	char		*str;
	t_map		*map;
	t_map_node	*ret;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen("key") + 1);
	ret = ft_map_get(map, "key", strlen("key") + 1);
	if (ret == NULL)
		return (1);
	else if (strcmp((char *)ret->data, "value"))
		return (1);
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	if (ret != NULL)
		return (1);
	ft_map_destroy(map);
	map = ft_map_create(1);
	ft_map_set(map, "key", str, strlen("key") + 1);
	ret = ft_map_get(map, "key2", strlen("key2") + 1);
	if (ret != NULL)
		return (1);
	ft_map_destroy(map);
	free(str);
	return (0);
}
