/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:37:46 by bgoulard          #+#    #+#             */
/*   Updated: 2026/01/15 14:21:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_H
# define FT_VECTOR_H

/* ************************************************************************** */
/* 																		      */
/* Module: FT_VECTOR														  */
/* Prefix: ft_vec_															  */
/*																			  */
/* This module provides the vector type, a way to create array that are chunk */
/*		allocated and allows for easy manipulations.						  */
/* 																		      */
/* ************************************************************************** */

# include <stdbool.h>
# include <stddef.h>

# include "ft_defs.h"
# include "types/ft_vector_types.h"

// alloc
			// use ft_vec_create instead
t_vector	*ft_vec_new(void) __attribute__((
					__deprecated__("please use create instead",
						"ft_vec_create")));
t_vector	*ft_vec_create(size_t size_of_elements);
t_vector	*ft_vec_from_size(size_t n);
t_vector	*ft_vec_from_array(const void *src, size_t nmemb, size_t elem_size);
			// new vector w rets from the function func
t_vector	*ft_vec_map(const t_vector *vec, t_data_apply func);
t_vector	*ft_vec_dup(const t_vector *vec);
t_vector	*ft_vec_convert_alloccarray(void *data, size_t nmemb, size_t size);
bool		ft_vec_reserve(t_vector *vec, size_t size);

// destroy
bool		ft_vec_destroy(t_vector **vec);
bool		ft_vec_delete(t_vector *vec);
void		*ft_vec_pop(t_vector *vec);
// TODO: push -> links backs to ft_vec_add
// TODO: ft_vec_pop_front
void		ft_vec_remove(t_vector *vector, size_t n,
				t_data_apply del);
void		ft_vec_nremove(t_vector *vec, size_t start, size_t n,
				t_data_apply del);
void		ft_vec_filterout(t_vector *vector, t_data_is func,
				t_data_apply del);

// add
bool		ft_vec_add(t_vector *vec, const void *data);
bool		ft_vec_cat(t_vector *vec_dst, const t_vector *vec_src);
bool		ft_vec_insert(t_vector *vec, size_t pos, const void *elem);

// alter
void		ft_vec_apply(t_vector *vec, t_data_apply func);
void		ft_vec_clear(t_vector *vec);
void		ft_vec_filter(t_vector *vec, t_data_is func,
				t_data_apply del);
void		ft_vec_sort(t_vector *vec, t_data_cmp cmp_f);
void		ft_vec_reverse(t_vector *vector);
void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);
bool		ft_vec_shrink(t_vector *vec);
void		ft_vec_swap(t_vector *vec, size_t a, size_t b);

// get
void		*ft_vec_at(const t_vector *vec, size_t n);
size_t		ft_vec_inuse(const t_vector *vec);
void		*ft_vec_find(const t_vector *vector,
				const void *key, t_data_cmp cmp);
void		*ft_vec_to_array(t_vector **vec);

#endif /* FT_VECTOR_H */
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
