/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:25:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:40:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static int	mt_substr(void)
{
	const int	fp = *talloc_get_failpoint();
	const char	*s1 = "test toto";

	talloc_set_failpoint(0);
	s1 = ft_substr(s1, 0, 99);
	talloc_set_failpoint(fp);
	if (s1 != NULL)
		return (1);
	return (EXIT_SUCCESS);
}

int	ts_substr(void)
{
	const char	*str = "Hello World!";
	char		*res[7];

	res[0] = ft_substr(str, 0, 5);
	res[1] = ft_substr(str, 6, 6);
	res[2] = ft_substr(str, 6, 100);
	res[3] = ft_substr(str, 6, 0);
	res[4] = ft_substr(str, 12, 0);
	res[5] = ft_substr(str, 12, 100);
	res[6] = ft_substr(NULL, 0, 5);
	if (ft_strcmp(res[0], "Hello") != 0 || ft_strcmp(res[1], "World!") != 0
		|| ft_strcmp(res[2], "World!") != 0)
		return (ft_aapply((t_any)res, ft_free), 1);
	if (ft_strcmp(res[3], "") != 0 || ft_strcmp(res[4], "") != 0
		|| ft_strcmp(res[5], "") != 0 || res[6])
		return (ft_aapply((t_any)res, ft_free), 2);
	return (ft_aapply((t_arr)res, ft_free), mt_substr());
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
