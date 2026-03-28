/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmal_allocator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 17:03:54 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_mem.h"
#include "types/ft_allocator_types.h"
#include "tests/str__mem_tests.h"
#include <malloc.h>

int	tmal_allocator(void)
{
	t_allocator_group		curent;
	const t_allocator_group	prev = ft_get_allocator(NULL);
	const t_allocator_group	gnu_expect = (t_allocator_group){
		.alloc_fn = malloc, .free_fn = free, .calloc_fn = calloc,
		.realloc_fn = realloc, .reallocarray_fn = reallocarray
	};
	const t_allocator_group	ft_expect = (t_allocator_group){
		.alloc_fn = ft_memimpl_malloc, .free_fn = ft_memimpl_free,
		.calloc_fn = ft_memimpl_calloc, .realloc_fn = ft_memimpl_realloc,
		.reallocarray_fn = ft_memimpl_reallocarray
	};

	curent = (ft_set_gnu_alloc(), ft_get_allocator(NULL));
	if (ft_memcmp(&curent, &gnu_expect, sizeof(t_allocator_group)) != 0)
		return (ft_get_allocator(&prev), 1);
	curent = (ft_set_ft_alloc(), ft_get_allocator(NULL));
	if (ft_memcmp(&curent, &ft_expect, sizeof(t_allocator_group)) != 0)
		return (ft_get_allocator(&prev), 2);
	curent = (ft_get_allocator(&prev));
	if (ft_memcmp(&curent, &prev, sizeof(t_allocator_group)) != 0)
		return (3);
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
