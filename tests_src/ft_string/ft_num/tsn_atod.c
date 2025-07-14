/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 16:08:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__num_tests.h"

int	tsn_atod(void)
{
	double			res;
	size_t			i;
	const float		marge = 0.00001;
	const double	t_cases[] = {
		1.13, 3.14, 0.0, 0.1, 0.0001, -0.2, -0.3, 0.3, 1200, 0,
		3.15, -3.15, 0.15
	};
	const char		*t_str[] = {
		"1.13", "3.14", "0.0", "0.1", "0.0001",
		"-0.2", "-.3", ".3", "1200", "0", "  +3.15",
		"  -3.15", "  .15"
	};

	i = 0;
	while (i < sizeof(t_cases) / sizeof(t_cases[0]))
	{
		res = ft_atod(t_str[i]);
		if (res < t_cases[i] - marge || res > t_cases[i] + marge)
			return (i + 1);
		i++;
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
