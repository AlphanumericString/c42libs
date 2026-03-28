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
	const t_allocator_group	test_allocator = {
		.alloc_fn = talloc_alloc,
		.calloc_fn = talloc_calloc,
		.realloc_fn = talloc_realloc,
		.free_fn = talloc_free,
		.reallocarray_fn = talloc_reallocarray,
	};

	*(t_allocator_group *)talloc_prev_group() = ft_get_allocator(NULL);
	ft_get_allocator(&test_allocator);
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
