/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   talloc_failpoint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 11:55:07 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/24 14:30:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>
#include "tests/fixtures.h"

int	*talloc_get_failpoint(void)
{
	static int	failpoint = 0;

	return (&failpoint);
}

void	talloc_set_failpoint(int val)
{
	int	*current;

	current = talloc_get_failpoint();
	*current = val;
	return ;
}

int	*talloc_get_currentpoint(void)
{
	static int	currentpoint = 0;

	return (&currentpoint);
}

void	talloc_set_currentpoint(int val)
{
	int	*current;

	current = talloc_get_currentpoint();
	*current = val;
	return ;
}

bool	talloc_is_ok(void)
{
	const int	*failpoint = talloc_get_failpoint();
	int			*current;

	current = talloc_get_currentpoint();
	if (*current < *failpoint)
	{
		*current += 1;
		return (true);
	}
	return (false);
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
