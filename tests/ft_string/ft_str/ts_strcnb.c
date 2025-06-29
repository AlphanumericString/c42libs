/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strcnb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:47:58 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdio.h>
#include "tests/tests__all_modules_tests.h"

int	test_strcnb(void)
{
	if (ft_strcnb("Hello World", 'o') != 2)
		return (1);
	if (ft_strcnb("Hello World", 'z') != 0)
		return (2);
	if (ft_strcnb("Hello World", 'H') != 1)
		return (3);
	if (ft_strcnb("Hello World", 'd') != 1)
		return (4);
	if (ft_strcnb("Hello World", 'l') != 3)
		return (5);
	if (ft_strcnb(NULL, ' ') != 0)
		return (6);
	if (ft_strcnb("toto", '\0') != 1)
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
