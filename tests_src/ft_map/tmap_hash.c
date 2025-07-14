/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmap_hash.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 18:21:33 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/map_tests.h"
#include "ft_defs.h"
#include "ft_map.h"
#include "ft_string.h"

// we dont really test the hash function, we just test that
// it doesn't overflow our map

int	tmap_hash(void)
{
	size_t	ret;
	size_t	ret2;

	ret = ft_hash_djb2("key", ft_strlen("key"));
	ret2 = ft_hash_djb2("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	ret = ft_hash_sdbm("key", ft_strlen("key"));
	ret2 = ft_hash_sdbm("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	ret = ft_hash_fnv1a("key", ft_strlen("key"));
	ret2 = ft_hash_fnv1a("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
	ret = ft_hash_dummy("key", ft_strlen("key"));
	ret2 = ft_hash_dummy("key2", ft_strlen("key2"));
	if (ret == ret2)
		return (1);
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
