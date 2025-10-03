/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optional.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:07:13 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:10:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OPTIONAL_H
# define FT_OPTIONAL_H

/* ************************************************************************** */
/*											                                  */
/* Module: FT_OPTIONAL                                                        */
/* Prefix: ft_optional                                                        */
/*																			  */
/* The FT_OPTIONAL module provides a way to add the optional type to the      */
/*		project, this type is used to handle the case where a function can    */
/*		return a value or nothing, or to chain functions on a pointer		  */
/*		(creating a 'pipeline' for the data to follow).					      */
/*                                                                            */
/* ************************************************************************** */

# include "ft_defs.h"
# include "types/ft_optional_types.h"
# include <stdbool.h>

/// @brief Create a new empty optional
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional	*ft_optional_new(void);

/// @brief Create a new optional with a value
/// @param ptr The value to store in the optional
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional	*ft_optional_from_val(const void *ptr);

/// @brief Copies the value of an optional into another
/// @param dest The destination optional
/// @param src The source optional
void		ft_optional_copy(t_optional *dest,
				const t_optional *src);

/// @brief Chain functions calls on an optional until either there are no more
/// functions to call or one of the functions returns NULL
/// @param opt The optional to chain
/// @param f The functions to call
/// @return true if all functions were called, false otherwise
/// @note This function was made to emulate object programming pipelines
/// @note WARNING: The function will return false if the optional is empty
/// or if the function list is NULL
bool		ft_optional_chain(t_optional *opt, const t_data_tr_i *f);

/// @brief Map a result of a function on an optional
/// @param opt The optional with the value to map
/// @param f The function to call
/// @return The new optional with the result of the functions.
/// @note WARNING: The function will return an empty optional if the result
/// of the function is NULL.
t_optional	ft_optional_map(t_optional *opt, const t_data_tr_i f[]);

/// @brief Destroy an optional
/// @param opt The optional to destroy
/// @return true if the optional was destroyed, false otherwise
/// @note WARNING: The optional must be empty before destroying it
/// otherwise the function will return false
bool		ft_optional_destroy(t_optional *opt);

/// @brief Duplicate an optional
/// @param org The optional to duplicate
/// @return The new optional
/// @note prefer creating from stack
/// @note WARNING: you must free the optional after use
t_optional	*ft_optional_dup(const t_optional *org);

/// @brief Return the value contained in an optional
/// @param opt The optional to unwrap
/// @return The value contained in the optional
/// @note WARNING: The optional must not be empty otherwise the function will
/// crash
void		*ft_optional_unwrap(t_optional opt);

#endif /* FT_OPTIONAL_H */
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
