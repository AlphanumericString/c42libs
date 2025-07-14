/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:07:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/fixtures.h"
#include "tests/map_tests.h"

#include "types/ft_map_types.h"
#include "ft_map.h"

int	tmap_create(void)
{
	t_map	*map;
	int		prev;
	int		total;

	total = *talloc_get_currentpoint();
	map = ft_map_create(10);
	total = *talloc_get_currentpoint() - total;
	if (!map)
		return (1);
	ft_map_destroy(map);
	prev = *talloc_get_failpoint();
	while (total >= 0)
	{
		talloc_set_failpoint(*talloc_get_currentpoint() + --total);
		map = ft_map_create(10);
		if (map)
			return (talloc_set_failpoint(prev), 2 + total + 1);
	}
	talloc_set_failpoint(prev);
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
