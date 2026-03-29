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

// TODO:	-- definitely
//				add_front, nadd_front
//				push_front ->add_front, push_back ->add
// TODO:	-- type change
// TODO: void->bool
//			void		ft_vec_shift(...); -> bool		ft_vec_shift(...);
// TODO:
//		rename: vec_shift -> vec_shift_at
//		rename: vec_advance -> vec_shift
// FIXME:
//		bugs on size = 3/2/1
// //		: merge values of n elements using f and reduce size
// //			accordingly. Do it starting from the back of the array.
// //			the property of f(element@n, element@n+1) is always valid
// void		ft_vec_nfold_r(t_vector *v, size_t n,
// 				void *(*f)(void *, void *));
// //		: same as nfold_mltp but runs through the vector in reverse
// //			{1, 2, 3, 4, 5} 3 add_number 2 -> {(1+(2+3)), 4, 5}
// void		ft_vec_nfold_r_mltp(t_vector *v, size_t n,
// 				void *(*f)(void *, void *), size_t mlt);

/* ************************************************************************** */
/*                                    ALLOC                                   */
/* ************************************************************************** */

/// @brief allocate a new vector using a standard number of elements
/// that are of size size_of_elements.
/// @param size_of_elements The size of the elements
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_create(size_t size_of_elements);
/// @brief create a vector using standard number of elem and leaving
/// e_size empty.
/// @warning this is deprecated use ft_vec_create instead
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_new(void) __attribute__((
					__deprecated__("please use create instead",
						"ft_vec_create")));

/// @brief create a vector with a guaranteed size in byte for the
/// vector. You are likely trying to use ft_vec_create if you only
/// have the size of the elements blocks.
/// @warning set elem sizes and number of elem yourself
/// @param size_in_byte The total size in bytes
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_from_size(size_t size_in_byte);
/// @brief create a vector using a copy of the array 'src'.
/// @param src The source array
/// @param e_nb The number of elements
/// @param e_size The size of each element
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_from_array(const void *src, size_t e_nb, size_t e_size);

/// @brief reserve so that at least 'size' additional elements can be
/// stored in the vector capacity.
/// @param vec The vector
/// @param size The additional size to reserve
/// @return true on success, false otherwise
bool		ft_vec_reserve(t_vector *vec, size_t size);

/// @brief allocate a vector with results from function func applied to all
/// elements of vec_src
/// @param vec_src The source vector
/// @param func The function to apply
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_map(const t_vector *vec_src, t_data_apply func);
/// @brief allocate a vector from the result of the first n elements
/// with func.
/// @param vec_src The source vector
/// @param n The number of elements to map
/// @param func The function to apply
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_nmap(const t_vector *vec_src, size_t n, t_data_apply func);

/// @brief return an allocated copy of a vector
/// @param vec The source vector
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_dup(const t_vector *vec);
/// @brief return an allocated copy of the first n elements of a vector
/// @param o The source vector
/// @param n The number of elements to duplicate
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_ndup(const t_vector *o, size_t n);

/* ************************************************************************** */
/*								INIT (NO ALLOC)								  */
/* ************************************************************************** */

/// @brief does not alloc vec - dereference then set fields and allocate
/// a buffer for at least e_nb elements of size 'size'.
/// @param vec The vector structure to initialize
/// @param e_nb The number of elements to preallocate
/// @param size The size of each element
/// @return The vector pointer on success, NULL otherwise
t_vector	*ft_vec_init(t_vector *vec, size_t e_nb, size_t size);
/// @brief copies data from an array into a new allocated internal buffer
/// inside a given vector. also sets elements size, number of elems
/// and all.
/// @param vec The vector
/// @param data The source array
/// @param e_nb The number of elements
/// @param e_size The size of each element
/// @return The vector pointer on success, NULL otherwise
t_vector	*ft_vec_ifrom_array(t_vector *vec, const void *data, size_t e_nb,
				size_t e_size);
/// @brief 'steals' the array and put in a vector w the number of
/// elements size of elements and all.
/// @param v The vector
/// @param data The allocated data array to steal
/// @param e_nb The number of elements
/// @param e_size The size of each element
/// @return The vector pointer on success, NULL otherwise
t_vector	*ft_vec_iconvert_allocarray(t_vector *v, void *data, size_t e_nb,
				size_t e_size);

/* ************************************************************************** */
/*                                CONVERTIONS                                 */
/* ************************************************************************** */

/// @brief 'steals' an array to create a vector
/// @param data The allocated data array
/// @param nmemb The number of elements
/// @param size The size of each element
/// @return The new vector on success, NULL otherwise
t_vector	*ft_vec_convert_alloccarray(void *data, size_t nmemb, size_t size);

