/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocator_types.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 13:02:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/02/10 13:07:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALLOCATOR_TYPES_H
# define FT_ALLOCATOR_TYPES_H

# include <stdbool.h>
# include <stddef.h>

typedef struct s_allocator_group
{
	void			*(*alloc_fn)(size_t);
	void			(*free_fn)(void *);
	void			*(*calloc_fn)(size_t, size_t);
	void			*(*realloc_fn)(void *, size_t);
	void			*(*reallocarray_fn)(void *, size_t, size_t);
}					t_allocator_group;

typedef struct s_memory_block
{
	size_t					size;
	bool					is_free;
	struct s_memory_block	*next;
	struct s_memory_block	*prev;
	char					*data;
}	t_memory_block;

#endif /* FT_ALLOCATOR_TYPES_H */

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
