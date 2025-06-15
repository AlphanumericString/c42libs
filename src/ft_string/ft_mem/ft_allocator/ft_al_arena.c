/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:10:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:48:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* SHELVED IDEA : kept for memories sake                                      */
/* ************************************************************************** */

/*
#include "types/ft_list_types.h"
#include "ft_math.h"
#include "ft_string.h"
#include "ft_arena.h"

#include <assert.h>
#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>

#define DEFAULT_ARENA		0
#define FT_NARENAS_MAX		8
#define FT_AREA_BLOCK_SIZE	4096
*/

/******************************************************************************/
/*                                                                            */
/* malloc suite - narena version:                                             */
/*                                                                            */
/* The idea is the following, at 42 any possible leak is considered a faillure*/
/*  therefore the idea of a 'smart' allocator tha could automatically free    */
/*  stuff at the end of a program emerged.                                    */
/* However how can i make my allocator 'speak' with the malloc suite?         */
/*  The solution we found was to re-implement it. This is why we use          */
/*  ft_memimpl_<function> to call our implementation of malloc.               */
/* Once we did this however came another problem, what if, i had done a job A */
/*  using ressources A' and didn't need A' anymore? 'just free the ressources'*/
/*  you might say. And yes we could do that but, we just made something to    */
/*  avoid this problem entierly in the 'global' case of memory allocation...  */
/* This is where the n_arena commes in to play, we basically allocate memory  */
/*  chunks that we then divide ourselves to avoid free'ing manually each ptr  */
/*  alloc. We just have to call free on the arena specified.                  */
/*                                                                            */
/* This system should also work where you could just use ft_narena_new and    */
/*  use the returned pointer as the arena. the Narena system provides an      */
/*  access to a singleton table that has already allocated Narenas.           */
/*                                                                            */
/* DO NOT use the Narena system if you are not sure whether the narena is used*/
/*  bellow you or, above you in the stack. A single call ft_arena_free would  */
/*  render pointers above or bellow un-usable.                                */
/*                                                                            */
/******************************************************************************/

/*
typedef union u_mem_fragment {
	uint64_t	infos;
	struct s_mem_fragment {
		uint64_t		used:1;
		uint64_t		size:63;
	} info_fragmented;
} t_mem_fragment ;

typedef struct s_arena {
	struct s_arena	*next_block;
	struct s_arena	*prev_block;
} t_arena;


// ar should never be null
t_arena	*ft_arena_get(int n)
{
	static t_arena	arena_array[FT_NARENAS_MAX] = {0};

	n = ft_clamp(n, 0, FT_NARENAS_MAX - 1);
	if (n < 0 || n >= FT_NARENAS_MAX || 0 == FT_NARENAS_MAX ||
	0 == FT_AREA_BLOCK_SIZE)
		return (NULL);
	return (&arena_array[n]);
}
// --- //

// proto - arena alloc suite
void	*ft_arena_alloc(t_arena *ar, size_t size);
void	*ft_arena_realloc(t_arena *ar, void *ptr, size_t size);
void	*ft_arena_calloc(t_arena *ar, size_t count, size_t size);
void	ft_arena_free(t_arena *ar, void *ptr);

// proto - narena alloc suite
void	*ft_narena_alloc(size_t size, int ar_nb);
void	*ft_narena_realloc(void *ptr, size_t size, int ar_nb);
void	*ft_narena_calloc(size_t count, size_t size, int ar_nb);
void	ft_narena_free(void *ptr, int ar_nb);

// proto - arena new - delete
t_arena	*ft_arena_new_size(size_t size);
t_arena	*ft_arena_new(void);
void	ft_arena_delete(t_arena *ar);

// funcs
// narena alloc suite

void ft_narena_free(void *ptr, int ar_nb)
{
	t_arena	*ar;

	ar = ft_arena_get(ar_nb);
	if (!ar || !ptr)
		return ;
	return (ft_arena_free(ar, ptr));
}

void *ft_narena_alloc(size_t size, int ar_nb)
{
	t_arena	*ar;
	void	*ret;

	ar = ft_arena_get(ar_nb);
	if (!ar || !size)
		return (NULL);
	return (ft_arena_alloc(ar, size));
}

void *ft_narena_realloc(void *ptr, size_t size, int ar_nb)
{
	t_arena	*ar;

	if (!ptr)
		return (ft_narena_alloc(size, ar_nb));
	ar = ft_arena_get(ar_nb);
	if (!ar || !size)
		return (NULL);
	return (ft_arena_realloc(ar, ptr, size));

}

void *ft_narena_calloc(size_t count, size_t size, int ar_nb)
{
	t_arena	*ar;


	if (!count || !size)
		return (NULL);
	ar = ft_arena_get(ar_nb);
	if (!ar)
		return (NULL);
	return (ft_arena_calloc(ar, count, size));
}

// func arena new - delete

t_arena	*ft_arena_new_size(size_t size)
{
	t_arena	*ret;

	ret = ft_malloc(sizeof(t_arena) + ft_align_2(size, FT_AREA_BLOCK_SIZE));
	return (ret);
}

t_arena	*ft_arena_new(void)
{
	t_arena	*ret;

	ret = ft_malloc(sizeof(t_arena) + FT_AREA_BLOCK_SIZE);
	return (ret);
}

void	ft_arena_delete(t_arena *ar)
{
	t_arena	*nxt;

	if (!ar)
		return ;
	nxt = ar->next_block;
	while (nxt)
	{
		ft_free(ar);
		ar = nxt;
		nxt = ar->next_block;
	}
	ft_free(ar);
}
*/

