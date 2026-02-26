/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_short_opt.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 19:56:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 02:04:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/args_helper_types.h"
#include "internal/args_helper.h"

#include "types/ft_args_types.h"
#include <stdlib.h>
#include <stddef.h>
#include <unistd.h>

static int	arg_ok(const char **args, t_parser_state *state,
				enum e_separator sep)
{
	const char	*current = args[state->arg_it];

	if ((sep == FT_AS_NEXT_ARG && current[state->in_arg_it + 1] != '\0')
		|| (sep == FT_AS_EQSIGN && current[state->in_arg_it + 1] != '='))
		return (1);
	if (sep == FT_AS_NEXT_ARG && state->args[state->arg_it + 1] == NULL)
		return (2);
	return (EXIT_SUCCESS);
}

static const char	*maybe_get_arg(const char **args, t_parser_state *state,
						enum e_has_arg harg, enum e_separator sep)
{
	if (harg == FT_AH_MAYBE && arg_ok(args, state, sep) != EXIT_SUCCESS)
		return (NULL);
	if ((harg == FT_AH_YES || harg == FT_AH_MAYBE)
		&& arg_ok(args, state, sep) == EXIT_SUCCESS)
	{
		if (sep == FT_AS_NEXT_ARG)
			return (args[state->arg_it + 1]);
		else if (sep == FT_AS_EQSIGN)
			return (&args[state->arg_it][state->in_arg_it + 2]);
		return (perror_pa_state(state, "Unkown separator flag"), NULL);
	}
	else if (harg == FT_AH_YES || harg == FT_AH_MAYBE)
	{
		if (arg_ok(args, state, sep) == 1)
			return (perror_pa_state(state, "Couldn't find separator"), NULL);
		return (perror_pa_state(state, "Missing argument"), NULL);
	}
	return (perror_pa_state(state, "Couldn't parse harg flag"), NULL);
}

static void	v2_parse_short_opt_inner(t_parser_state *state, size_t op,
				const char **args, void *data)
{
	const t_opt				*ls = state->opt_list;
	const enum e_has_arg	has_arg = ls[op].type & FT_AH_MASK;
	const enum e_separator	separator = ls[op].type & FT_AS_MASK;
	const enum e_arg_types	arg_type = ls[op].type & FT_AT_MASK;
	const char				*arg = NULL;

	if (has_arg == FT_AH_NO)
	{
		state->in_arg_it++;
		state->err = ((int (*)(void *))ls[op].func)(data);
		return ;
	}
	arg = maybe_get_arg(args, state, has_arg, separator);
	if (state->err)
		return ;
	check_arg(arg_type, state, arg);
	if (state->err)
		return ;
	if (arg)
		state->arg_it += (separator == FT_AS_NEXT_ARG) + 1;
	state->in_arg_it = (state->in_arg_it + 1) * (arg == NULL);
	state->err = ((int (*)(void *, const char *))ls[op].func)(data, arg);
}

static void	char_runner(t_parser_state *state, const char **args,
				void *data, const char c)
{
	const t_opt	*ls = state->opt_list;
	size_t		op;

	op = 0;
	while (ls[op].func && ls[op].short_name != c)
		op++;
	if (!ls[op].func || !ls[op].short_name || ls[op].short_name != c)
	{
		perror_pa_state(state, "Unknown short option");
		return ;
	}
	return (v2_parse_short_opt_inner(state, op, args, data));
}

void	v2_parse_short_opts(t_parser_state *state, const char **args,
			void *data)
{
	state->in_arg_it = 1;
	state->mode = FTPA_SHORT;
	while (args[state->arg_it]
		&& args[state->arg_it][state->in_arg_it] && state->err == 0
		&& state->in_arg_it != 0)
		char_runner(state, args, data, args[state->arg_it][state->in_arg_it]);
	if (state->err || !state->in_arg_it)
		return ;
	state->arg_it++;
	state->in_arg_it = 0;
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
