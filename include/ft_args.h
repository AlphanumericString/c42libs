/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 23:42:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:15:05 by bgoulard         ###   ########.fr       */
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

// Change version with -DVERSION="x.y.z-W" via Makefile
# ifndef VERSION
#  define VERSION "1.0.0"
# endif

# include "ft_defs.h"
# include <sys/types.h>
# include "ft_args_types.h"

/* @file: src/ft_args/ft_arg_custom_checker.c */
void				ft_arg_set_custom_checker(t_data_is custom_checker);
t_data_is			ft_arg_get_custom_checker(void);

/* @file: src/ft_args/ft_setup_prog.c */
void				ft_setup_prog(const char *const *const av);

/// @file: src/ft_args/ft_parse_args
int					ft_parse_args(const char **argv, void *usr_control_struct);

void				ft_set_opt_list(const t_opt *opt_list);
const t_opt			*ft_get_opt_list(void);

// getters for vals
int					ft_ac(void);
const char *const	*ft_av(void);
const char *const	*ft_ev(void);
const char			*ft_progname(void);
const char			*ft_version(void);
// set vals
void				ft_set_progname(const char *program_name);
void				ft_set_version(const char *version);
int					ft_set_av(const char *const *const av);
int					ft_set_ac(int ac);
int					ft_set_ev(const char *const *const ev);

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
