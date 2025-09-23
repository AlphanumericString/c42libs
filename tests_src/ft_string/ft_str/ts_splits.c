/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_splits.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:22:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static int	mt_tssplits(void)
{
	int			fp;
	const char	*s_test = "path/to/file:another/path:yet/another/path";
	char		**res;
	char		**res2;
	char		**res3;

	fp = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	res = ft_splits(s_test, " /:");
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	res2 = ft_splits(s_test, " /:");
	talloc_set_failpoint(*talloc_get_currentpoint() + 3);
	res3 = ft_splits(s_test, " /:");
	talloc_set_failpoint(fp);
	if (res != NULL)
		return (1 + 10);
	if (res2 != NULL)
		return (2 + 10);
	if (res3 != NULL)
		return (2 + 10);
	return (EXIT_SUCCESS);
}

int	ts_splits(void)
{
	const char	*s_test = "path/to/file:another/path:yet/another/path";
	const char	*s_test2 = "///path//to/my//file.type///";
	char		**res;

	res = ft_splits(s_test, " /:");
	if (ft_strcmp(res[0], "path") != 0 || ft_strcmp(res[1], "to") != 0
		|| ft_strcmp(res[2], "file") != 0 || ft_strcmp(res[3], "another") != 0
		|| ft_strcmp(res[4], "path") != 0 || ft_strcmp(res[5], "yet") != 0
		|| ft_strcmp(res[6], "another") != 0 || ft_strcmp(res[7], "path") != 0
		|| res[8])
		return (1);
	res = (ft_afree((t_arr)res), ft_splits(s_test, "z"));
	if (!res || ft_strcmp(res[0], s_test) != 0 || res[1] != NULL)
		return (2);
	res = (ft_afree((t_arr)res), ft_splits(NULL, "z"));
	if (!res || res[0] != NULL)
		return (3);
	res = (ft_afree((t_any)res), ft_splits(s_test2, "/"));
	if (ft_strcmp(res[0], "path") != 0 || ft_strcmp(res[1], "to") != 0
		|| ft_strcmp(res[2], "my") != 0 || ft_strcmp(res[3], "file.type") != 0)
		return (4);
	return (ft_afree((t_arr)res), mt_tssplits());
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
