/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/14 22:58:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_nchr(void)
{
	char	*str;
	char	s;
	char	s2;
	char	*res;

	str = "Hello World!";
	s = 'o';
	s2 = 'z';
	res = ft_strnchr(str, -1, s);
	if (res != str + 4)
		return (1);
	res = ft_strnchr(str, 3, s);
	if (res)
		return (2);
	res = ft_strnchr(str, -1, s2);
	if (res)
		return (3);
	res = ft_strnchr(str, 0, '\0');
	if (res)
		return (4);
	res = ft_strnchr(str, -1, '\0');
	if (res != str + ft_strlen(str))
		return (5);
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
