/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targp_perror_pa_state.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 19:32:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/20 19:32:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "internal/args_helper_types.h"
#include "tests/args_tests.h"

#include <unistd.h>

#define EXPECTED_LINE1 "Error:  Option `--test' : str.\n"
#define EXPECTED_LINE2 "Error: toto: Option `--test' : str.\n"

int	targ_perror_pa_state(void)
{
	int				ppe[2];
	const char		*args[] = {"--test", "argument"};
	t_parser_state	st;
	char			buffer[1024];

	ft_bzero(&st, sizeof(st));
	st.args = args;
	st.mode = FTPA_LONG;
	(pipe(ppe), dup2(ppe[1], STDERR_FILENO));
	perror_pa_state(&st, "str");
	ft_set_progname("toto");
	perror_pa_state(&st, "str");
	ft_bzero(buffer, 1024);
	read(ppe[0], &buffer, 1024);
	(dup2(STDERR_FILENO, ppe[1]), close(ppe[0]), close(ppe[1]));
	if (ft_strcmp(buffer, EXPECTED_LINE1 EXPECTED_LINE2) != 0)
		return (1);
	return (EXIT_SUCCESS);
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
