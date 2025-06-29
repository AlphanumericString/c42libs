/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 12:25:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:18 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_substr(void)
{
	const char	*str = "Hello World!";
	char		*res[7];

	res[0] = ft_substr(str, 0, 5);
	res[1] = ft_substr(str, 6, 6);
	res[2] = ft_substr(str, 6, 100);
	res[3] = ft_substr(str, 6, 0);
	res[4] = ft_substr(str, 12, 0);
	res[5] = ft_substr(str, 12, 100);
	res[6] = ft_substr(NULL, 0, 5);
	if (ft_strcmp(res[0], "Hello") != 0 || ft_strcmp(res[1], "World!") != 0
		|| ft_strcmp(res[2], "World!") != 0)
		return (1);
	if (ft_strcmp(res[3], "") != 0 || ft_strcmp(res[4], "") != 0
		|| ft_strcmp(res[5], "") != 0 || res[6])
		return (2);
	ft_aapply((void **)res, ft_free);
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
