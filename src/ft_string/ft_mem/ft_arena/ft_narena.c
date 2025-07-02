/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 23:46:39 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/21 22:00:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_list.h"
#include "ft_string.h"
#include "types/ft_list_types.h"

static t_dlist	**singleton_arena(int arena)
{
	static t_dlist	*arenas[FT_NARENA_MAX] = {0};

	if (arena < 0 || arena >= FT_NARENA_MAX)
		return (NULL);
	return (&arenas[arena]);
}

// anrena should be for group allocation
//	- eg :
//	you do step x needing y allocations and then extract result z
//	then nuke the whole allocation y needed by step x
//	you shouldn't 'NEED' to free just a single ptr from an arena
//
//	but i wanna change the ownership ! cant i have an 'unregister' function?
//	No. Just use malloc directly to trnasmit the result then.
//
//	still... even after all that... i kinda play around in my head on with this
//	stuff... might be usefull...
// void	ft_narena_remove(int arena, const void *ptr)
// {
// 	t_dlist	**current_arena;
// 	t_dlist	*node;
//
// 	current_arena = singleton_arena(arena);
// 	if (!current_arena)
// 		return ;
// 	node = ft_dl_find(*current_arena, ptr, NULL);
// 	if (!node)
// 		return ;
// 	ft_dl_delete_self(node, ft_free);
// }

// todo: switch order
bool	ft_narena_belongs(const void *ptr, int ar_nb)
{
	t_dlist	**current_arena;

	current_arena = singleton_arena(ar_nb);
	if (!current_arena)
		return (false);
	return (ft_dl_find(*current_arena, ptr, NULL) != NULL);
}

void	*ft_narena_alloc(int arena_nb, size_t request)
{
	t_dlist	**current_arena;
	void	*ptr;

	current_arena = singleton_arena(arena_nb);
	if (!current_arena)
		return (NULL);
	ptr = ft_malloc(request);
	if (!ptr)
		return (NULL);
	ft_dl_push(current_arena, ptr);
	return (ptr);
}

void	*ft_narena_calloc(int arena_nb, size_t count, size_t size)
{
	t_dlist	**current_arena;
	void	*ptr;

	current_arena = singleton_arena(arena_nb);
	if (!current_arena)
		return (NULL);
	ptr = ft_calloc(count, size);
	if (!ptr)
		return (NULL);
	ft_dl_push(current_arena, ptr);
	return (ptr);
}

void	ft_narena_free(int arena)
{
	t_dlist	**current_arena;

	current_arena = singleton_arena(arena);
	if (!current_arena || !*current_arena)
		return ;
	ft_dl_delete(current_arena, ft_free);
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
