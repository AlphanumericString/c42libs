/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_memmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:39 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

#include "tests/fixtures.h"

static int	base_cases(void)
{
	const char	*tb[3] = {"Hello", "World", "!"};
	char		**str2;

	str2 = (char **) ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]),
			(t_data_tr)ft_strdup);
	if (!str2 || ft_strcmp(str2[0], "Hello") || ft_strcmp(str2[1], "World")
		|| ft_strcmp(str2[2], "!"))
		return (ft_anfree((void **)str2, 3), 1);
	ft_anfree((void **)str2, 3);
	if (ft_memmap(NULL, 0, (t_data_tr)ft_strdup)
		|| ft_memmap((void *)tb, 0, (t_data_tr)ft_strdup)
		|| ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]), NULL))
		return (2);
	return (EXIT_SUCCESS);
}

static int	mt_cases(void)
{
	const char	*tb[3] = {"Hello", "World", "!"};
	char		**str2;
	const int	f_p = *talloc_get_failpoint();

	talloc_set_failpoint(0);
	str2 = (char **) ft_memmap((void *)tb, sizeof(tb) / sizeof(tb[0]),
			(t_data_tr)ft_strdup);
	talloc_set_failpoint(f_p);
	if (str2)
		return (1);
	return (EXIT_SUCCESS);
}

int	tm_memmap(void)
{
	int	ret;

	ret = base_cases();
	if (ret)
		return (ret);
	ret = mt_cases();
	if (ret)
		return (ret + 10);
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
