/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arena.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 11:35:06 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/21 22:00:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARENA_H
# define FT_ARENA_H

// scope based arena

/// @brief	starts a scope (also, will disable realloc + reallocarray)
void	ft_ar_scope_start(void);
/// @brief	removes a scope and free associated pointers
void	ft_ar_scope_end(void);
/// @brief	remove all scop in use and free internals
void	ft_ar_scope_endall(void);

/// @brief	removes a pointer from the curent scope handler
/// might be usefull in case of returning allocated values
void	ft_ar_extract_ptr(void *ptr);

#endif
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
