/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:46:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_defs.h"

void	*ft_arena_alloc(size_t size)
{
	return (ft_narena_alloc(FT_DEFAULT_ARENA, size));
}

void	*ft_arena_calloc(size_t count, size_t size)
{
	return (ft_narena_calloc(FT_DEFAULT_ARENA, count, size));
}

void	ft_arena_free(void)
{
	ft_narena_free(FT_DEFAULT_ARENA);
}

// go see ft_narena_remove comments
// void	ft_arena_remove(const void *ptr)
// {
// 	ft_narena_remove(FT_DEFAULT_ARENA, ptr);
// }
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
