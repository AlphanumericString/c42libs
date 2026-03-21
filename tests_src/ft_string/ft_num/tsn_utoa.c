/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:17:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:28 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include <stdlib.h>
#include "tests/fixtures.h"
#include "tests/str__num_tests.h"

static int	mt_utoa(void)
{
	const int	fp = *talloc_get_failpoint();
	char		*res;

	talloc_set_failpoint(0);
	res = ft_utoa(42);
	talloc_set_failpoint(fp);
	if (res)
		return (ft_free(res), 32);
	return (EXIT_SUCCESS);
}

int	tsn_utoa(void)
{
	char				*res;
	size_t				i;
	const unsigned int	t_cases[] = {0, 123, 456, 7890, 12345};
	const char			*expected_results[] = {"0", "123", "456", "7890",
		"12345"};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_utoa(t_cases[i]);
		if (ft_strcmp(res, expected_results[i++]) != 0)
			return (ft_free(res), i + 1);
		ft_free(res);
	}
	return (mt_utoa());
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
