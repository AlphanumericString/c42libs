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
#include <wctype.h>

# include "ft_defs.h"
# include "types/ft_vector_types.h"

// TODO:	-- definitely
//				nfilter(t_vector *vec, t_data_is func, t_data_apply del);
//				nfilterout(t_vector *vec, t_data_is func, t_data_apply del);
//				ninsert
//				add_front
//				push_front
//				push_back
//				nget
//
// TODO:	-- maybe
//				lenght
//				cappacity
// TODO:
//			INFO: reduce size by one, set removed element in holder and
//			return holder
//			void		*ft_vec_popget(t_vector *vec, void *holder);
//			void		*ft_vec_npopget(t_vector *vec, size_t n, void *holder);
//			void		*ft_vec_popfront(t_vector *vec, void *holder);

// ALLOC
//			INFO: allocates a new vector using a standard number of elements
//			that are of size size_of_elements.
t_vector	*ft_vec_create(size_t size_of_elements);
//			INFO: create a vector with a guaranteed size in byte for the
//			vector. You are likely trying to use ft_vec_create if you only
//			have the sie of the elements blocks.
//			WARNING: set elem sizes and number of elem yourself
t_vector	*ft_vec_from_size(size_t size_in_byte);
//			INFO: create a vector using a copy the array 'src'.
t_vector	*ft_vec_from_array(const void *src, size_t e_nb, size_t e_size);
//			INFO: create a vector using standard number of elem and leaving
//			e_size empty.
//			WARNING: this is deprecated use ft_vec_create instead
t_vector	*ft_vec_new(void) __attribute__((
					__deprecated__("please use create instead",
						"ft_vec_create")));

//			INFO: does not alloc vec - dereference then set fields and allocate
//			a buffer for at least e_nb elements of size 'e_size'.
t_vector	*ft_vec_init(t_vector *vec, size_t e_nb, size_t size);
//			INFO: copies data from an array into a new allocated internal buffer
//			inside a given vector. also sets elements size, number of elems
//			and all.
t_vector	*ft_vec_ifrom_array(t_vector *vec, const void *data, size_t e_nb,
				size_t e_size);
//			INFO: 'steals' the array and put in a vector w the number of
//			elements size of elements and all.
t_vector	*ft_vec_iconvert_allocarray(t_vector *v, void *data, size_t e_nb,
				size_t e_size);

//			INFO: reserve so that at least 'size' addtional elements can are
//			vect disponible in the cappacity.
bool		ft_vec_reserve(t_vector *vec, size_t size);

//			INFO: allocate a vector with results from function func and all
//			elements of vec_src
t_vector	*ft_vec_map(const t_vector *vec_src, t_data_apply func);
//			INFO: allocate a vector from the result of the first n elements
//			with func.
t_vector	*ft_vec_nmap(const t_vector *vec_src, size_t n, t_data_apply func);

//			INFO: return an allocated copy of a vector
t_vector	*ft_vec_dup(const t_vector *vec);
//			INFO: return an allocated copy of the first n elements of a vector
t_vector	*ft_vec_ndup(const t_vector *o, size_t n);

// CONVERTIONS
//			INFO: 'steals' an array to create a vector
t_vector	*ft_vec_convert_alloccarray(void *data, size_t nmemb, size_t size);
//			INFO: extract the array and free's the vector
void		*ft_vec_to_array(t_vector **vec);

// DESTROY
//			INFO: frees only the inner data
bool		ft_vec_wipe(t_vector *v);
//			INFO: frees internal + frees vec
bool		ft_vec_delete(t_vector *vec); // free's doesnt set null
//			INFO: free's internal and free's *vec then set to null
bool		ft_vec_destroy(t_vector **vec);
//			INFO: reduce size by one and return element.
//			WARNING: the data returned is a position in the inner array.
//			if it need to be consistant use ft_vec_popget()
void		*ft_vec_pop(t_vector *vec);

// ADD
//			INFO: add data to vec
bool		ft_vec_add(t_vector *vec, const void *data);
//			INFO: add n elements from data to vec
bool		ft_vec_nadd(t_vector *vec, size_t n, const void *data);
//			INFO: append elements from vec_dst to vec_src
bool		ft_vec_cat(t_vector *vec_dst, const t_vector *vec_src);
//			INFO: append n elements from vec_dst to vec_src
bool		ft_vec_ncat(t_vector *vec_dst, const t_vector *vec_src, size_t n);
//			INFO: append elem to vec at position pos
bool		ft_vec_insert(t_vector *vec, size_t pos, const void *elem);
//			INFO: append n elems to vec from elem at position pos
bool		ft_vec_ninsert(t_vector *vec, size_t pos, size_t n, const void *elem);

// MODIFY
//			INFO: apply function func to all elements of vector vec
void		ft_vec_apply(t_vector *vec, t_data_apply func);
//			INFO: apply function func to n elements of vector vec
void		ft_vec_napply(t_vector *vec, size_t n, t_data_apply func);

//			INFO: change value at pos to value store at data
bool		ft_vec_set(t_vector *v, ssize_t pos, const void *data);
//			INFO: change n values at position pos to values stored at datas
bool		ft_vec_nset(t_vector *v, ssize_t pos, size_t n, const void *datas);

//			INFO: sort vec using cmp_f
void		ft_vec_sort(t_vector *vec, t_data_cmp cmp_f);
//			INFO: sort a maximum of n elements of vec using cmp_f
void		ft_vec_nsort(t_vector *vec, size_t n, t_data_cmp cmp_f);

//			INFO: reverse the order of elements
bool		ft_vec_reverse(t_vector *vector);
//			INFO: reverse the order of up to n first elements
bool		ft_vec_nreverse(t_vector *vec, size_t n);

