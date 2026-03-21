/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:39:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include <stdlib.h>
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static int	test_side_empty(void)
{
	const char	*str = "Hello World!";
	const char	*str_empty = "";
	char		*res;

	res = ft_strjoin(str, str_empty);
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str_empty)
		return (ft_free(res), 1);
	res = (ft_free(res), ft_strjoin(str, NULL));
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str)
		return (ft_free(res), 2);
	res = (ft_free(res), ft_strjoin(str_empty, str));
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str_empty)
		return (ft_free(res), 3);
	res = (ft_free(res), ft_strjoin(NULL, str));
	if (ft_strcmp(res, "Hello World!") != 0 || !res || res == str
		|| res == str_empty)
		return (ft_free(res), 4);
	return (ft_free(res), 0);
}

static int	mt_strjoin(void)
{
	const char	*str = "Hello ";
	const char	*str2 = "World!";
	const int	fp = *talloc_get_failpoint();
	char		*res;

	talloc_set_failpoint(0);
	res = ft_strjoin(str, str2);
	talloc_set_failpoint(fp);
	if (res)
		return (ft_free(res), 1);
	return (EXIT_SUCCESS);
}

int	ts_join(void)
{
	const char	*str = "Hello World!";
	const char	*str2 = "Hello World!";
	char		*res;
	int			ret;

	res = ft_strjoin(str, str2);
	if (ft_strcmp(res, "Hello World!Hello World!") != 0)
		return (ft_free(res), 1);
	ft_free(res);
	ret = test_side_empty();
	if (ret)
		return (10 + ret);
	ret = mt_strjoin();
	if (ret)
		return (ret + 20);
	return (EXIT_SUCCESS);
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
