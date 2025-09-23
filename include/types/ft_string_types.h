/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/24 14:00:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_TYPES_H
# define FT_STRING_TYPES_H

# include <stddef.h>

// maximum number of file descriptors
//  - ft_gnl
# ifndef MAX_FD
#  ifdef TEST
#   define MAX_FD 15
#  else
//  there's unfortunately no way to know the maximum number of file descriptors
//	might need to acoomodate the makefile to add a -D
#   define MAX_FD 1024
#  endif
# endif

// default allocation size for t_strings
//  - ft_string_new
# ifndef FT_TSTR_BUFF
#  ifdef TEST
#   define FT_TSTR_BUFF 5
#  else
#   define FT_TSTR_BUFF 4096
#  endif
# endif

// buffer size for temporary read buffers
# ifndef MAX_GNL_FD
#  ifdef TEST
#   define MAX_GNL_FD 3
#  else
#   define MAX_GNL_FD 32
#  endif
# endif

# ifndef BUFFER_SIZE
#  ifdef TEST
#   define BUFFER_SIZE 5
#  else
#   define BUFFER_SIZE 4096
#  endif
# endif

/// @brief Structure representing a string
/// @param str The string
/// @param length The length of the string
/// @param capacity The capacity of the string
typedef struct s_string
{
	char	*str;
	size_t	length;
	size_t	capacity;
}			t_string;

#endif /* FT_STRING_TYPES_H */
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
