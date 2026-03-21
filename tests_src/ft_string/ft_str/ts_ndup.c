/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:23:38 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:40:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_ndup(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strndup(str, 5);
	if (ft_strcmp(res, "Hello") != 0)
		return (ft_free(res), 1);
	ft_free(res);
	res = ft_strndup(str, 0);
	if (ft_strcmp(res, "") != 0)
		return (ft_free(res), 2);
	ft_free(res);
	res = ft_strndup(str, 12);
	if (ft_strcmp(res, "Hello World!") != 0)
		return (ft_free(res), 3);
	ft_free(res);
	res = ft_strndup(str, 15);
	if (ft_strcmp(res, "Hello World!") != 0)
		return (ft_free(res), 4);
	return (ft_free(res), EXIT_SUCCESS);
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
