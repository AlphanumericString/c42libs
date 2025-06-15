/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_types.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:08:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 00:39:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_TYPES_H
# define FT_MATH_TYPES_H

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

# ifndef M_E
#  define M_E 2.71828182845904523536
# endif

# ifndef INFINITY
#  define INFINITY 0x7ff0000000000000ULL
# endif

# ifndef NAN
#  define NAN 0x7ff0000000000001ULL
# endif

typedef struct s_complex
{
	double	real;
	double	imaginary;
}			t_complex;

typedef struct s_vec2
{
	double	x;
	double	y;
}			t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}			t_vec3;

typedef struct s_vec4
{
	double	x;
	double	y;
	double	z;
	double	w;
}			t_vec4;

typedef unsigned int	t_uint;

typedef struct s_dbl_fields
{
	unsigned long	mantissa : 52;
	unsigned long	exponent : 11;
	unsigned int	sign : 1;
}					t_dbl_fields;

typedef union s_double_explicit
{
	double			value;
	t_dbl_fields	fields;
}			t_double_explicit;

#endif /* FT_MATH_TYPES_H */
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
