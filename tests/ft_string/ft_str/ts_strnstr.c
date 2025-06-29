/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:24:10 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stddef.h>
#include "tests/tests__all_modules_tests.h"

int	test_strnstr(void)
{
	char	*str;
	char	*res;

	str = "The cake is a lie !\0I'm hidden lol\n";
	if (ft_strnstr(str, "The cake is a lie !", 100) != str)
		return (1);
	if (ft_strnstr(str, "The cake is a lie !", 20) != str)
		return (2);
	res = ft_strnstr(str, "The cake is a lie !", 19);
	if (!res)
		return (3);
	if (ft_strnstr(str, "The cake is a lie !", 0))
		return (4);
	if (ft_strnstr(str, "hidden", 100))
		return (5);
	if (ft_strnstr(NULL, "hidden", 10) || \
ft_strnstr(str, NULL, 10))
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
