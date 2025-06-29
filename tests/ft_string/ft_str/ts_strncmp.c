/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:23:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_strncmp(void)
{
	const char	*str_buffs[] = {
		"none",
		"some",
		"nonethensome",
		"nonethensome",
		"!\0a",
		"!\0b",
		NULL
	};

	if (ft_strncmp(str_buffs[0], str_buffs[1], 4) >= 0)
		return (1);
	if (ft_strncmp(str_buffs[0], str_buffs[2], 4) != 0)
		return (2);
	if (ft_strncmp(str_buffs[2], str_buffs[3], 4) != 0)
		return (3);
	if (ft_strncmp(str_buffs[4], str_buffs[5], 4) != 0)
		return (4);
	if (ft_strncmp(str_buffs[5], str_buffs[0], 0) != 0)
		return (5);
	return (0);
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
