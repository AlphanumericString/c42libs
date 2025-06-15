/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_perror.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:35:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:42:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "internal/args_helper_types.h"
#include "internal/args_helper.h"

#include <unistd.h>

void	perror_pa_state(t_parser_state *st, const char *error)
{
	char	str[2];

	str[0] = st->args[st->arg_it][st->in_arg_it];
	str[1] = '\0';
	if (ft_progname())
		ft_print_fd(STDERR_FILENO, "Error: %s:", ft_progname());
	else
		ft_print_fd(STDERR_FILENO, "Error: ");
	if (st->mode == FTPA_SHORT)
		ft_print_fd(STDERR_FILENO, " Short option `-%s' : %s\n", str, error);
	else
		ft_print_fd(STDERR_FILENO, " Option `%s' : %s\n",
			st->args[st->arg_it], error);
	st->err = 1;
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
