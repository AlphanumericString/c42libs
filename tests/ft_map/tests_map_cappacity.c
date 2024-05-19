/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_cappacity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:16:49 by bgoulard          #+#    #+#             */
/*   Updated: 2024/05/19 18:17:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_map.h"
#include "ft_map_types.h"
#include <stdlib.h>
#include <string.h>

int	test_map_capacity(void)
{
	char	*str;
	t_map	*map;
	size_t	ret;

	str = strdup("value");
	map = ft_map_create(10);
	ret = ft_map_capacity(map);
	if (ret != 10)
		return (1);
	ft_map_destroy(map);
	free(str);
	return (0);
}
