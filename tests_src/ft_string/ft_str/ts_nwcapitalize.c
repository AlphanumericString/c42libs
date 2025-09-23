/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strnwcapitalize.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/06 06:25:03 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:40:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__str_tests.h"
#include "ft_string.h"

int	ts_nwcapitalize(void)
{
	const char	*exp = "Hello World! 42this Is a test.";
	const char	*exp2 = "Hello World! 42this Is A Test.";
	char		str1[32];

	ft_strlcpy(str1, "hello world! 42this is a test.", 32);
	ft_strnwcapitalize(str1, 4);
	if (ft_strcmp(str1, exp) != 0)
		return (1);
	ft_strnwcapitalize(str1, 999);
	if (ft_strcmp(str1, exp2) != 0)
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
