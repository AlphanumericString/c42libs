/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talloc_testimpl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:58:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/29 10:17:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_allocator_types.h"
#include "tests/fixtures.h"

void	*talloc_alloc(size_t s)
{
	if (talloc_is_ok())
		return (((t_allocator_group *)talloc_prev_group())->alloc_fn(s));
	return (NULL);
}

void	*talloc_calloc(size_t a, size_t b)
{
	if (talloc_is_ok())
		return (((t_allocator_group *)talloc_prev_group())->calloc_fn(a, b));
	return (NULL);
}

void	*talloc_realloc(void *p, size_t s)
{
	if (talloc_is_ok())
		return (((t_allocator_group *)talloc_prev_group())->realloc_fn(p, s));
	return (NULL);
}

// no check on isok as we dont allocates here
void	talloc_free(void *p)
{
	return (((t_allocator_group *)talloc_prev_group())->free_fn(p));
}

void	*talloc_reallocarray(void *p, size_t a, size_t b)
{
	if (talloc_is_ok())
		return (((t_allocator_group *)
				talloc_prev_group())->reallocarray_fn(p, a, b));
	return (NULL);
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
