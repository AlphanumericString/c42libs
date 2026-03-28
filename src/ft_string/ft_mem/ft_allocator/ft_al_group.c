/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_al_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 15:55:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:03:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_defs.h"
#include <malloc.h> // reallocarray
#include <pthread.h>
#include <stdbool.h> // true

t_allocator_group	ft_get_allocator(const t_allocator_group *ag)
{
	static pthread_mutex_t		ag_lock = PTHREAD_MUTEX_INITIALIZER;
	static t_allocator_group	alloc = {0};

	if (FT_THREADS)
		pthread_mutex_lock(&ag_lock);
	if (ag != NULL)
		alloc = *ag;
	if (FT_THREADS)
		pthread_mutex_unlock(&ag_lock);
	return (alloc);
}

void	ft_set_allocator(void)
{
	if (FT_ALLOC_SELF == true)
		ft_set_ft_alloc();
	else
		ft_set_gnu_alloc();
}

void	ft_set_ft_alloc(void)
{
	const t_allocator_group	alloc = (t_allocator_group){
		.alloc_fn = ft_memimpl_malloc,
		.calloc_fn = ft_memimpl_calloc,
		.free_fn = ft_memimpl_free,
		.realloc_fn = ft_memimpl_realloc,
		.reallocarray_fn = ft_memimpl_reallocarray,
	};

	ft_get_allocator(&alloc);
}

#if __GNUC__ && __GNUC__ > 2 || (__GNUC__ == 2 && __GNUC_MINOR__ >= 26)
# define REALLOCARRAY reallocarray
#else
# define REALLOCARRAY 0
#endif

void	ft_set_gnu_alloc(void)
{
	const t_allocator_group	alloc = (t_allocator_group){
		.alloc_fn = malloc,
		.calloc_fn = calloc,
		.free_fn = free,
		.realloc_fn = realloc,
		.reallocarray_fn = (void *(*)(void *, size_t, size_t))REALLOCARRAY,
	};

	ft_get_allocator(&alloc);
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