/// @brief extract the array and free the vector
/// @param vec The vector to extraction from and free
/// @return The extracted array
void		*ft_vec_to_array(t_vector **vec);

/* ************************************************************************** */
/*                                  DESTROY                                   */
/* ************************************************************************** */

/// @brief frees only the inner data
/// @param v The vector
/// @return true on success, false otherwise
bool		ft_vec_wipe(t_vector *v);

/// @brief frees internal + frees vec
/// @param vec The vector
/// @return true on success, false otherwise
bool		ft_vec_delete(t_vector *vec);

/// @brief frees internal and free's *vec then set to null
/// @param vec Pointer to the vector to destroy
/// @return true on success, false otherwise
bool		ft_vec_destroy(t_vector **vec);

/* ************************************************************************** */
/*                                    POP                                     */
/* ************************************************************************** */

/// @brief reduce size by one and return element pointer in inner array.
/// @warning the data returned is a position in the inner array.
/// if it needs to be persistent use ft_vec_popget()
/// @param vec The vector
/// @return Pointer to the popped element in inner array
void		*ft_vec_pop(t_vector *vec);
/// @brief reduce size by one, set removed element in holder and return holder
/// @param vec The vector
/// @param holder The pointer to store the value
/// @return The holder pointer on success, NULL otherwise
void		*ft_vec_popget(t_vector *vec, void *holder);
/// @brief reduce size by n, set removed elements in holder and return holder
/// @param vec The vector
/// @param n The number of elements to pop
/// @param holder The pointer to store the values
/// @return The holder pointer on success, NULL otherwise
void		*ft_vec_npopget(t_vector *vec, size_t n, void *holder);

/* ************************************************************************** */
/*                                    ADD                                     */
/* ************************************************************************** */

/// @brief add data to vec
/// @param vec The vector
/// @param data The data to add
/// @return true on success, false otherwise
bool		ft_vec_add(t_vector *vec, const void *data);
/// @brief add n elements from data to vec
/// @param vec The vector
/// @param n The number of elements to add
/// @param data The data to add
/// @return true on success, false otherwise
bool		ft_vec_nadd(t_vector *vec, size_t n, const void *data);

/// @brief append elements from vec_src to vec_dst
/// @param vec_dst The destination vector
/// @param vec_src The source vector
/// @return true on success, false otherwise
bool		ft_vec_cat(t_vector *vec_dst, const t_vector *vec_src);
/// @brief append n elements from vec_src to vec_dst
/// @param vec_dst The destination vector
/// @param vec_src The source vector
/// @param n The number of elements to append
/// @return true on success, false otherwise
bool		ft_vec_ncat(t_vector *vec_dst, const t_vector *vec_src, size_t n);

/// @brief append elem to vec at position pos
/// @param vec The vector
/// @param pos The position to insert
/// @param elem The element to insert
/// @return true on success, false otherwise
bool		ft_vec_insert(t_vector *vec, size_t pos, const void *elem);
/// @brief append n elems to vec from elem at position pos
/// @param vec The vector
/// @param pos The position to insert
/// @param n The number of elements to insert
/// @param elem The elements to insert
/// @return true on success, false otherwise
bool		ft_vec_ninsert(t_vector *vec, size_t pos, size_t n,
				const void *elem);

/* ************************************************************************** */
/*                                   MODIFY                                   */
/* ************************************************************************** */

/// @brief apply function func to all elements of vector vec
/// @param vec The vector
/// @param func The function to apply
void		ft_vec_apply(t_vector *vec, t_data_apply func);

/// @brief apply function func to n elements of vector vec
/// @param vec The vector
/// @param n The number of elements to apply to
/// @param func The function to apply
void		ft_vec_napply(t_vector *vec, size_t n, t_data_apply func);

/// @brief change value at pos to value stored at data
/// @param v The vector
/// @param pos The position to set
/// @param data The data to set
/// @return true on success, false otherwise
bool		ft_vec_set(t_vector *v, ssize_t pos, const void *data);
/// @brief change n values at position pos to values stored at datas
/// @param v The vector
/// @param pos The position to set
/// @param n The number of elements to set
/// @param datas The datas to set
/// @return true on success, false otherwise
bool		ft_vec_nset(t_vector *v, ssize_t pos, size_t n, const void *datas);

/// @brief sort vec using cmp_f
/// @param vec The vector
/// @param cmp_f The compare function
void		ft_vec_sort(t_vector *vec, t_data_cmp cmp_f);
/// @brief sort a maximum of n elements of vec using cmp_f
/// @param vec The vector
/// @param n The number of elements to sort
/// @param cmp_f The compare function
void		ft_vec_nsort(t_vector *vec, size_t n, t_data_cmp cmp_f);

