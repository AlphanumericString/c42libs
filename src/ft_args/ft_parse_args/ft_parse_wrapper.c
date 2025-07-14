/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_wrapper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:57:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:20:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "types/ft_args_types.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "internal/args_helper_types.h"

#include <stddef.h>
#include <stdlib.h>

static int	ft_parg_core(const char **argv, void *usr_strct)
{
	t_parser_state	state;

	ft_bzero(&state, sizeof(t_parser_state));
	state.arg_it = 1;
	state.opt_list = ft_get_opt_list();
	state.args = argv;
	while (argv[state.arg_it])
	{
		if (!ft_strcmp(argv[state.arg_it], "--"))
			return (ft_set_nbparg(state.arg_it + 1), EXIT_SUCCESS);
		if (argv[state.arg_it][0] != '-')
			return (ft_set_nbparg(state.arg_it), EXIT_SUCCESS);
		if (ft_strstart_with(argv[state.arg_it], "--"))
			v2_parse_long_opt(&state, argv, usr_strct);
		else
			v2_parse_short_opts(&state, argv, usr_strct);
		if (state.err)
			return (ft_set_nbparg(state.arg_it), EXIT_FAILURE);
	}
	return (ft_set_nbparg(state.arg_it), EXIT_SUCCESS);
}

int	ft_parse_args(const char **argv, void *usr_control_struct)
{
	const t_opt	*opt_list;
	size_t		i;
	uint16_t	j;

	if (!argv || !*argv)
		return (ft_set_nbparg(0), -1);
	ft_setup_prog(argv);
	opt_list = ft_get_opt_list();
	if (!opt_list)
		return (-1);
	i = 0;
	while (opt_list[i].func && !usr_control_struct)
	{
		j = opt_list[i].type;
		if ((j & FT_AH_MASK) != 0 && !usr_control_struct)
			return (-1);
		i++;
	}
	return (ft_parg_core(argv, usr_control_struct));
}
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
