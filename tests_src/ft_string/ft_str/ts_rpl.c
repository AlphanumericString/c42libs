/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_rpl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/16 20:44:33 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static int	mt_ts_rpl(void)
{
	const char	*str = "Hello World!";
	char		*res;
	const int	fp = *talloc_get_failpoint();

	talloc_set_failpoint(0);
	res = ft_strrpl(str, "World", "Zod");
	talloc_set_failpoint(fp);
	if (res)
		return (1);
	return (EXIT_SUCCESS);
}

int	ts_rpl(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strrpl(str, "World", "Zod");
	if (ft_strcmp(res, "Hello Zod!") != 0)
		return (1);
	ft_free(res);
	res = ft_strrpl(str, "World", "");
	if (ft_strcmp(res, "Hello !") != 0)
		return (2);
	ft_free(res);
	str = "Hello World!";
	res = ft_strrpl(str, "toto", "tutu");
	if (ft_strcmp(res, "Hello World!") != 0)
		return (3);
	return (ft_free(res), mt_ts_rpl());
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