/// @brief reverse the order of elements
/// @param vector The vector
/// @return true on success, false otherwise
bool		ft_vec_reverse(t_vector *vector);
/// @brief reverse the order of up to n first elements
/// @param vec The vector
/// @param n The number of elements to reverse
/// @return true on success, false otherwise
bool		ft_vec_nreverse(t_vector *vec, size_t n);

/// @brief swap the value at position a and postion b.
/// @note a and b can be negativ and then refer to the elements from the back
/// -1 : last element, 0 : first element, 1: second ...
/// @param vec The vector
/// @param a The first position
/// @param b The second position
void		ft_vec_swap(t_vector *vec, ssize_t a, ssize_t b);
/// @brief swap the n values at position a and postion b.
/// @note a and b can be negative and then refer to the elements from the back
/// -1 : last element, 0 : first element, 1: second ...
/// @warning if a+n or b+n is out of bounds fails.
/// @param vec The vector
/// @param n The number of elements to swap
/// @param a The first position
/// @param b The second position
void		ft_vec_nswap(t_vector *vec, size_t n, ssize_t a, ssize_t b);

/* ************************************************************************** */
/*                                   REDUCE                                   */
/* ************************************************************************** */

/// @brief shift the vector from start of shift elements
/// eg: {1, 2, 3, 4} 1 2 -> {1, 4}
/// @param vec The vector
/// @param start The start position
/// @param shift The shift count
void		ft_vec_shift(t_vector *vec, size_t start, size_t shift);
/// @brief advances the values by move in vector data
/// eg: {1, 2, 3, 4} 2 -> {3, 4}
/// @param v The vector
/// @param n The move count
/// @return true on success, false otherwise
bool		ft_vec_advance(t_vector *v, size_t n);
/// @brief set to 0 all the data and reset count
/// @param vec The vector
void		ft_vec_clear(t_vector *vec);

/// @brief shrink to fit only the data present in the vector
/// @param vec The vector
/// @return true on success, false otherwise
bool		ft_vec_shrink(t_vector *vec);
/// @brief shrink to fit but keep at least min slots for the data
/// @param v The vector
/// @param min The minimum slots to keep
/// @return true on success, false otherwise
bool		ft_vec_shrink_min(t_vector *v, size_t min);

/// @brief merge values of all elements using f and reduce size accordingly.
/// the property of f(element@n, element@n+1) is always valid
/// @param v The vector
/// @param f The fold function
void		ft_vec_fold(t_vector *v, void *(*f)(void *, void *));
/// @brief merge values of n elements using f and reduce size accordingly.
/// the property of f(element@n, element@n+1) is always valid
/// @param v The vector
/// @param n The number of elements
/// @param f The fold function
void		ft_vec_nfold(t_vector *v, size_t n,
				void *(*f)(void *, void *));
/// @brief call a fold function mlt times on n elements.
/// {1, 2, 3, 4, 5} 3 add_number 2 -> {((1+2)+3), 4, 5}
/// @param v The vector
/// @param n The number of elements
/// @param f The fold function
/// @param mlt The multiplier count
void		ft_vec_nfold_mltp(t_vector *v, size_t n,
				void *(*f)(void *, void *), size_t mlt);

/// @brief remove all elements returning false to filter using del if present
/// @param vec The vector
/// @param filter The function to apply
/// @param del The delete function to apply to removed elements
void		ft_vec_filter(t_vector *vec, t_data_is filter, t_data_apply del);
/// @brief remove up to max elements returning false to filter using del
/// @param vec The vector
/// @param max The maximum elements to process
/// @param func The function to apply
/// @param del The delete function to apply to removed elements
void		ft_vec_nfilter(t_vector *vec, size_t max, t_data_is func,
				t_data_apply del);

/// @brief remove all elements returning true to filter using del if present
/// @param vector The vector
/// @param filter The function to apply
/// @param del The delete function to apply to removed elements
void		ft_vec_filterout(t_vector *vector, t_data_is filter,
				t_data_apply del);
/// @brief remove up to max elements returning true to filter using del
/// @param vec The vector
/// @param max The maximum elements to process
/// @param func The function to apply
/// @param del The delete function to apply to removed elements
void		ft_vec_nfilterout(t_vector *vec, size_t max, t_data_is func,
				t_data_apply del);

/// @brief remove n elements from vec using `del`
/// @param vec The vector
/// @param n The number of elements
/// @param del The delete function
void		ft_vec_remove(t_vector *vec, size_t n, t_data_apply del);
/// @brief remove n elements from vec at start using `del` if present
/// @param vec The vector
/// @param start The start position
/// @param n The number of elements
/// @param del The delete function
void		ft_vec_nremove(t_vector *vec, size_t start, size_t n,
				t_data_apply del);

