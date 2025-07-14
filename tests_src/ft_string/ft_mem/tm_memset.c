/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:21:24 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:19 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__mem_tests.h"

/*
	// ignore warning for memset args
	#pragma clang diagnostic push
	#pragma clang diagnostic ignored "-Wmemset-transposed-args"
*/
int	tm_memset(void)
{
	char	str[10];
	char	str2[10];

	ft_strlcpy(str, "123456789", 10);
	ft_strlcpy(str2, "123456789", 10);
	ft_memset(str, 'a', 10);
	if (ft_memcmp(str, "aaaaaaaaaa", 10) != 0)
		return (1);
	ft_memset(str, 'b', 0);
	if (ft_memcmp(str, "aaaaaaaaaa", 10) != 0)
		return (2);
	ft_memset(str, 'c', 5);
	if (ft_memcmp(str, "cccccaaaaa", 10) != 0)
		return (3);
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
