/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 20:07:54 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:40:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__str_tests.h"
#include "ft_string.h"

int	ts_nupper(void)
{
	const char	*expected1 = "HELLO world!";
	const char	*expected2 = "ABCDEF+-?]SA;LKDJF\nghijklmn";
	char		str1[14];
	char		str2[32];
	char		*res;

	ft_strlcpy(str1, "Hello world!", 14);
	ft_strlcpy(str2, "abcdef+-?]sa;lkdjf\nghijklmn", 32);
	res = ft_strnupper(str1, 5);
	if (ft_strcmp(res, expected1) != 0 || str1 != res)
		return (1);
	res = ft_strnupper(str2, ft_strclen(str2, '\n'));
	if (ft_strcmp(res, expected2) != 0 || str2 != res)
		return (2);
	return (EXIT_SUCCESS);
}

int	ts_upper(void)
{
	const char	*expected1 = "HELLO WORLD!";
	const char	*expected2 = "ABCDEF+-?]SA;LKDJF\nGHIJKLMN";
	char		str1[14];
	char		str2[32];
	char		*res;

	ft_strlcpy(str1, "Hello World!", 14);
	ft_strlcpy(str2, "abcdef+-?]sa;lkdjf\nghIJKlmn", 32);
	res = ft_strupper(str1);
	if (ft_strcmp(res, expected1) != 0 || str1 != res)
		return (1);
	res = ft_strupper(str2);
	if (ft_strcmp(res, expected2) != 0 || str2 != res)
		return (2);
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
