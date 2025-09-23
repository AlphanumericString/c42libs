/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ__progname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 22:37:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/args_helper.h"
#include "ft_args.h"
#include "ft_string.h"
#include "tests/args_tests.h"

int	targ_program_name_test(void)
{
	char	*s1;
	char	*s2;

	s1 = "toto";
	s2 = 0;
	ft_set_progname(s1);
	if (ft_progname() != s1)
		return (1);
	ft_set_progname(s2);
	if (ft_progname() == s2)
		return (2);
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
