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
#include "tests/tests__all_modules_tests.h"
#include <malloc.h>

static void	reset_allocator(const t_allocator_group prev)
{
	t_allocator_group	*group_test;

	group_test = ft_get_allocator();
	group_test->ptr_free = prev.ptr_free;
	group_test->ptr_alloc = prev.ptr_alloc;
	group_test->ptr_calloc = prev.ptr_calloc;
	group_test->ptr_realloc = prev.ptr_realloc;
	group_test->ptr_reallocarray = prev.ptr_reallocarray;
}

int	tmal_allocator(void)
{
	const t_allocator_group	prev = *ft_get_allocator();
	t_allocator_group		*group_test;

	ft_set_gnu_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_free != &free
		|| group_test->ptr_alloc != &malloc
		|| group_test->ptr_calloc != &calloc
		|| group_test->ptr_realloc != &realloc
		|| group_test->ptr_reallocarray != &reallocarray)
		return (1);
	ft_set_ft_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_free != &ft_memimpl_free
		|| group_test->ptr_alloc != &ft_memimpl_malloc
		|| group_test->ptr_calloc != &ft_memimpl_calloc
		|| group_test->ptr_realloc != &ft_memimpl_realloc
		|| group_test->ptr_reallocarray != &ft_memimpl_reallocarray)
		return (2);
	reset_allocator(prev);
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
