/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_setup_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 15:55:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:58 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "internal/args_helper.h"

#include "tests/args_tests.h"

int	targ_setup_prog(void)
{
	const char	*argv[] = {"dummy_prog", "--test", NULL, "ev_start", NULL};
	const char	*argv2[] = {NULL};
	const char	**argv3 = NULL;

	ft_setup_prog(argv);
	if (ft_progname() != argv[0])
		return (1);
	if (ft_strcmp(ft_version(), VERSION) != 0)
		return (2);
	if (ft_ac() != 2 || ft_ev() != &(argv[3]) || ft_ev()[0] != argv[3]
		|| ft_av()[1] != argv[1])
		return (3);
	ft_set_ev(NULL);
	ft_setup_prog(argv2);
	if (!ft_progname() || ft_strcmp(ft_progname(), "a.out"))
		return (6);
	if (ft_ac() != 0 || ft_ev() != NULL)
		return (7);
	ft_setup_prog(argv3);
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
