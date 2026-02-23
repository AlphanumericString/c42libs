/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:13:10 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:42:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_TYPES_H
# define FT_VECTOR_TYPES_H

# ifndef FT_VECTOR_BASE_LEN
#  ifdef TEST
#   define FT_VECTOR_BASE_LEN 5
#  else
#   define FT_VECTOR_BASE_LEN FT_STD_BUF_SIZE
#  endif
# endif

# include <stddef.h>

# ifdef MT_DATA_BLOCK

typedef struct s_vector
{
	void	*data;
	size_t	n_e;
	size_t	s_e;
	size_t	cappacity;
	void	*meta_data;
}			t_vector;
# else

typedef struct s_vector
{
	void	*data;
	size_t	n_e;
	size_t	s_e;
	size_t	cappacity; // number max of ELEMENTS it can store. 
	// not total storage disponible.
}			t_vector;

# endif

#endif /* FT_VECTOR_TYPES_H */
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
