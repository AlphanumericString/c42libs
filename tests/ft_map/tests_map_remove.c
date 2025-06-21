/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_map_remove.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:18:53 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:29:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests__all_modules_tests.h"
#include "ft_map.h"
#include "ft_string.h"
#include "types/ft_map_types.h"
#include "ft_string.h"
#include <stdlib.h>

static int	tm_remove_normal(void)
{
	char	*str;
	void	*ret;
	t_map	*map;

	str = ft_strdup("value");
	map = ft_map_create(10);
	ft_map_set(map, "key", str, ft_strlen("key"));
	ret = ft_map_remove(map, "key", ft_strlen("key"));
	if (!ret)
		return (1);
	else if (ret != str)
		return (2);
	ret = ft_map_remove(map, "key2", ft_strlen("key2"));
	if (ret)
		return (3);
	ft_map_destroy(map);
	ft_free(str);
	return (0);
}

static int	tm_remove_colision(void)
{
	const char	*keys[] = {"key", "key2", "key3", "key4", NULL};
	const char	*str[] = {
		ft_strdup("value"), ft_strdup("value2"), ft_strdup("value3"),
		ft_strdup("value4"), NULL};
	t_map		*map;
	int			ret;

	map = ft_map_create(1);
	ret = 0;
	while (str[ret])
	{
		ft_map_set(map, keys[ret], str[ret], ft_strlen(keys[ret]));
		ret++;
	}
	ret = 0;
	if (ft_map_remove(map, keys[2], ft_strlen(keys[2])) != str[2])
		return (1);
	if (ft_map_remove(map, keys[1], ft_strlen(keys[1])) != str[1])
		return (2);
	if (ft_map_remove(map, keys[0], ft_strlen(keys[0])) != str[0])
		return (3);
	if (ft_map_remove(map, keys[3], ft_strlen(keys[3])) != str[3])
		return (4);
	return (ft_map_destroy(map), ft_aapply((void **)str, ft_free), 0);
}

int	tm_remove(void)
{
	int	ret;

	ret = tm_remove_normal();
	if (ret != 0)
		return (ret);
	ret = tm_remove_colision();
	if (ret != 0)
		return (ret + 10);
	return (0);
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
