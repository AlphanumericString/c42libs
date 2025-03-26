/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:36:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "tests/tests__all_modules_tests.h"
int	test_split(void)
{
	const char	*str = "  Hello World!  ";
	char		**res;
	const char	*str2 = "Hello World!  ";
	char		**res2;
	size_t		i;

	res = ft_split(str, ' ');
	res2 = ft_split(str2, ' ');
	if (ft_strcmp(res[0], "Hello") != 0 || ft_strcmp(res[1], "World!") != 0
		|| res[2])
		return (1);
	if (ft_strcmp(res2[0], "Hello") != 0 || ft_strcmp(res2[1], "World!") != 0
		|| res2[2])
		return (2);
	i = 0;
	while (res[i])
		ft_free(res[i++]);
	i = 0;
	while (res2[i])
		ft_free(res2[i++]);
	return (ft_free(res), ft_free(res2), 0);
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