/* ************************************************************************** */
/*                                    CMP                                     */
/* ************************************************************************** */

/// @brief compares vector a to vector b using function fc if present
/// otherwise uses ft_memcmp
/// @param a The first vector
/// @param b The second vector
/// @param fc The compare function
/// @return 0 if equal, non-zero otherwise
int			ft_vec_cmp(const t_vector *a, const t_vector *b, t_data_cmp fc);
/// @brief compares n elements to vector a to vector b using function
/// fc if present otherwise uses ft_memcmp
/// @param a The first vector
/// @param n The number of elements
/// @param b The second vector
/// @param fc The compare function
/// @return 0 if equal, non-zero otherwise
int			ft_vec_ncmp(const t_vector *a, size_t n, const t_vector *b,
				t_data_cmp fc);

/// @brief compares vector a to array b using function fc if present
/// otherwise uses ft_memcmp
/// @param a The first vector
/// @param b The array
/// @param fc The compare function
/// @return 0 if equal, non-zero otherwise
int			ft_vec_acmp(const t_vector *a, const void *b, t_data_cmp fc);
/// @brief compares n elements to vector a to array b using function
/// fc if present otherwise uses ft_memcmp
/// @param a The first vector
/// @param n The number of elements
/// @param b The array
/// @param fc The compare function
/// @return 0 if equal, non-zero otherwise
int			ft_vec_ancmp(const t_vector *a, size_t n, const void *b,
				t_data_cmp fc);

/* ************************************************************************** */
/*                                    GET                                     */
/* ************************************************************************** */

/// @brief iterates all elements with function fw and init_val
/// passed in calls as second parameter
/// @param v The vector
/// @param init_val The initial value
/// @param fw The apply function
/// @return The resulting pointer
void		*ft_vec_collect(const t_vector *v, void *init_val,
				t_data_apply_with fw);
/// @brief iterates n elements with function fw and init_val
/// passed in calls as second parameter
/// @param v The vector
/// @param n The number of elements
/// @param init_val The initial value
/// @param fw The apply function
/// @return The resulting pointer
void		*ft_vec_ncollect(const t_vector *v, size_t n, void *init_val,
				t_data_apply_with fw);
/// @brief iterates n elements starting from the end with function fw
/// and init_val passed in calls as second parameter
/// @param v The vector
/// @param n The number of elements
/// @param init_val The initial value
/// @param fw The apply function
/// @return The resulting pointer
void		*ft_vec_ncollect_r(const t_vector *v, size_t n, void *init_val,
				t_data_apply_with fw);

/// @brief obtain the position of the nth element in the array.
/// if n < 0 the position is counted from the end. NULL if OOB
/// @param vec The vector
/// @param n The position
/// @return The element pointer on success, NULL otherwise
void		*ft_vec_at(const t_vector *vec, ssize_t n);

/// @brief searches using key and cmp is present otherwise justs does a
/// ft_memcmp comparaison
/// @param vector The vector
/// @param key The key to search
/// @param cmp The compare function
/// @return The element pointer on success, NULL otherwise
void		*ft_vec_find(const t_vector *vector, const void *key,
				t_data_cmp cmp);
/// @brief set value in holder if find successfull.
/// if cmp is NULL, defaults to ft_memcmp
/// @param vector The vector
/// @param key The key to search
/// @param cmp The compare function
/// @param holder The pointer to store the value
/// @return The element pointer on success, NULL otherwise
void		*ft_vec_findget(const t_vector *vector, const void *key,
				t_data_cmp cmp, void *holder);

/// @brief gets element at position pos in vetor and set holder to
/// found value.
/// if pos < 0 the position is counted from the end. NULL if OOB
/// @param v The vector
/// @param pos The position
/// @param holder The pointer to store the value
/// @return The element pointer on success, NULL otherwise
void		*ft_vec_get(const t_vector *v, ssize_t pos, void *holder);
/// @brief gets n elements from position pos in vector and set holder to
/// found values.
/// if pos < 0 the position is counted from the end. NULL if OOB
/// @param v The vector
/// @param pos The start position
/// @param n The number of elements to get
/// @param hldr The pointer to store the values
/// @return The holder pointer on success, NULL otherwise
void		*ft_vec_nget(const t_vector *v, ssize_t pos, size_t n, void *hldr);

/// @brief returns the size in bytes of the size currently occupied by
/// the vector.
/// @param vec The vector
/// @return The size in bytes
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
