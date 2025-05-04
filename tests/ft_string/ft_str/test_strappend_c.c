/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strappend_c.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:12:40 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:22:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

// calloc sets the \0 byte at the end of the string
// we test the function can append at empty string
int	test_strappend_c(void)
{
	char	*str;

	str = ft_strdup("Hello");
	if (!str)
		return (1);
	if (ft_strappend_c(&str, ' ') == 0 || ft_strcmp(str, "Hello ") != 0)
		return (2);
	if (ft_strappend_c(&str, 'W') == 0 || ft_strcmp(str, "Hello W") != 0)
		return (3);
	if (ft_strappend_c(NULL, '\0'))
		return (4);
	ft_free(str);
	str = ft_calloc(1, 1);
	if (!str || ft_strappend_c(&str, ' ') == 0 || ft_strcmp(str, " ") != 0)
		return (5);
	ft_free(str);
	str = NULL;
	if (ft_strappend_c(&str, ' ') == 0 || ft_strcmp(str, " ") != 0)
		return (6);
	ft_free(str);
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
