/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsn_sstopa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 17:48:31 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/16 17:48:31 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__num_tests.h"
#include "ft_defs.h"
#include <stddef.h>

#define BUFF_SZ	200

static int	test_for(const ssize_t *nbrs, const char **expected,
				const char *base, size_t len)
{
	char	s[200];
	size_t	i;

	i = 0;
	while (i < len)
	{
		if (ft_sstopa_base(nbrs[i], base, (char *)s, BUFF_SZ) != true
			|| ft_strcmp(s, expected[i]) != 0)
			return (i + 1);
		i++;
	}
	return (0);
}

int	tsn_sstopa_base(void)
{
	const char		*b[] = {FT_DECBASE, FT_HEXBASE};
	const ssize_t	nb[] = {0, 12, 34, 42, 78, -12, -34, -42};
	const char		*e[][sizeof(nb) / sizeof(nb[0])] = {
	{"0", "12", "34", "42", "78", "-12", "-34", "-42"},
	{"0", "c", "22", "2a", "4e", "-c", "-22", "-2a"}};
	size_t			j;
	int				ret;

	j = 0;
	while (j < sizeof(b) / sizeof(b[0]))
	{
		ret = test_for(nb, e[j], b[j], sizeof(nb) / sizeof(nb[0]));
		if (ret)
			return (ret + (j + 1) * 100);
		j++;
	}
	if (ft_sstopa_base(42, FT_DECBASE, (void *)0xDEADBEEF, 1) != false
		|| ft_sstopa_base(42, FT_DECBASE, (void *)0XCAFE, 2) != false)
		return (42);
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
