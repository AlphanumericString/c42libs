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
# include <stddef.h>

// linux:
// stddef -> size_t
// stdbool -> boolean types
// sys/types -> ssize_t

# ifdef __APPLE__
#  define INVALID_SPE_CHARS "/:\""
#  define NEWLINE_SEQ "\n"
#  define PATH_SEPARATORS "/:"
#  define ENV_SEPARATORS ":"
#  include <stddef.h>
#  include <stdbool.h>
#  include <sys/types.h>
# elif defined(__linux__)
#  define INVALID_SPE_CHARS "?*/"
#  define NEWLINE_SEQ "\n"
#  define PATH_SEPARATORS "/"
#  define ENV_SEPARATORS ":"
#  include <stdbool.h>
#  include <sys/types.h>
# elif defined(_WIN32) || defined(_WIN64)
#  define INVALID_SPE_CHARS "\\:*?\"<>|"
#  define NEWLINE_SEQ "\r\n"
#  define PATH_SEPARATORS "\\/"
#  define ENV_SEPARATORS ";"
# else
#  define INVALID_SPE_CHARS ""
#  define NEWLINE_SEQ "\n"
#  define PATH_SEPARATORS "/"
#  define ENV_SEPARATORS ":"
#  include <stdbool.h>
#  include <sys/types.h>
# endif

# if defined(__APPLE__) || defined(__linux__)

typedef bool			t_bool;
typedef ssize_t			t_ssize;

# elif defined(_WIN32) || defined(_WIN64)

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef signed size_t	t_ssize;

# else

typedef bool			t_bool;
typedef ssize_t			t_ssize;

# endif

/// @brief	Base array interface, maps to void **
typedef void **t_arr;

/// @brief	Array interface where inside and outside are consts, maps to
///		const void *const *
typedef const void *const *t_const_arr;

/// @brief	Arrayinterface where the data inside the sub ptrs are consts,
///		maps to const void **
typedef const void **t_iconst_arr;

/// @brief	Arrayinterface where the data inside the sub ptrs is not const but
///		the holder to them is, maps to void *const *t_oconst_arr
typedef void *const *t_oconst_arr;

/// @brief	interface for string hashes.
/// @param	str	The string to hash
/// @param	str_len	The lenght of the string to hash, if -1 hashes until '\0'
typedef size_t			(*t_strhash)(const char *str, ssize_t str_len);

/// @brief Interface for string hashes.
/// @param str	The string to hash
/// @param data_len	The lenght of the string to hash, if -1 hashes until '\0'
typedef size_t			(*t_memhash)(const void *data, size_t data_len);

/// @brief	Type of function to compare two elements
/// @param	A The first element to compare
/// @param	B The second element to compare
/// @return	Standard cmp c function ( < 0, 0, > 0 for a < b, a == b, a > b)
typedef int				(*t_data_cmp)(const void *, const void *);

/// @brief	Type of function to apply on a node data
/// @param	Data The data to apply the function on
/// @return Void
typedef void			(*t_data_apply)(void *);

/// @brief	Type of function to see if a node data is something
/// @return	True if the data is what we are looking for, false otherwise
typedef bool			(*t_data_is)(const void *);

/// @brief	Type of function to transform a data into something else
/// @return	The new data
typedef void			*(*t_data_tr)(const void *);

/// @brief	Type of function to transform inplace a data into some other data
/// @return	pointer to the data (think of strcat or memcpy, returns a pointer
///	to dst)
typedef void			*(*t_data_tr_i)(void *);

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
