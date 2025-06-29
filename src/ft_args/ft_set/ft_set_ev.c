/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_ev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 17:40:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/24 14:27:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "internal/args_helper.h"
#include "ft_defs.h"

#include <stdlib.h>

static const char *const	*ft_ev_singleton(const char *const *ev, bool set)
{
	static const char *const	*ev_st = NULL;

	if (set)
		ev_st = ev;
	return (ev_st);
}

// Dependant on c abi - lol
// ev are always sotred after av in mem acording to c std abi
// we use this property to access ev by just reading after the first NULL;;
int	ft_set_ev_from_av(const char *const *av, int ac)
{
	if (!av || !ac || av[ac] != NULL)
		return (ft_set_ev(NULL));
	return (ft_set_ev((const char *const *)(&av[ac + 1])));
}

int	ft_set_ev(const char *const *const ev)
{
	return (ft_ev_singleton(ev, true), EXIT_SUCCESS);
}

const char *const	*ft_ev(void)
{
	return (ft_ev_singleton(NULL, false));
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
