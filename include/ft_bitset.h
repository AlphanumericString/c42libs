/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bitset.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:25:07 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 03:33:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BITSET_H
# define FT_BITSET_H

/* ************************************************************************** */
/*                                                                            */
/* Module: FT_BITSET                                                          */
/* Prefix: ft_bs_*                                                            */
/*                                                                            */
/* The module ft_bitset is a module made for handling boolean flags compacted */
/*		by char steps (8bits). Does not handle precision on bit levels except */
/*		on get/set/toggle opperations.                                        */
/*                                                                            */
/* ************************************************************************** */

# include <stddef.h>
# include <stdint.h>
# include <stdbool.h>
# include "types/ft_bitset_types.h"

/* ************************************************************************** */
/*                               CREATE BITSET                                */
/* ************************************************************************** */

/// @brief Create a new bitset
/// @param size The size of the bitset
/// @return A pointer to the new bitset allocated in memory
/// @note You to free the bitset with ft_bs_free
t_bitset	*ft_bs_new(size_t size);

/// @brief Create a new bitset
/// @param size The size of the bitset
/// @return A new bitset allocated in memory
/// @note There is an underlying memory allocated, free with ft_bs_free_inner
t_bitset	ft_bs_create(size_t size);

/// @brief Create a new bitset from a string
/// @param ptr The pointer to where to sample bytes from
/// @param n The size number of bytes to sample from the pointer ptr
/// @return A pointer to the new bitset allocated in memory
/// @note Samples with multiple of 8 underneath, you can visualize ptr as a
///		`uint8_t *` and n as the number of 'uint8_t' read.
t_bitset	*ft_bs_new_from_mem(const void *ptr, size_t n);

/* ************************************************************************** */
/*                               DELETE BITSET                                */
/* ************************************************************************** */

/// @brief Reset all fields of the bitset to 0
/// @param bitset The bitset to clear
void		ft_bs_clear(t_bitset *bitset);

/// @brief Free the bitsetptr and all its inner fields
/// @param bitset The bitset to free
void		ft_bs_free(t_bitset **bitset);

/// @brief Free the inner fields of the bitset
/// @param bitset The bitset of which to free the inner fields
void		ft_bs_free_inner(t_bitset *bitset);

/* ************************************************************************** */
/*                               SETGET BITSET                                */
/* ************************************************************************** */

/// @brief Get the value of a bit in the bitset
/// @param bitset The bitset to get the value from
/// @param index The index of the raw to get
/// @return The value of the raw at this index
/// @note If the index is out of bounds, the function will return 0
uint8_t		ft_bs_get_raw(t_bitset *bitset, size_t raw_index);

/// @brief Get the value of a bit in the bitset
/// @param bitset The bitset to get the value from
/// @param index The index of the bit to get (not necessarily a multiple of 8)
/// @return The value of the bit at this index
/// @note If the index is out of bounds, the function will return 0
bool		ft_bs_get(t_bitset *bitset, size_t index);

/// @brief Set the value of a raw in the bitset
/// @param bitset The bitset to set the raw value in
/// @param index The index of the raw to set (will be multed by 8)
/// @param value The value of the raw to set
/// @return False if out of bounds, True otherwise
bool		ft_bs_set_raw(t_bitset *bitset, size_t raw_index, uint8_t value);

/// @brief Set the value of a bool in the bitset
/// @param bitset The bitset to set the value in
/// @param index The index of the bool to set
/// @return The value of the bool to set (0 - False, 1 - True)
/// @return False if out of bounds, True otherwise
bool		ft_bs_set(t_bitset *bitset, size_t index, bool value);

/* ************************************************************************** */
/*                               TOGGLE BITSET                                */
/* ************************************************************************** */

/// @brief Toggle the value of a bit in the bitset
/// @param bitset The bitset to toggle the value in
/// @param idx The index of the bit to toggle (not necessarily a multiple of 8)
/// @return False if out of bounds, True otherwise
bool		ft_bs_toggle(t_bitset *bitset, size_t idx);

/// @brief Toggle the value of a raw in the bitset
/// @param bitset The bitset to toggle the raw value in
/// @param index The index of the raw to toggle (must be a multiple of 8)
/// @return False if out of bounds, True otherwise
bool		ft_bs_toggle_raw(t_bitset *bitset, size_t index);

/* ************************************************************************** */
/*								  PRINT BITSET								  */
/* ************************************************************************** */

/// @brief Print the bitset in a human readable format eg:
///   ([true|false],){7}[true|false]\n
///   ...
///   with the number of lines being the number of t_bitset8 in the bitset
/// @param bitset The bitset to print
/// @param fd The file descriptor to print to
/// @note	The MSB is the first print and then decreases until the
///		LSB. Same is multiple bytes are present inside, byte n will be printed
///		before byte n - 1.
void		ft_bs_print(t_bitset *bitset, int fd);

/// @brief Print the bitset in a human readable format where the bits are
///   represented as 1 and 0 eg:
///   ([1|0],){7}[1|0]\n
///   ...
///   with the number of lines being the number of t_bitset8 in the bitset
/// @param bitset The bitset to print
/// @param fd The file descriptor to print to
/// @note	The MSB is the first print and then decreases until the
///		LSB. Same is multiple bytes are present inside, byte n will be printed
///		before byte n - 1.
void		ft_bs_print_binary(t_bitset *bitset, int fd);

/// @brief Print the bitset in a human readable format where the bits are
///   represented as 0x00 eg:
///   (0x... ){n - 1}0x...\n
///   where n is the number of t_bitset8 in the bitset (single line)
/// @param bitset The bitset to print
/// @param fd The file descriptor to print to
/// @note	The MSB is the first print and then decreases until the
///		LSB. Same is multiple bytes are present inside, byte n will be printed
///		before byte n - 1.
void		ft_bs_print_hex(t_bitset *bitset, int fd);

/// @brief Print the bitset in a human readable format where the bits are
///  represented as 000 to 255 eg:
///  (000, ){n - 1}000...\n
///  where n is the number of t_bitset8 in the bitset (single line)
/// @param bitset The bitset to print
/// @param fd The file descriptor to print to
/// @note	The MSB is the first print and then decreases until the
///		LSB. Same is multiple bytes are present inside, byte n will be printed
///		before byte n - 1.
void		ft_bs_print_decimal(t_bitset *bitset, int fd);

/* ************************************************************************** */
/*								 APPEND BITSET								  */
/* ************************************************************************** */

/// @brief Append a bitset to another bitset
/// @param bitset The bitset to append to
/// @param to_append The bitset to append
/// @return true - successful append call, false otherwise
/// @note To append to the front of the bistet, reverse the order of the
///   parameters
bool		ft_bs_append(t_bitset *bitset, t_bitset *to_append);

/* ************************************************************************** */
/*								 REMOVE BITSET								  */
/* ************************************************************************** */

/// @brief Remove the last Nth bytes from the back of the bitset
/// @param bitset The bitset to remove the bytes from
/// @param nbr The number of bytes to remove
void		ft_bs_remove(t_bitset *bitset, size_t nbr);

/// @brief Remove front Nth bytes from the back of the bitset
/// @param bitset The bitset to remove the byte from
/// @param nbr The number of bytes to remove
void		ft_bs_remove_front(t_bitset *bitset, uint8_t nbr);

#endif /* FT_BITSET_H */
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
