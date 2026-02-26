/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:19:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:40:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "ft_arr.h"
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static int	mt_strtrim(void)
{
	const int	fp = *talloc_get_failpoint();
	const char	*str_ugly = "  Hallo mein muttie  ";
	char		*res;

	talloc_set_failpoint(0);
	res = ft_strtrim(str_ugly, " ");
	talloc_set_failpoint(fp);
	if (res)
		return (1);
	return (EXIT_SUCCESS);
}

int	ts_trim(void)
{
	const char	*str_ugly = "  Hello World!  ";
	const char	*str_ugly_front = "  Hello World!";
	const char	*str_ugly_back = "Hello World!    ";
	char		*res[7];

	res[0] = ft_strtrim(str_ugly_back, " ");
	res[1] = ft_strtrim(str_ugly, " ");
	res[2] = ft_strtrim(str_ugly_front, " ");
	res[3] = ft_strtrim(str_ugly, " !Wd");
	res[4] = ft_strtrim(str_ugly, NULL);
	res[5] = ft_strtrim("   ", " ");
	res[6] = ft_strtrim(NULL, " ");
	if (ft_strcmp(res[0], "Hello World!") || ft_strcmp(res[1], "Hello World!")
		|| ft_strcmp(res[2], "Hello World!")
		|| ft_strcmp(res[3], "Hello Worl") || ft_strcmp(res[4], str_ugly)
		|| ft_strcmp(res[5], "") || res[6])
		return (1);
	return (ft_aapply((t_arr)res, ft_free), mt_strtrim());
}

static void	exc_tests(char res[32][32], char *ret[32])
{
	const char	*str_ugly = "  Hello World!  ";
	const char	*str_ugly_front = "  Hello World!";
	const char	*str_ugly_back = "Hello World!    ";

	ft_strlcpy(res[0], str_ugly_back, 32);
	ft_strlcpy(res[1], str_ugly, 32);
	ft_strlcpy(res[2], str_ugly_front, 32);
	ft_strlcpy(res[3], str_ugly, 32);
	ft_strlcpy(res[4], str_ugly, 32);
	ft_strlcpy(res[5], str_ugly_front, 32);
	ft_strlcpy(res[6], str_ugly_back, 32);
	ret[0] = ft_strtrim_inplace(res[0], " ");
	ret[1] = ft_strtrim_inplace(res[1], " ");
	ret[2] = ft_strtrim_inplace(res[2], " ");
	ret[3] = ft_strtrim_inplace(res[3], " !Wd");
	ret[4] = ft_strtrim_inplace(res[4], NULL);
	ret[5] = ft_strtrim_inplace(NULL, " ");
	ret[6] = ft_strtrim_inplace(res[5], " Hello World");
	ret[7] = ft_strtrim_inplace(res[6], " ello World!");
}

int	ts_trim_inplace(void)
{
	const char	*str_ugly = "  Hello World!  ";
	const char	*target = "Hello World!";
	char		res[32][32];
	char		*ret[32];

	exc_tests(res, ret);
	if (ft_strcmp(res[0], target) || ft_strcmp(res[1], target)
		|| ft_strcmp(res[2], target) || ft_strcmp(res[3], "Hello Worl")
		|| ft_strcmp(res[4], str_ugly) || ret[5] != NULL
		|| ft_strcmp(ret[6], "!") || ft_strcmp(ret[7], "H"))
		return (1);
	ft_strtrim_inplace(ret[7], "babagaboush");
	ft_strtrim_inplace(ret[6], "babagaboush");
	ft_strtrim_inplace(ret[0], "babagaboush");
	ft_strtrim_inplace(ret[1], "");
	if (ft_strcmp(ret[6], "!") != 0 && ft_strcmp(ret[7], "H") != 0
		&& ft_strcmp(ret[0], target) != 0 && ft_strcmp(ret[1], target) != 0)
		return (2);
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
