/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strndup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:23:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:19:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_strndup(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strndup(str, 5);
	if (ft_strcmp(res, "Hello") != 0)
		return (1);
	ft_free(res);
	res = ft_strndup(str, 0);
	if (ft_strcmp(res, "") != 0)
		return (2);
	ft_free(res);
	res = ft_strndup(str, 12);
	if (ft_strcmp(res, "Hello World!") != 0)
		return (3);
	ft_free(res);
	res = ft_strndup(str, 15);
	if (ft_strcmp(res, "Hello World!") != 0)
		return (4);
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
