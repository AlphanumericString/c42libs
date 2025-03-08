/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:17:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>

int	test_utoa(void)
{
	char				*res;
	size_t				i;
	const unsigned int	t_cases[] = {0, 123, 456, 7890, 12345};
	const char			*expected_results[] = \
	{"0", "123", "456", "7890", "12345"};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_utoa(t_cases[i]);
		if (ft_strcmp(res, expected_results[i++]) != 0)
			return (i);
		ft_free(res);
	}
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
