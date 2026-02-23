/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:47:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:50:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_HELPER_H
# define ARGS_HELPER_H

# include <stddef.h>
# include <sys/types.h>

# include "internal/args_helper_types.h"
# include "types/ft_args_types.h"
# include "ft_defs.h"

// Setup
// -----
//
// set ev internal
int			ft_set_ev_from_av(const char *const *const av, int ac);
// set vals (don't use please)
void		ft_set_progname(const char *program_name);
// Change version with -DVERSION="x.y.z" at compile time
void		ft_set_version(const char *version);
int			ft_set_av(const char *const *const av);
int			ft_set_ac(int ac);
int			ft_set_ev(const char *const *const ev);

// PARSER
// ------
//
// private holders
t_data_is	ft_arg_get_custom_checker(void);
const t_opt	*ft_get_opt_list(void);
// private parser setters
void		ft_set_nbparg(size_t nb);
// private parser utils
const char	*get_arg(enum e_separator sep_flag, t_parser_state *state,
				const char **args);
int			check_arg(enum e_arg_types type, t_parser_state *state,
				const char *arg);
void		perror_pa_state(t_parser_state *st, const char *error);
//
// Parse utils (semi-private)
//
void		put_type_fd(uint16_t type, int fd);
void		disp_loaded(int fd);
//
// Parse long option only funcs
//
void		v2_parse_long_opt(t_parser_state *state, const char **args,
				void *data);
//
// Parse short option only func
//
void		v2_parse_short_opts(t_parser_state *state, const char **args,
				void *data);

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
