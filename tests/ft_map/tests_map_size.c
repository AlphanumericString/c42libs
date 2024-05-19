/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:15:34 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:16:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include <stdlib.h>
#include <string.h>

int	test_map_size(void)
{
	char	*str;
	t_map	*map;
	size_t	ret;

	str = strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, strlen(str) + 1);
	ret = ft_map_size(map);
	if (ret != 1)
		return (1);
	ft_map_destroy(map);
	free(str);
	return (0);
}
