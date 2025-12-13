/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/13 21:04:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

// last ft_memcpy is a test to check that we do nothing on
// dst if src and dst are the same otherwise it will segfault
int	tm_memcpy(void)
{
	char		str[10];
	const char	str3[] = "1234567\0009";

	ft_strlcpy(str, "123456789", 10);
	ft_memcpy(str, "abc", 3);
	if (ft_memcmp(str, "abc456789", 10) != 0)
		return (1);
	ft_memcpy(str, str3, 10);
	if (ft_memcmp(str, str3, 10) != 0)
		return (2);
	ft_memcpy(str, str, 999);
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
