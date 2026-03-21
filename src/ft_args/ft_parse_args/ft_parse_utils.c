/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 04:24:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 23:38:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_defs.h"
#include "types/ft_args_types.h"
#include "ft_string.h"
#include "ft_stris.h"
#include "internal/args_helper.h"
#include "internal/args_helper_types.h"

#include <stddef.h>
#include <unistd.h>

#define SE	STDERR_FILENO

void	disp_loaded(int fd)
{
	const t_opt	*ls = ft_get_opt_list();
	size_t		i;

	i = 0;
	ft_print_fd(fd, "%s:\n", ft_progname());
	while (ls && ls[i].func)
	{
		if (ls[i].short_name || ls[i].long_name)
			ft_print_opts(ls[i], fd);
		i++;
	}
}

// get_arg shoud never fail.... but just in case...
const char	*get_arg(enum e_separator sep_flag, t_parser_state *state,
				const char **args)
{
	const char	*av_arg;

	state->err = 0;
	av_arg = NULL;
	if (sep_flag == FT_AS_NEXT_ARG)
		av_arg = args[state->arg_it + 1];
	else if (sep_flag == FT_AS_EQSIGN)
		av_arg = ft_strchr(args[state->arg_it], '=') + 1;
	else
		return (perror_pa_state(state, "Unknown separator", SE), NULL);
	if (!av_arg)
		return (perror_pa_state(state, "Missing argument", SE), NULL);
	else if (av_arg == (void *)1 || av_arg[1] == '\0')
		return (perror_pa_state(state, "invalid argument", SE), NULL);
	else
		return (av_arg);
}

// {NULL, FT_AT_STR, "string"},
// maybe add something to check non empty eg: ""
static const struct s_local_table	*get_table(void)
{
	size_t						i;
	static struct s_local_table	table[] = {
	{NULL, FT_AT_CUSTOM, "custom"},
	{NULL, FT_AT_UNSPECIFIED, "unspecified"},
	{(t_data_is)ft_str_isalnum, FT_AT_ALPHANUM, "alphanumeric"},
	{(t_data_is)ft_str_ishex, FT_AT_HEX, "hexadecimal"},
	{(t_data_is)ft_str_isoct, FT_AT_OCT, "octal"},
	{(t_data_is)ft_str_isint, FT_AT_INT, "integer"},
	{(t_data_is)ft_str_islong, FT_AT_LONG, "long"},
	{(t_data_is)ft_str_isdouble, FT_AT_FLOAT, "float"},
	{(t_data_is)ft_str_isdouble, FT_AT_DOUBLE, "double"},
	{(t_data_is)ft_str_isbool, FT_AT_BOOL, "boolean"},
	{(t_data_is)ft_str_isnum, FT_AT_NBR, "number"},
	{(t_data_is)ft_str_isfname, FT_AT_FNAME, "file name"},
	{NULL, FT_AT_STR, "string"}, // ?todo? see above
	{NULL, 0, NULL}
	};

	i = 0;
	if (table[i].type == FT_AT_CUSTOM && ft_arg_get_custom_checker())
		table[i].checker = ft_arg_get_custom_checker();
	return ((const struct s_local_table *)table);
}

int	check_arg(enum e_arg_types type, t_parser_state *state, const char *arg)
{
	const struct s_local_table	*table = get_table();
	size_t						i;

	i = 0;
	state->err = 1;
	while (table[i].name)
	{
		if (table[i].type == type)
		{
			if (table[i].checker && !table[i].checker(arg))
				return (perror_pa_state(state,
						"Invalid argument (type check)", SE), state->err);
			state->err = 0;
			return (EXIT_SUCCESS);
		}
		i++;
	}
	perror_pa_state(state, "Unknown argument type", SE);
	state->err = 2;
	return (EXIT_FAILURE);
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
