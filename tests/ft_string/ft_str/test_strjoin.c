/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:29 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

static int	test_right_empty(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "Hello World!";
	str2 = "";
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str2)
		return (1);
	ft_free(res);
	str2 = NULL;
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str)
		return (2);
	ft_free(res);
	return (0);
}

static int	test_left_empty(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str2)
		return (1);
	ft_free(res);
	str = NULL;
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str2)
		return (2);
	ft_free(res);
	return (0);
}

int	test_strjoin(void)
{
	char	*str;
	char	*str2;
	char	*res;

	str = "Hello World!";
	str2 = "Hello World!";
	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!Hello World!") != 0)
		return (1);
	ft_free(res);
	if (test_right_empty() != 0)
		return (20 + test_right_empty());
	if (test_left_empty() != 0)
		return (30 + test_left_empty());
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
