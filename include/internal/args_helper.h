/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_helper.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:47:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:18:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_HELPER_H
# define ARGS_HELPER_H

# include "ft_args_types.h"
# include <stddef.h>
# include <sys/types.h>

// Parser opt
//
// Parse long option
ssize_t	parse_long_opt(const char *str_op, const t_opt *opt_list);
// Parse short option
ssize_t	parse_short_opt(const char *str_op, const t_opt *opt_list);

// Checker
//
// Check if the argument is valid
int		checker_arg(t_opt_type type, const char *arg);

// Run
//
// Run the function associated with the option
int		run_opt_func(const t_opt opt, void *usr_control_struct, \
		const char **arg, int *i);

// Error
//
// Print error message for option
int		arg_opt_err(const char *opt);
// Print error message for argument type
int		arg_type_err(const t_opt opt, const char *arg);

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
