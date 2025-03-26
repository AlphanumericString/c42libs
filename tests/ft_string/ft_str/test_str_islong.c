/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_islong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:36:23 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "tests/tests__all_modules_tests.h"
int	test_str_islong(void)
{
	if (ft_str_islong("23") != 1 || ft_str_islong("42") != 1 || \
	ft_str_islong("0") != 1 || ft_str_islong("2") != 1 || \
	ft_str_islong("-34") != 1 || ft_str_islong("42") != 1 || \
	ft_str_islong("9223372036854775807") != 1 || \
	ft_str_islong("-9223372036854775808") != 1)
		return (1);
	if (ft_str_islong("9223372036854775808") != 0 || \
	ft_str_islong("-9223372036854775809") != 0 || \
	ft_str_islong("92233720368547758070") != 0 || \
	ft_str_islong("-92233720368547758080") != 0 || \
	ft_str_islong("9223372036854775807a") != 0 || \
	ft_str_islong("-9223372036854775808a") != 0 || \
	ft_str_islong("9223372036854775807 ") != 0 || \
	ft_str_islong("-9223372036854775808 ") != 0 || \
	ft_str_islong("-+0") != 0 || ft_str_islong("+-0") != 0 || \
	ft_str_islong("0-") != 0 || ft_str_islong("0+") != 0)
		return (2);
	if (ft_str_islong("") != 0 || ft_str_islong("-") != 0)
		return (3);
	if (ft_str_islong(NULL) != false)
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
