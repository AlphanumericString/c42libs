/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_ishex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:36:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "tests/tests__all_modules_tests.h"
int	test_str_ishex(void)
{
	if (ft_str_ishex("0123456789abcdefABCDEF") != 1)
		return (1);
	if (ft_str_ishex("0xdeadbeef") != 1 || ft_str_ishex("0xDEADBEEF") != 1)
		return (2);
	if (ft_str_ishex("0xdeadbeefg") != 0 || ft_str_ishex("0xDEADBEEFG") != 0)
		return (3);
	if (ft_str_ishex("0x") != 0 || ft_str_ishex("0X") != 0)
		return (4);
	if (ft_str_ishex("0x+32") != 0 || ft_str_ishex("0x-32") != 0)
		return (5);
	if (ft_str_ishex("0x0x") != 0 || ft_str_ishex("0X0X") != 0)
		return (6);
	if (ft_str_ishex("-0x0") != 0 || ft_str_ishex("+0X0") != 0)
		return (7);
	if (ft_str_ishex("0x0") != 1 || ft_str_ishex("0X0") != 1)
		return (8);
	if (ft_str_ishex("") != 0)
		return (8);
	if (ft_str_ishex(NULL) != false)
		return (9);
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
