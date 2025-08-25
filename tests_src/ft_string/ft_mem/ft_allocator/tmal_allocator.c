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
#include "types/ft_allocator_types.h"
#include "tests/str__mem_tests.h"
#include <malloc.h>

int	tmal_allocator(void)
{
	const t_allocator_group	prev = ft_get_allocator(NULL);
	t_allocator_group		curent;

	curent = (ft_set_gnu_alloc(), ft_get_allocator(NULL));
	if (curent.ptr_free != &free || curent.ptr_alloc != &malloc
		|| curent.ptr_calloc != &calloc || curent.ptr_realloc != &realloc
		|| curent.ptr_reallocarray != &reallocarray)
		return (1);
	curent = (ft_set_ft_alloc(), ft_get_allocator(NULL));
	if (curent.ptr_free != &ft_memimpl_free
		|| curent.ptr_alloc != &ft_memimpl_malloc
		|| curent.ptr_calloc != &ft_memimpl_calloc
		|| curent.ptr_realloc != &ft_memimpl_realloc
		|| curent.ptr_reallocarray != &ft_memimpl_reallocarray)
		return (2);
	curent = (ft_get_allocator(&prev));
	if (curent.ptr_free != prev.ptr_free || curent.ptr_alloc != prev.ptr_alloc
		|| curent.ptr_calloc != prev.ptr_calloc
		|| curent.ptr_realloc != prev.ptr_realloc
		|| curent.ptr_reallocarray != prev.ptr_reallocarray)
		return (3);
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
