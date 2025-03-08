/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_memcmp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 12:22:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	test_memcmp(void)
{
	const char	str[] = "1234567\0009";
	const char	str2[] = "1234567\0009";
	const char	str3[] = "1234567\000a";
	const char	str4[] = "1234567\0009";

	if (ft_memcmp(str, str2, 10) != 0)
		return (1);
	if (ft_memcmp(str, str3, 10) >= 0)
		return (2);
	if (ft_memcmp(str3, str, 10) <= 0)
		return (3);
	if (ft_memcmp(str, str2, 0) != 0)
		return (4);
	if (ft_memcmp(str, str4, 10) != 0)
		return (5);
	if (ft_memcmp(str, str, 999) != 0)
		return (6);
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
