/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_mem.h"
#include "tests/str__mem_tests.h"

// test 1: basic test - str aligned + search char in str
// test 2: str not aligned at start, tests both chr in str and not in str
// test 3: str not aligned at end, chr not in str
// test 4: no chr in str + bad args + null test
int	tm_memchr(void)
{
	char	str[32 + 1];
	size_t	i;

	i = 0;
	while (i < 32)
	{
		str[i] = '0' + (i % 10);
		if (str[i++] == '9')
			str[i - 1] = '8';
	}
	str[32 / 2] = '9';
	str[32] = 0;
	if (ft_memchr(str, '8', 32) != &str[8]
		|| ft_memchr(str, '7', 32) != &str[7]
		|| ft_memchr(str, '9', 32) != &str[32 / 2])
		return (1);
	if (ft_memchr(str + 3, '8', 32 - 3) != &str[8]
		|| ft_memchr(str + 3, '9', 32 - 3) != &str[32 / 2])
		return (2);
	if (ft_memchr(str, 'z', sizeof(size_t) + 2) || ft_memchr(str, 'z', 32)
		|| ft_memchr(str, '1', 0) || ft_memchr(str, 4242, 1)
		|| ft_memchr(NULL, 42, 1) || ft_memchr(str, -42, 1))
		return (3);
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
