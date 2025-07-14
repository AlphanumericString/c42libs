/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talloc_group.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:47:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 13:53:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/fixtures.h"

void	*talloc_prev_group(void)
{
	static t_allocator_group	prev;

	return (&prev);
}

void	talloc_wrapper_setup(void)
{
	t_allocator_group	*alloc;
	t_allocator_group	*prev;

	alloc = ft_get_allocator();
	prev = talloc_prev_group();
	prev->ptr_alloc = alloc->ptr_alloc;
	prev->ptr_calloc = alloc->ptr_calloc;
	prev->ptr_realloc = alloc->ptr_realloc;
	prev->ptr_free = alloc->ptr_free;
	prev->ptr_reallocarray = alloc->ptr_reallocarray;
	alloc->ptr_alloc = talloc_alloc;
	alloc->ptr_calloc = talloc_calloc;
	alloc->ptr_realloc = talloc_realloc;
	alloc->ptr_free = talloc_free;
	alloc->ptr_reallocarray = talloc_reallocarray;
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
