/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tma_arena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:42:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"
#include <stddef.h>

int	tma_arena(void)
{
	const char	*str_src = "toto valid memory to write to test";
	char		*ptr;
	size_t		i;

	ptr = ft_arena_alloc(42);
	if (!ptr)
		return (1);
	ft_strlcpy(ptr, str_src, 42);
	if (ft_strncmp(ptr, str_src, 41) != 0)
		return (2);
	if (ft_narena_belongs(FT_DEFAULT_ARENA, ptr) != true)
		return (3);
	ft_arena_free();
	ptr = ft_arena_calloc(42, sizeof(char));
	if (!ptr)
		return (4);
	i = 0;
	while (i < 42)
		if (ptr[i++] != 0)
			return (5);
	return (ft_arena_free(), 0);
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