//			INFO: swap the value at position a and postion b.
//			a and b can be negativ and then refer to the elements from the back
//			-1 : last element, 0 : first element, 1: second ...
void		ft_vec_swap(t_vector *vec, ssize_t a, ssize_t b);
//			INFO: swap the n values at position a and postion b.
//			a and b can be negativ and then refer to the elements from the back
//			-1 : last element, 0 : first element, 1: second ...
//			if a+n or b+n is out of bounds fails.
void		ft_vec_nswap(t_vector *vec, size_t n, ssize_t a, ssize_t b);

// REDUCE
//			INFO: shift the vector from start of shift elements
//			eg: {1, 2, 3, 4} 1 2 -> {1, 4}
void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);
//			INFO: advances the values by move in vector data
//			eg: {1, 2, 3, 4} 2 -> {3, 4}
bool		ft_vec_advance(t_vector *v, size_t n);

//			INFO: shrink to fit only the data present in the vector
bool		ft_vec_shrink(t_vector *vec);
//			INFO: shrink to fit but keep at least min slots for the data
bool		ft_vec_shrink_min(t_vector *v, size_t min);

//			INFO: merge values of all elements using f and reduce size
//			accordingly.
//			the property of f(element@n, element@n+1) is always valid
void		ft_vec_fold(t_vector *v, void *(*f)(void *, void *));
//			INFO: merge values of n elements using f and reduce size
//			accordingly.
//			the property of f(element@n, element@n+1) is always valid
void		ft_vec_nfold(t_vector *v, size_t n,
				void *(*f)(void *, void *));
//			INFO: merge values of n elements using f and reduce size
//			accordingly. Do it starting from the back of the array.
//			the property of f(element@n, element@n+1) is always valid
void		ft_vec_nfold_r(t_vector *v, size_t n,
				void *(*f)(void *, void *));
//			INFO: call a fold function mlt times on n elements.
//			{1, 2, 3, 4, 5} 3 add_number 2 -> {((1+2)+3), 4, 5}
void		ft_vec_nfold_mltp(t_vector *v, size_t n,
				void *(*f)(void *, void *), size_t mlt);
//			INFO: same as nfold_mltp but runs through the vector in reverse
//			{1, 2, 3, 4, 5} 3 add_number 2 -> {(1+(2+3)), 4, 5}
void		ft_vec_nfold_r_mltp(t_vector *v, size_t n,
				void *(*f)(void *, void *), size_t mlt);

//			INFO: set to 0 all the data and reset count
void		ft_vec_clear(t_vector *vec);
//			INFO: remove all elements returning false to filter using del if
//			present
void		ft_vec_filter(t_vector *vec, t_data_is filter, t_data_apply del);
//			INFO: remove all elements returning true to filter using del if
//			present
void		ft_vec_filterout(t_vector *vector, t_data_is filter,
				t_data_apply del);

//			INFO: remove n elements from vec using `del`
void		ft_vec_remove(t_vector *vec, size_t n, t_data_apply del);
//			INFO: remove n elements from vec at start using `del` if present
void		ft_vec_nremove(t_vector *vec, size_t start, size_t n,
				t_data_apply del);

// CMP
//			INFO: compares vector a to vector b using function fc if present
//			otherwise uses ft_memcmp
int			ft_vec_cmp(const t_vector *a, const t_vector *b, t_data_cmp fc);
//			INFO: compares vector a to array b using function fc if present
//			otherwise uses ft_memcmp
int			ft_vec_acmp(const t_vector *a, const void *b, t_data_cmp fc);
//			INFO: compares n elements to vector a to vector b using function
//			fc if present otherwise uses ft_memcmp
int			ft_vec_ncmp(const t_vector *a, size_t n, const t_vector *b,
				t_data_cmp fc);
//			INFO: compares n elements to vector a to array b using function
//			fc if present otherwise uses ft_memcmp
int			ft_vec_ancmp(const t_vector *a, size_t n, const void *b,
				t_data_cmp fc);

// GET
//			INFO: itterates all elements with function fw and init_val
//			passed in calls as second parameter
void		*ft_vec_collect(const t_vector *v, void *init_val,
				t_data_apply_with fw);
//			INFO: itterates n elements with function fw and init_val
//			passed in calls as second parameter
void		*ft_vec_ncollect(const t_vector *v, size_t n, void *init_val,
				t_data_apply_with fw);
//			INFO: itterates n elements starting from the end with function fw
//			and init_val passed in calls as second parameter
void		*ft_vec_ncollect_r(const t_vector *v, size_t n, void *init_val,
				t_data_apply_with fw);

//			INFO: obtain the position of the nth element in the array.
//			if n < 0 the position is counted from the end. NULL if OOB
void		*ft_vec_at(const t_vector *vec, ssize_t n);
//			INFO: searches using key and cmp is present otherwise justs does a
//			ft_memcmp comparaison
void		*ft_vec_find(const t_vector *vector, const void *key,
				t_data_cmp cmp);
//			INFO: gets element at position pos in vetor and set holder to
//			found value.
//			if pos < 0 the position is counted from the end. NULL if OOB
void		*ft_vec_get(const t_vector *v, ssize_t pos, void *holder);
//			INFO: set value in holder if find successfull.
//			if cmp is NULL, defaults to ft_memcmp
void		*ft_vec_findget(const t_vector *vector, const void *key,
				t_data_cmp cmp, void *holder);

//			INFO: returns the size in bytes of the size currently occupied by
//			the vector.
size_t		ft_vec_inuse(const t_vector *vec);

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
