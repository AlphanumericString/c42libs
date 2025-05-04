/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:21:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_str_isint(void)
{
	if (ft_str_isint("23") != 1 || ft_str_isint("42") != 1 || \
	ft_str_isint("0") != 1 || ft_str_isint("-42") != 1 || \
	ft_str_isint("2147483647") != 1 || ft_str_isint("-2147483648") != 1)
		return (1);
	if (ft_str_isint("23.3") != 0 || ft_str_isint("42.0") != 0 || \
	ft_str_isint("0.0") != 0 || ft_str_isint("2.000000") != 0 || \
	ft_str_isint("0.000000") != 0 || ft_str_isint("2147483648") != 0 || \
	ft_str_isint("-2147483649") != 0 || ft_str_isint("2147483647.0") != 0 || \
	ft_str_isint("-2147483648.0") != 0)
		return (2);
	if (ft_str_isint("") != 0 || ft_str_isint("999999999999") != 0 || \
	ft_str_isint("-") != 0 || ft_str_isint("+") != 0)
		return (3);
	if (ft_str_isint(NULL) != false)
		return (4);
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
