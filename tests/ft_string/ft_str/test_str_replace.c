/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:22:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_str_replace(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_str_replace(str, "World", "Zod");
	if (ft_strcmp(res, "Hello Zod!") != 0)
		return (1);
	ft_free(res);
	res = ft_str_replace(str, "World", "");
	if (ft_strcmp(res, "Hello !") != 0)
		return (2);
	ft_free(res);
	str = "Hello World!";
	res = ft_str_replace(str, "toto", "tutu");
	if (ft_strcmp(res, "Hello World!") != 0)
		return (3);
	ft_free(res);
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
