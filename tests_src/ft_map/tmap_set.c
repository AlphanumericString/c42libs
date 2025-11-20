/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:12:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/fixtures.h"
#include "tests/map_tests.h"
#include "ft_mem.h"
#include "ft_map.h"
#include "ft_string.h"

static int	tmap_alloc_fail(void)
{
	const size_t	fp = *talloc_get_failpoint();
	char			*str;
	t_map			*map;
	int				ret;

	str = ft_strdup("value");
	map = ft_map_create(1);
	ret = EXIT_SUCCESS;
	talloc_set_failpoint(0);
	if (ft_map_set(map, "key", str, ft_strlen("key")) != false)
		ret = 1;
	talloc_set_failpoint(fp);
	ft_map_destroy_free(map, ft_free);
	ft_free(str);
	return (ret);
}


static int	tmap_set_normal(void)
{
	char		*str;
	char		*str2;
	t_map		*map;

	str = ft_strdup("value");
	str2 = ft_strdup("value2");
	map = ft_map_create(1);
	if (ft_map_set(map, "key", str, ft_strlen("key")) != true)
		return (1);
	if (ft_map_set(map, "key", str2, ft_strlen("key")) != true)
		return (1);
	ft_map_destroy(map);
	ft_free(str);
	ft_free(str2);
	return (EXIT_SUCCESS);
}

int	tmap_set(void)
{
	int	ret;

	ret = tmap_set_normal();
	if (ret != EXIT_SUCCESS)
		return (ret + 10 * 0);
	ret = tmap_alloc_fail();
	if (ret != EXIT_SUCCESS)
		return (ret + 10 * 1);
	return (EXIT_SUCCESS);
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
