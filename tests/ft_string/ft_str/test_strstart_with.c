/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strstart_with.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 10:49:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:20:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_strstart_with(void)
{
	if (ft_strstart_with("Hello World", "Hello") != 1)
		return (1);
	if (ft_strstart_with("Hello World", "Hello!") != 0)
		return (1);
	if (ft_strstart_with("Hello World", "World") != 0)
		return (1);
	if (ft_strstart_with("Hello World", "Hello World") != 1)
		return (1);
	if (ft_strstart_with("Hello World", "Hello World!") != 0)
		return (1);
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
