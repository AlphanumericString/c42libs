/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocator__dev.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 14:16:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 00:15:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOCATOR__DEV_H
# define FT_ALLOCATOR__DEV_H

# include <stdbool.h>
# include <stdlib.h>

// if for whatever reason it is def, put true in it
# ifdef ALLOC_SELF
#  define SELF_ALLOC true
# else
#  define SELF_ALLOC false
# endif

# include "types/ft_allocator_types.h"

// basic idea is that ft_set_alloc gets called first in the programs and set
//  the allocator_group to the correct variable then any call to ft_malloc is
//  resolved through the allocaor group -> therefore i can switch to the 'real'
//  malloc at any time by calling ft_set_gnu_alloc

t_allocator_group	*ft_get_allocator(void);
void				ft_set_allocator(void) __attribute__((constructor(200)));
void				ft_set_ft_alloc(void);
void				ft_set_gnu_alloc(void);

// hooks
// aka call the allocator_group ptrs
void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_reallocarray(void *ptr, size_t nmemb, size_t size);

// mem implementation
// aka 'My' allocators
void				*ft_memimpl_malloc(size_t size);
void				ft_memimpl_free(void *ptr);
void				*ft_memimpl_calloc(size_t nmemb, size_t size);
void				*ft_memimpl_realloc(void *ptr, size_t size);
void				*ft_memimpl_reallocarray(void *ptr, size_t nmemb,
						size_t size);

/// dev (not sorted)
t_memory_block		**ft_get_memory_block(void);
bool				is_block_valid(void *ptr);
void				merge_blocks(t_memory_block *block1,
						t_memory_block *block2);

// usefull ::
t_memory_block		*search_block(size_t size);
t_memory_block		*create_block(size_t size);
t_memory_block		*split_block(t_memory_block *block, size_t size);
void				*realoc_create_block(size_t size);
bool				addable_blocks(t_memory_block *block, size_t size,
						t_memory_block *bound[2]);
void				*add_blocks(t_memory_block *block, size_t size,
						t_memory_block *bounds[2]);
void				move_block_data(t_memory_block *dst, t_memory_block *src);
void				free_block(t_memory_block *block);

void				ft_real_memimpl_free(void *ptr);;
void				*ft_real_memimpl_realloc(void *ptr, size_t size);

#endif /* FT_ALLOCATOR__DEV_H */
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
