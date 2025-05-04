/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isalnum.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:21:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_str_isalnum(void)
{
	if (ft_str_isalnum("HelloWorld42") != 1)
		return (1);
	if (ft_str_isalnum("Hello World42") != 0)
		return (2);
	if (ft_str_isalnum("Hello21World!") != 0)
		return (3);
	if (ft_str_isalnum("Hello420BlazeIt.") != 0)
		return (4);
	if (ft_str_isalnum("HelloWorld696969\0") != 1)
		return (5);
	if (ft_str_isalnum("") != 0)
		return (6);
	if (ft_str_isalnum(NULL) != false)
		return (7);
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
