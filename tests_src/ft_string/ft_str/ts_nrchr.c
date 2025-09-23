/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_nrchr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 14:51:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/18 14:51:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

// 1: checks on "normal" ft_strrchr
// 2: checks on n parameter
int	ts_nrchr(void)
{
	const char	*str = "Hello World!";

	if (ft_strnrchr(str, -1, 'o') != str + 7
		|| ft_strnrchr(str, -1, 'z')
		|| ft_strnrchr(str, -1, '\0') != str + ft_strlen(str))
		return (1);
	if (ft_strnrchr(str, 5, 'o') != str + 4
		|| ft_strnrchr(str, 3, 'o'))
		return (2);
	if (ft_strnrchr(str, 0, '\0')
		|| ft_strnrchr(NULL, -1, 'a'))
		return (3);
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
