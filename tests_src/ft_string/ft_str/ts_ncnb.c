/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_ncnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:47:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/15 14:38:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_ncnb(void)
{
	if (ft_strncnb("Hello World", -1, 'o') != 2)
		return (1);
	if (ft_strncnb("Hello World", -1, 'z') != 0)
		return (2);
	if (ft_strncnb("Hello World", 5, 'o') != 1)
		return (3);
	if (ft_strncnb("Hello World", 5, 'l') != 2)
		return (4);
	if (ft_strncnb("Hello World", 0, 'l') != 0)
		return (5);
	if (ft_strncnb(NULL, 42, ' ') != 0 || ft_strncnb(NULL, 0, ' ') != 0)
		return (6);
	if (ft_strncnb("toto", -1, '\0') != 1)
		return (7);
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
