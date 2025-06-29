/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:24:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_strtok(void)
{
	char	test[50];
	char	lorem[30];

	lorem[0] = '\0';
	test[0] = '\0';
	ft_strlcpy(lorem, "Lorem ipsum dolor ", 30);
	ft_strlcpy(test, ":::path/to/file:::another/path::yet/:/another/path", 47);
	if (ft_strcmp(ft_strtok(lorem, " "), "Lorem") != 0
		|| ft_strcmp(ft_strtok(NULL, " "), "ipsum") != 0
		|| ft_strcmp(ft_strtok(NULL, " "), "dolor") != 0)
		return (1);
	if (ft_strcmp(ft_strtok(NULL, " "), "") != 0 || ft_strtok(NULL,
			" "))
		return (2);
	if (ft_strcmp(ft_strtok(test, ":"), "path/to/file") != 0
		|| ft_strcmp(ft_strtok(NULL, ":"), "another/path") != 0)
		return (3);
	if (ft_strcmp(ft_strtok(NULL, ":/"), "yet") != 0)
		return (4);
	if (ft_strcmp(ft_strtok(NULL, ":/"), "another") != 0)
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
