/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 15:29:04 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/28 23:30:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LIB_H
# define FT_LIB_H

/* ************************************************************************** */
/* 					                                                          */
/* Module: ALL                                                                */
/* Prefix:	ft_,                      										  */
/*																		      */
/* This interface provides a simple solution to include the whole lib         */
/*		(without the test function internal to the lib), in both c and c++.   */
/*																			  */
/* ************************************************************************** */

// cpp compatibility
# ifdef __cplusplus

extern "C" {

# endif

// types
# include "ft_types.h"

// funcs
# include "ft_args.h"
# include "ft_char.h"
# include "ft_colors.h"
# include "ft_defs.h"
# include "ft_errno.h"
# include "ft_list.h"
# include "ft_map.h"
# include "ft_math.h"
# include "ft_optional.h"
# include "ft_pair.h"
# include "ft_string.h"
# include "ft_vector.h"

# ifdef __cplusplus
}
# endif

#endif /* FT_LIB_H */
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
