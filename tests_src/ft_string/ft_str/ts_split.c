/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static int	mt_ts_split(void)
{
	const char	*s1 = "  Hello world!  ";
	char		**res;
	int			fp;

	fp = *talloc_get_failpoint();
	talloc_set_failpoint(0);
	res = ft_split(s1, ' ');
	if (res != NULL)
		return (1 + 10);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	res = ft_split(s1, ' ');
	if (res != NULL)
		return (2 + 10);
	talloc_set_failpoint(fp);
	return (EXIT_SUCCESS);
}

int	ts_split(void)
{
	const char	*str = "  Hello World!  ";
	const char	*str2 = "Hello World!  ";
	char		**r[5];

	r[0] = ft_split(NULL, ' ');
	r[1] = ft_split(str, ' ');
	r[2] = ft_split(str2, ' ');
	r[3] = ft_split(str, 'z');
	r[4] = ft_split(str, 0);
	if (r[0][0] != NULL)
		return (1);
	if (ft_strcmp(r[1][0], "Hello") != 0 || ft_strcmp(r[1][1], "World!") != 0
		|| r[1][2]
		|| ft_strcmp(r[2][0], "Hello") != 0 || ft_strcmp(r[2][1], "World!") != 0
		|| r[2][2])
		return (2);
	if (ft_strcmp(r[3][0], str) != 0 || r[3][1] != NULL
		|| ft_strcmp(r[4][0], str) != 0 || r[4][1] != NULL)
		return (3);
	return (ft_afree((t_arr)r[0]), ft_afree((t_arr)r[1]),
		ft_afree((t_arr)r[2]), ft_afree((t_arr)r[3]), ft_afree((t_arr)r[4]),
		mt_ts_split());
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
