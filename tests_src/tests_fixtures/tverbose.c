/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tverbose.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 01:40:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/06 01:40:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/tests.h"

static t_verbosity	*tverbose_singleton(void)
{
	static t_verbosity	verbose = VERBOSE;

	return (&verbose);
}

t_verbosity	tverbose(void)
{
	return (*tverbose_singleton());
}

void	tverbose_set(t_verbosity verbose)
{
	*tverbose_singleton() = verbose;
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
