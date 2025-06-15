/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ncmp_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/30 07:26:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "types/ft_string_types.h"
#include "tests/tests__all_modules_tests.h"

int	test_string_ncmp_str(void)
{
	t_string	*str;
	t_string	*str2;
	t_string	*str3;
	t_string	*str4;

	str = ft_string_from("Hello World");
	str2 = ft_string_from("Hello Worle");
	str3 = ft_string_from("Hello Worla");
	str4 = ft_string_from("Hello");
	if (ft_string_ncmpstr(str, str2, 10) != 0 || \
ft_string_ncmpstr(str, str3, 10) != 0)
		return (1);
	if (ft_string_ncmpstr(str, str2, 11) == 0 || \
ft_string_ncmpstr(str, str3, 11) == 0 || \
ft_string_ncmpstr(str3, str, 11) == 0)
		return (2);
	if (ft_string_ncmpstr(str2, str, 99) == 0 || \
ft_string_ncmpstr(str3, str4, 9) == 0)
		return (6);
	return (ft_string_destroy(&str), ft_string_destroy(&str2),
		ft_string_destroy(&str3), ft_string_destroy(&str4), 0);
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
