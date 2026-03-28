/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar_scope.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:52:29 by antigravity       #+#    #+#             */
/*   Updated: 2026/03/28 15:52:29 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arena.h"
#include "ft_list.h"
#include "internal/ft_ar_scope__dev.h"

t_ar_state	*ft_get_ar_state(void)
{
	static t_ar_state	state = {0};

	return (&state);
}

static t_ar_scope	*create_scope(t_allocator_group *underlying)
{
	t_ar_scope	*scope;

	scope = underlying->alloc_fn(sizeof(t_ar_scope));
	if (!scope)
		return (NULL);
	scope->count = 0;
	scope->capacity = FT_AR_SCOPE_INIT_CAP;
	scope->allocations = underlying->alloc_fn(sizeof(void *) * scope->capacity);
	if (!scope->allocations)
		return (underlying->free_fn(scope), NULL);
	return (scope);
}

void	ft_ar_scope_start(void)
{
	t_ar_state			*state;
	t_allocator_group	ag;
	t_ar_scope			*scope;
	t_dlist				*node;

	state = ft_get_ar_state();
	ag = ft_get_allocator(NULL);
	if (ag.alloc_fn != ft_ar_alloc)
	{
		state->underlying = ag;
		ag = (t_allocator_group){.alloc_fn = ft_ar_alloc, .realloc_fn = 0,
			.reallocarray_fn = 0, .calloc_fn = ft_ar_calloc,
			.free_fn = ft_ar_free};
		ft_get_allocator(&ag);
	}
	scope = create_scope(&state->underlying);
	if (!scope)
		return ;
	node = state->underlying.alloc_fn(sizeof(t_dlist));
	if (!node)
		return (state->underlying.free_fn(scope->allocations),
			state->underlying.free_fn(scope));
	*node = (t_dlist){.data = scope, .next = NULL, .prev = NULL};
	ft_dl_add_front(&state->scopes, node);
}

void	ft_ar_scope_end(void)
{
	t_ar_state	*state;
	t_dlist		*node;
	t_ar_scope	*scope;
	size_t		i;

	state = ft_get_ar_state();
	if (!state->scopes)
		return ;
	node = state->scopes;
	state->scopes = node->next;
	if (state->scopes)
		state->scopes->prev = NULL;
	scope = (t_ar_scope *)node->data;
	i = 0;
	while (i < scope->count)
		state->underlying.free_fn(scope->allocations[i++]);
	state->underlying.free_fn(scope->allocations);
	state->underlying.free_fn(scope);
	state->underlying.free_fn(node);
	if (!state->scopes)
		ft_get_allocator(&state->underlying);
}

void	ft_ar_extract_ptr(void *ptr)
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
