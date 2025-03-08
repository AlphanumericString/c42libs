/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 23:11:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TYPES_H
# define FT_TYPES_H

/* ************************************************************************** */
/*                                                                            */
/* Useful in early development of projects where you might no know what you   */
/*		want from the ft_personal lib - otherwise if you already know what    */
/*		you use / are at the end of a project remove this to lighten the .h   */
/*		step of compilation													  */
/*                                                                            */
/* ************************************************************************** */

// true - false
# include <stdbool.h>

// size_t - ssize_t - ptrdiff_t ... NULL
# include <stddef.h>

// int8_t - int16_t - uint32_t ... INT_MAX - INT_MIN
# include <stdint.h>

# include "ft_args_types.h"
# include "ft_list_types.h"
# include "ft_map_types.h"
# include "ft_math_types.h"
# include "ft_optional_types.h"
# include "ft_pair_types.h"
# include "ft_string_types.h"
# include "ft_vector_types.h"

#endif /* FT_TYPES_H */
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
