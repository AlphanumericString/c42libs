/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_get_envp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 11:50:59 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "tests/args_tests.h"

int	targ_getenvp(void)
{
	const char			*s;
	const char *const	*prev_ev = ft_ev();
	const char			*test_ev[] = {
		"TOTO=TITI", "HOME=notapath", "user=tests", NULL
	};

	ft_set_ev(test_ev);
	if (ft_get_env("giberish") || ft_get_env("") || ft_get_env(NULL))
		return (1);
	s = ft_get_env("user");
	if (!s || ft_strcmp(s, "tests"))
		return (2);
	s = ft_get_env("TOTO");
	if (!s || ft_strcmp(s, "TITI"))
		return (3);
	ft_set_ev(NULL);
	if (ft_get_env("TOTO"))
		return (4);
	return (ft_set_ev(prev_ev), 0);
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
