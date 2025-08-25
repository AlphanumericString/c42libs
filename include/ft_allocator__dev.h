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

// for conditional self alloc defines
# include "ft_defs.h"

# include "types/ft_allocator_types.h"

// basic idea is that ft_set_alloc gets called first in the programs and set
//  the allocator_group to the correct variable then any call to ft_malloc is
//  resolved through the allocaor group -> therefore i can switch to the 'real'
//  malloc at any time by calling ft_set_gnu_alloc

// hook to null to get current value
t_allocator_group	ft_get_allocator(const t_allocator_group *ag);
void				ft_set_allocator(void) __attribute__((constructor(200)));
void				ft_set_ft_alloc(void);
void				ft_set_gnu_alloc(void);

// hooks
// aka call the allocator_group ptrs
// equivalent to doing:
//	ft_get_allocator()->[allocator_function](args);
//	eg:
//	ft_malloc(42) == ft_get_allocator()->ptr_alloc(42);
//	ft_calloc(42) == ft_get_allocator()->ptr_calloc(42);
//	...
void				*ft_malloc(size_t size);
void				ft_free(void *ptr);
void				*ft_calloc(size_t nmemb, size_t size);
void				*ft_realloc(void *ptr, size_t size);
void				*ft_reallocarray(void *ptr, size_t nmemb, size_t size);

// mem implementation
// aka 'My' allocators - not finished
void				*ft_memimpl_malloc(size_t size);
void				ft_memimpl_free(void *ptr);
void				*ft_memimpl_calloc(size_t nmemb, size_t size);
void				*ft_memimpl_realloc(void *ptr, size_t size);
void				*ft_memimpl_reallocarray(void *ptr, size_t nmemb,
						size_t size);

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
