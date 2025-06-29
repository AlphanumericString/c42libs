/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_tests.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:39:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 17:17:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARGS_TESTS_H
# define ARGS_TESTS_H

// TODO: parse_arg tests :eyes: :sus:
int	parse_args_test(void);
int	targ_custom_checker_test(void);
int	targ_opt_list_test(void);

int	targ_shift_args(void);
int	targ_consume_args_test(void);

int	targ_setup_prog(void);
int	targ_ac(void);
int	targ_av(void);
int	targ_ev(void);
int	targ_parse(void);
int	targ_getenvp(void);
int	targ_version_test(void);
int	targ_program_name_test(void);

#endif /* ARGS_TESTS_H */
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
