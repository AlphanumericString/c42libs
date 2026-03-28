/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_scope_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:52:29 by antigravity       #+#    #+#             */
/*   Updated: 2026/03/28 15:52:29 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/ft_ar_scope__dev.h"

static void	*manual_realloc(t_ar_scope *scope, t_allocator_group *u)
{
	void	**new_allocs;
	size_t	i;

	new_allocs = u->alloc_fn(scope->capacity * 2 * sizeof(void *));
	if (new_allocs)
	{
		i = -1;
		while (++i < scope->count)
			new_allocs[i] = scope->allocations[i];
		u->free_fn(scope->allocations);
	}
	return (new_allocs);
}

static bool	push_to_scope(t_ar_scope *scope, void *ptr, t_allocator_group *u)
{
	void	**new_allocs;

	if (scope->count >= scope->capacity)
	{
		new_allocs = manual_realloc(scope, u);
		if (!new_allocs)
			return (false);
		scope->allocations = new_allocs;
		scope->capacity *= 2;
	}
	scope->allocations[scope->count++] = ptr;
	return (true);
}

void	*ft_ar_alloc(size_t size)
{
	t_ar_state	*state;
	void		*ptr;
	t_ar_scope	*scope;

	state = ft_get_ar_state();
	ptr = state->underlying.alloc_fn(size);
	if (!ptr)
		return (NULL);
	if (state->scopes)
	{
		scope = (t_ar_scope *)state->scopes->data;
		if (!push_to_scope(scope, ptr, &state->underlying))
			return (state->underlying.free_fn(ptr), NULL);
	}
	return (ptr);
}

void	*ft_ar_calloc(size_t count, size_t size)
{
	t_ar_state	*state;
	void		*ptr;
	t_ar_scope	*scope;

	state = ft_get_ar_state();
	ptr = state->underlying.calloc_fn(count, size);
	if (!ptr)
		return (NULL);
	if (state->scopes)
	{
		scope = (t_ar_scope *)state->scopes->data;
		if (!push_to_scope(scope, ptr, &state->underlying))
			return (state->underlying.free_fn(ptr), NULL);
	}
	return (ptr);
}

void	ft_ar_free(void *ptr)
{
	t_ar_state	*state;
	t_ar_scope	*scope;
	size_t		i;

	if (!ptr)
		return ;
	state = ft_get_ar_state();
	if (state->scopes)
	{
		scope = (t_ar_scope *)state->scopes->data;
		i = 0;
		while (i < scope->count)
		{
			if (scope->allocations[i] == ptr)
			{
				scope->allocations[i] = scope->allocations[scope->count - 1];
				scope->count--;
				break ;
			}
			i++;
		}
	}
	state->underlying.free_fn(ptr);
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
