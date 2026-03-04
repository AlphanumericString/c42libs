/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:19:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARGS_H
# define FT_ARGS_H

/* ************************************************************************** */
/*                                                                            */
/* Module: FT_ARGS                                                            */
/* Prefix: ft_arg                                                             */
/*                                                                            */
/* The Module FT_ARGS provides an easy way to handle task related to the cli  */
/*		arguments both for manipulation and parsing.	                      */
/*                                                                            */
/* ************************************************************************** */

// [idea shellved] : pb was to ugly to resolve in core and complexified the
// logic for minimum benefits
// // [CARG:common Args]
// // Auto handle common args options such as 'v'|"version" 'h'|"help"
// // 0 -> no.
// // !0 -> yes.
// // pb: either malloc the t_opt list or mixup in core logic
// # ifndef FT_AUTO_HANDLE_CARGS
// #  define FT_AUTO_HANDLE_CARGS 1
// # endif

# include "ft_defs.h"
# include "types/ft_args_types.h"

// args parser
//
/// @brief argument parser
/// WARNING: these function is NOT thread-safe.
/// It uses static variables.
///
/// @note not MT-safe
/// @note not AC-Safe
/// @note not AS-Safe
int					ft_arg_set_custom_checker(t_data_is custom_checker);
int					ft_set_opt_list(t_opt *opt_list);
void				ft_print_opts(const t_opt opt, int fd);
void				ft_print_fopts(const t_opt *opt, int fd);
int					ft_parse_args(const char **argv,
						void *usr_control_struct);

/// @brief setup program vars -> ac, av, ev
void				ft_setup_prog(const char *const *const av);

/// @brief getters for vals
/// @return ac, av, ev, progname, version
///
/// @note MT-safe
/// @note not AC-Safe
/// @note not AS-Safe
int					ft_ac(void);
const char *const	*ft_av(void);
const char *const	*ft_ev(void);
const char			*ft_progname(void);
const char			*ft_version(void);
size_t				ft_get_nbparg(void);

/// @brief	Return the value of '$key'
/// @param	key the key to search in env
/// @return	return either null if not found/invalid-key otherwise the value
/// associated with $key (already truncate the 'key=' part)
///
/// @note MT-safe
/// @note no guarantee of AC-Safe
/// @note no guarantee of AS-Safe
const char			*ft_get_env(const char *key);

/// @brief	Returns a pointer to the first argument string pointed to by args
///  and decreases ac by one and increase args by one. It effectively 'shift'
///  the table by one while keeping the count of element consistent.
/// @param	args Pointer to a list of const char pointer
/// @param	ac Pointer to the number of elements in Args remaining
///		(argument count)
/// @return	The first string in args or NULL if it fails.
/// fail reasons might be: bad `args` pointer, `index` is 0 or negative.
///
/// @note MT-safe
/// @note no guarantee of AC-Safe
/// @note no guarantee of AS-Safe
const char			*ft_consume_args(const char **args[], int *ac);

/// @brief Moves the first arg to the nth element and decrease ac accordingly
/// @param av Pointer to a list of const char pointer (program arguments)
/// @param ac Pointer to the number of elements in Args
/// @param nb Number of elements to shift
///
/// @note MT-safe
/// @note no guarantee of AC-Safe
/// @note no guarantee of AS-Safe
void				ft_shift_args(const char *const **av, int *ac, int nb);

#endif /* FT_ARGS_H */
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
