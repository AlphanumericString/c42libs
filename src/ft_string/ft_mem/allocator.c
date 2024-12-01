/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 16:32:41 by bgoulard          #+#    #+#             */
/*   Updated: 2024/12/01 16:46:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct s_allocator
{
	void	*(*alloc)(size_t size);
	void	*(*realloc)(void *ptr, size_t size);
	void	*(*calloc)(size_t count, size_t size);
	void	(*free)(void *ptr);
}	t_allocator;

t_allocator *singleton_allocator(void)
{
	static t_allocator allocator = {
		.alloc = malloc,
		.realloc = realloc,
		.calloc = calloc,
		.free = free
	};

	return (&allocator);
}

// -- functions
// -- -- ft implementation of alloc realloc calloc free
void *ft_mem_malloc(size_t size)
{
	return (malloc(size));
}

void *ft_mem_realloc(void *ptr, size_t size)
{
	void *ret = malloc(size);

	if (ret == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		ft_memcpy(ret, ptr, size);
		free(ptr);
	}
	return (ret);
}

void *ft_mem_calloc(size_t count, size_t size)
{
	void *ret = NULL;

	if (count == (SIZE_MAX / size) ||
	size == (SIZE_MAX / count))
		return (errno = ENOMEM, NULL);
	ret = malloc(count * size);
	if (ret == NULL)
		return (NULL);
	ft_bzero(ret, count * size);
	return (ret);
}

void ft_mem_free(void *ptr)
{
	free(ptr);
}


// -- calls

void *ft_malloc(size_t size)
{
	t_allocator *gb_alloc = singleton_allocator();

	return (gb_alloc->alloc(size));
}

void *ft_realloc(void *ptr, size_t size)
{
	t_allocator *gb_alloc = singleton_allocator();

	return (gb_alloc->realloc(ptr, size));
}

void *ft_calloc(size_t count, size_t size)
{
	t_allocator *gb_alloc = singleton_allocator();

	return (gb_alloc->calloc(count, size));
}

void ft_free(void *ptr)
{
	t_allocator *gb_alloc = singleton_allocator();

	gb_alloc->free(ptr);
}

// -- setters
// -- -- setter generic

void	ft_set_allocator(t_allocator *other)
{
	t_allocator *gb_alloc = singleton_allocator();

	gb_alloc->alloc = other->alloc;
	gb_alloc->realloc = other->realloc;
	gb_alloc->calloc = other->calloc;
	gb_alloc->free = other->free;
}

// -- -- setter ft
void ft_set_allocator_ft(void)
{
	t_allocator ft_allocator = {
		.alloc		=	ft_mem_malloc,
		.realloc	=	ft_mem_realloc,
		.calloc		=	ft_mem_calloc,
		.free		=	ft_mem_free
	};

	ft_set_allocator(&ft_allocator);
}

// -- -- setter std
void ft_set_allocator_std(void)
{
	t_allocator std_allocator = {
		.alloc = malloc,
		.realloc = realloc,
		.calloc = calloc,
		.free = free
	};

	ft_set_allocator(&std_allocator);
}
