/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "tests/str__num_tests.h"
#include <limits.h>
#include <stdio.h>

static int	mt_cases(void)
{
	char		*res;
	const int	p_fp = *talloc_get_failpoint();

	res = ft_itoa(INT_MAX);
	if (res == NULL || ft_strcmp(res, "2147483647") != 0)
		return (2);
	ft_free(res);
	res = ft_itoa(INT_MIN);
	if (res == NULL || ft_strcmp(res, "-2147483648") != 0)
		return (printf("DBG: res '%s' exp '%s'\n", res, "-2147483648"), 3);
	ft_free(res);
	talloc_set_failpoint(0);
	if (ft_itoa(42) != NULL || ft_itoa(-42) != NULL)
		return (4);
	talloc_set_failpoint(p_fp);
	return (0);
}

int	tsn_itoa(void)
{
	char		*res;
	size_t		i;
	const int	t_cases[] = {0, 123, -456, 7890, -12345};
	const char	*expected_results[] = {"0", "123", "-456", "7890", "-12345"};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_itoa(t_cases[i]);
		if (ft_strcmp(res, expected_results[i++]) != 0)
			return (i);
		ft_free(res);
	}
	return (mt_cases());
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