// func arena alloc suite

/*
void	*ft_arena_alloc(t_arena *ar, size_t size)
{
}

void	*ft_arena_realloc(t_arena *ar, void *ptr, size_t size)
{
}

void	*ft_arena_calloc(t_arena *ar, size_t count, size_t size)
{
}

void	ft_arena_free(t_arena *ar, void *ptr)
{
}
*/
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_narena.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 17:41:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 13:41:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include "ft_list.h"
#include "types/ft_list_types.h"
#include "ft_math.h"
#include <stddef.h>
#include <stdlib.h>

#define FT_NARENAS_MAX 8
#define FT_AREA_BLOCK_SIZE 4096

typedef struct s_arena
{
	void			*block_origin;
	void			*block_current;
	void			*block_end;
}	t_arena;

t_list	*ft_arena_get(int n)
{
	static t_list	arena_array[FT_NARENAS_MAX] = {0};

	if (n < 0 || n >= FT_NARENAS_MAX)
		return (NULL);
	return (&arena_array[n]);
}

bool ft_arena_create_handler(t_list *ar_ptr, size_t size)
{
	t_arena	*arena;

	size = ft_align_2(size + sizeof(t_arena), FT_AREA_BLOCK_SIZE);
	arena = malloc(size);
	if (!arena)
		return (false);
	arena->block_origin = arena + 1;
	arena->block_current = arena->block_origin;
	arena->block_end = (void *)arena + size;
	ar_ptr->data = arena;
	return (true);
}

void *ft_arena_alloc(size_t size, int ar_nb)
{
	t_list	*ar_list;
	t_arena	*arena;
	void	*ret;

	size = ft_align_2(size, FT_AREA_BLOCK_SIZE);
	ar_list = ft_arena_get(ar_nb);
	if (!ar_list)
		return (NULL);
	arena = ft_ll_end(ar_list)->data;
	if (!arena && ft_arena_create_handler(ar_list, size) == false)
		return (NULL);
		// create new block handler - if fail ret null
	if (arena->block_origin == NULL ||
arena->block_current + size > arena->block_end)
	{
		// allocate a new block
		;
	}
	ret = arena->block_current;
	arena->block_current += size;
	return (ret);
}
*/
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
