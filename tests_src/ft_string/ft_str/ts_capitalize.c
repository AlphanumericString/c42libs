/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 06:19:07 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:39:08 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__str_tests.h"
#include "ft_string.h"

int	ts_capitalize(void)
{
	const char	*expected = "Hello World! This Is A Test.";
	char		str1[32];
	char		str2[32];
	char		*res;

	ft_strlcpy(str1, "hello world! this is a test.", 32);
	res = ft_strcapitalize(str1);
	if (ft_strcmp(res, expected) != 0 || str1 != res)
		return (1);
	ft_strlcpy(str2, "hello woRLD! this is a test.", 32);
	res = ft_strcapitalize(str2);
	if (ft_strcmp(res, expected) != 0 || str2 != res)
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
