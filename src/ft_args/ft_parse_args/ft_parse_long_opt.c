/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_long_opt.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:56:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 02:12:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "types/ft_args_types.h"
#include "internal/args_helper.h"
#include "internal/args_helper_types.h"
#include "ft_string.h"

#include <stddef.h>
#include <unistd.h>

static bool	maybe_run(const char **args, t_parser_state state,
				enum e_has_arg harg_flag, enum e_separator sep_flag)
{
	if (harg_flag != FT_AH_MAYBE)
		return (false);
	if (sep_flag == FT_AS_NEXT_ARG
		&& (!args[state.arg_it + 1] || args[state.arg_it + 1][0] == '-'))
		return (false);
	if (sep_flag == FT_AS_EQSIGN && !ft_strchr(args[state.arg_it], '='))
		return (false);
	return (true);
}

static const char	*maybe_get_arg(const char **args, t_parser_state *state,
						enum e_has_arg harg_flag, enum e_separator sep_flag)
{
	const char	*av_arg;

	if (harg_flag == FT_AH_MAYBE
		&& !maybe_run(args, *state, harg_flag, sep_flag))
		av_arg = NULL;
	else
		av_arg = get_arg(sep_flag, state, args);
	return (av_arg);
}

static void	v2_parse_long_opt_inner(t_parser_state *st, size_t op,
				const char **args, void *data)
{
	const t_opt				*o_lst = st->opt_list;
	const enum e_has_arg	harg_flag = o_lst[op].type & FT_AH_MASK;
	const enum e_separator	sep_flag = o_lst[op].type & FT_AS_MASK;
	const char				*value;

	if (harg_flag == FT_AH_NO)
	{
		st->arg_it++;
		st->err = ((int (*)(void *))o_lst[op].func)(data);
		return ;
	}
	else if (harg_flag == FT_AH_YES || harg_flag == FT_AH_MAYBE)
	{
		value = maybe_get_arg(args, st, harg_flag, sep_flag);
		if (st->err)
			return ;
		if ((value && harg_flag != FT_AH_MAYBE) || harg_flag != FT_AH_MAYBE)
			check_arg(o_lst[op].type & FT_AT_MASK, st, value);
		if (st->err)
			return ;
		st->arg_it += 1 + (value != NULL) * (sep_flag != FT_AS_EQSIGN);
		st->err = ((int (*)(void *, const char *))o_lst[op].func)(data, value);
		return ;
	}
	perror_pa_state(st, "Couldn't parse harg flag ", STDERR_FILENO);
}

static void	explain(const char *arg)
{
	ft_print_fd(STDERR_FILENO, "Unkown long option '%s'\n", arg);
	ft_print_fd(STDERR_FILENO, "To supress this and run as program's argumen"
		"run with %s `--' '%s'\n", ft_progname(), arg);
	disp_loaded(STDERR_FILENO);
}

void	v2_parse_long_opt(t_parser_state *st, const char **av, void *data)
{
	const t_opt		*ls = st->opt_list;
	size_t			op;
	const char		*str_o;
	size_t			cmp_len;

	op = 0;
	st->mode = FTPA_LONG;
	str_o = av[st->arg_it] + 2;
	cmp_len = ft_strclen(str_o, '=');
	if (cmp_len == ft_strlen(str_o))
		cmp_len = -1;
	while (ls[op].func
		&& !(ls[op].long_name
			&& !ft_strncmp(ls[op].long_name, str_o, cmp_len)))
		op++;
	if (!ls[op].func
		|| !(ls[op].long_name
			&& !ft_strncmp(ls[op].long_name, str_o, cmp_len)))
	{
		st->err = 1;
		return (explain(av[st->arg_it]));
	}
	v2_parse_long_opt_inner(st, op, av, data);
	return ;
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
