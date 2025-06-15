/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitset_types.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:14:45 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:35:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITSET_TYPES_H
# define FT_BITSET_TYPES_H

// uint8_t
# include <stdint.h>

// size_t
# include <stddef.h>

/// @brief Structure to represent a bitset8
/// @param raw The raw value of the bitset8
/// @param b0 The first bit of the bitset8
/// @param b1 The second bit of the bitset8
/// @param b2 The third bit of the bitset8
/// @param b3 The fourth bit of the bitset8
/// @param b4 The fifth bit of the bitset8
/// @param b5 The sixth bit of the bitset8
/// @param b6 The seventh bit of the bitset8
/// @param b7 The eighth bit of the bitset8
/// @note Non-officially supported by the lib, would have put it in the
///   t_bitset struct but norminette is not happy with it *shrugs*
typedef union u_bitset8
{
	uint8_t		raw;
	struct
	{
		uint8_t	b0 : 1;
		uint8_t	b1 : 1;
		uint8_t	b2 : 1;
		uint8_t	b3 : 1;
		uint8_t	b4 : 1;
		uint8_t	b5 : 1;
		uint8_t	b6 : 1;
		uint8_t	b7 : 1;
	};
}				t_bitset8;

/// @brief Structure to represent a bitset
/// @param length The length of the bitset in bits
/// @param capacity The capacity of the bitset in bitset8
/// @param bits The bits of the bitset
/// @details diff between cappacity, and length, eg:
///   length = 6, capacity = 1, bits = {0b00000000}
///   length = 8, capacity = 1, bits = {0b00000000}
///   length = 9, capacity = 2, bits = {0b00000000, 0b00000000}
///   ...
typedef struct s_bitset
{
	size_t		_capacity;
	t_bitset8	*bits;
}				t_bitset;

#endif /* FT_BITSET_TYPES_H */
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
