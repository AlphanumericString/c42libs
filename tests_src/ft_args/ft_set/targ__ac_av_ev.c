/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ__ac_av_ev.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 20:09:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "internal/args_helper.h"
#include "tests/args_tests.h"

#include <stdlib.h>
#include <stddef.h>

int	targ_ac(void)
{
	const int	acs[] = {0, -3, 3};
	int			ret;
	size_t		it;

	it = 0;
	while (it < sizeof(acs) / sizeof(acs[0]))
	{
		ft_set_ac(acs[it]);
		ret = ft_ac();
		if (acs[it] > 0 && acs[it] != ret)
			return (it + 1);
		it++;
	}
	return (EXIT_SUCCESS);
}

int	targ_ev_from_acav(void)
{
	const char			*av_fake[] = {
		"toto", "prout", NULL, "pipi", "caca", NULL};
	const char *const	*prev_ev = ft_ev();
	const char *const	*prev_av = ft_av();
	const int			prev_ac = ft_ac();

	ft_set_ev_from_av(av_fake, 2);
	if (ft_ev() != av_fake + 3)
		return (1);
	ft_set_ev_from_av(av_fake, 1);
	if (ft_ev() == av_fake + 1)
		return (2);
	if (ft_set_ev_from_av(NULL, 0) != EXIT_FAILURE
		|| ft_ev() != av_fake + 3)
		return (3);
	return (ft_set_ev(prev_ev), ft_set_av(prev_av),
		ft_set_ac(prev_ac), 0);
}

int	targ_ev(void)
{
	const char			*evs[][2] = {{"toto", "prout"}, {"pipi", "caca"}};
	const char *const	*prev;

	prev = ft_ev();
	ft_set_ev((const char *const *)evs[0]);
	if (ft_ev() != (const char *const *)evs[0])
		return (1);
	ft_set_ev((const char *const *)evs[1]);
	if (ft_ev() != (const char *const *)evs[1])
		return (2);
	ft_set_ev(NULL);
	if (ft_ev() != NULL)
		return (3);
	return (ft_set_ev(prev), 0);
}

int	targ_av(void)
{
	const char *const	*prev = ft_av();
	const int			prev_ac = ft_ac();
	const char			*args[][4] = {{"toto", "prout", NULL, NULL},
	{"0", "1", "2", NULL}};

	if (ft_set_av(args[0]) != EXIT_SUCCESS || ft_av() != args[0])
		return (1);
	if (ft_set_av(args[1]) != EXIT_SUCCESS || ft_av() != args[1])
		return (2);
	if (ft_set_av(NULL) != EXIT_FAILURE || ft_av() != args[1])
		return (3);
	return (ft_set_av(prev), ft_set_ac(prev_ac));
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
