/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_defs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 14:55:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 15:28:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DEFS_H
# define FT_DEFS_H

// NULL    -> stddef.h
// bools   -> stdbool.h
// ssize_t -> stddef.h | sys/types.h (version dependent, idk, weird)
# include <stddef.h>
# include <stdbool.h>
# include <sys/types.h>

# ifndef EXIT_SUCCESS
#  define EXIT_SUCCESS 0
# endif

# ifndef EXIT_FAILURE
#  define EXIT_FAILURE 1
# endif

# define FT_MICRO_BUF_SIZE	16
# define FT_SMALL_BUF_SIZE	256
# define FT_STD_BUF_SIZE	4096
# define FT_LARGE_BUF_SIZE	65536

// Change version with -DVERSION="x.y.z" at compile time
# ifndef VERSION
#  define VERSION "1.0.0"
# endif
# ifndef AUTHOR
#  define AUTHOR "bgoulard <bgoulard@student.42.fr>"
# endif

# ifndef FT_VERSION
#  define FT_VERSION "0.0.12"
# endif

// maybe add a hash to the prefix to avoid collisions?
// sed in Makefile to replace '_COMPILETIME_HASH\s+\w*'
# ifndef FT_COMPILETIME_HASH
#  define FT_COMPILETIME_HASH "13"
# endif

// if for whatever reason it is def, put true in it
# ifdef FT_ALLOC_SELF
#  define FT_ALLOC_SELF true
# else
#  define FT_ALLOC_SELF false
# endif

# ifdef FT_THREADS
#  define FT_THREADS true
# else
#  define FT_THREADS false
# endif

// Paths and separators
# define FT_NEWLINE_SEQ "\n"
# define FT_PATH_SEPARATORS "/"
# define FT_ENV_SEPARATORS ":"

// Base strings for conversions
# define FT_HEXBASE			"0123456789abcdef"
# define FT_HEXBASE_CAP		"0123456789ABCDEF"
# define FT_DECBASE			"0123456789"
# define FT_OCTBASE			"01234567"
# define FT_BINBASE			"01"

//  Add other primitive types max and min (currently not needed)

# include <limits.h>

# define FT_SSIZE_MAX LONG_MAX
# define FT_SSIZE_MIN LONG_MIN
# define FT_SIZE_MAX ULONG_MAX
# define FT_SIZE_MIN 0

// TODO: implement algos
typedef enum e_sort_algorithms
{
	FT_SORT_ALG_BUBBLE = 0,
	FT_SORT_ALG_BUCKET,
	FT_SORT_ALG_INSERTION,
	FT_SORT_ALG_SELECTION,
	FT_SORT_ALG_SHAKER,
	// FT_SORT_ALG_QUICK,
	// FT_SORT_ALG_MERGE,
	// FT_SORT_ALG_HEAP,
	// FT_SORT_ALG_COUNTING,
	// FT_SORT_ALG_SHELL,
	FT_SORT_ALG_UNKNOWN, // 10 // 31 - 10 => 21 space left is ok
	FT_SORT_ALG_MASK = (1 << 5) - 1, // (2^5 - 1) = 31 = 0b00011111
}	t_sort_algorithms;

typedef enum e_sort_order
{
	FT_SORT_ORD_ASC = 1 << 5,
	FT_SORT_ORD_DES = 2 << 5,
	FT_SORT_ORD_UNO = 3 << 5, //< not sure is usefull
	FT_SORT_ORD_MASK = 7 << 5, // (2^3 - 1) << 5 = 0b11100000
}	t_sort_order;


typedef struct {
	void		*func;
	const char	*f_name;
} t_named_func;

/// @brief	Type maping to remove checks on type on any ptrs
typedef void				*t_any;

/// @brief	Base array interface, maps to void **
typedef void				**t_arr;

/// @brief	Array interface where inside and outside are consts, maps to
///		const void *const *
typedef const void *const	*t_const_arr;

/// @brief	Arrayinterface where the data inside the sub ptrs are consts,
///		maps to const void **
typedef const void			**t_iconst_arr;

/// @brief	Arrayinterface where the data inside the sub ptrs is not const but
///		the holder to them is, maps to void *const *t_oconst_arr
typedef void *const			*t_oconst_arr;

/// @brief	interface for string hashes.
/// @param	str	The string to hash
/// @param	str_len	The lenght of the string to hash, if -1 hashes until '\0'
typedef size_t				(*t_strhash)(const char *str, ssize_t str_len);

/// @brief Interface for string hashes.
/// @param data The memory to hash
/// @param data_len	The lenght of the memory to hash, if -1 hashes until '\0'
typedef size_t				(*t_memhash)(const void *data, size_t data_len);

/// @brief	Type of function to compare two elements
/// @param	a The first element to compare
/// @param	b The second element to compare
/// @return	Standard cmp c function ( < 0, 0, > 0 for a < b, a == b, a > b)
typedef int					(*t_data_cmp)(const void *a, const void *b);

/// @brief	Type of function to apply on a node data
/// @param	data The data to apply the function on
/// @return Void
typedef void				(*t_data_apply)(void *data);

/// @brief	Type of function to apply on a node data with an arg
/// @param	data The data to apply the function on
/// @param	arg	The argument to feed to the function
/// @return Void
typedef void				(*t_data_apply_with)(void *data, void *arg);

/// @brief	Type of function to see if a node data is something
/// @return	True if the data is what we are looking for, false otherwise
typedef bool				(*t_data_is)(const void *);

/// @brief	Type of function to transform a data into something else
/// @return	The new data
typedef void				*(*t_data_tr)(const void *);

/// @brief	Type of function to transform a data into something else with an arg
/// @return	The new data
typedef void				*(*t_data_tr_w)(const void *, void *);

/// @brief	Type of function to transform inplace a data into some other data
/// @param	data The data to transform in place
/// @return	pointer to the data (think of strcat or memcpy, returns a pointer
///	to dst)
typedef void				*(*t_data_tr_i)(void *data);

// asserts on basic defs needed for the lib to work

# if FT_MICRO_BUF_SIZE != 16
#  error "FT_SMALL_BUF_SIZE must be 256 bytes"
# endif
# if FT_SMALL_BUF_SIZE != 256 || FT_SMALL_BUF_SIZE != FT_MICRO_BUF_SIZE * 16
#  error "FT_SMALL_BUF_SIZE must be 256 bytes"
# endif
# if FT_STD_BUF_SIZE != 4096 || FT_STD_BUF_SIZE != FT_SMALL_BUF_SIZE * 16
#  error "FT_STD_BUF_SIZE must be 4096 bytes"
# endif
# if FT_LARGE_BUF_SIZE != 65536 || FT_LARGE_BUF_SIZE != FT_STD_BUF_SIZE * 16
#  error "FT_LARGE_BUF_SIZE must be 65536 bytes"
# endif

#endif /* FT_DEFS_H */
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
