/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:10 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:39:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_cmp(void)
{
	const char	*buffs[] = {
		"none", "some",
		"nonethensome",
		"nonethensome",
		"!\0a", "!\0b",
	};

	if (ft_strcmp(buffs[0], buffs[1]) >= 0)
		return (1);
	if (ft_strcmp(buffs[0], buffs[2]) >= 0)
		return (2);
	if (ft_strcmp(buffs[2], buffs[3]) != 0)
		return (3);
	if (ft_strcmp(buffs[4], buffs[5]) != 0)
		return (4);
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
