/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:11:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:39:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_lcat(void)
{
	char	*res;
	size_t	size;
	int		ret;

	size = 15;
	res = ft_malloc(sizeof(char) * size);
	ft_bzero(res, size);
	ret = ft_strlcat(res, "Hello", size);
	if (ft_strcmp(res, "Hello") != 0 || ret != 5)
		return (ft_free(res), 1);
	ret = ft_strlcat(res, " World!", size);
	if (ft_strcmp(res, "Hello World!") != 0 || ret != 12)
		return (ft_free(res), 2);
	ret = ft_strlcat(res, "This is zod!", size);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 24)
		return (ft_free(res), 3);
	ret = ft_strlcat(res, "This is zod!", 5);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 5 + 12)
		return (ft_free(res), 4);
	if (ft_strlcat(NULL, "test", 0) != 0 || ft_strlcat(NULL, "test", 5) != 0)
		return (ft_free(res), 5);
	ret = ft_strlcat(res, NULL, size);
	if (ft_strcmp(res, "Hello World!Th") != 0 || ret != 14)
		return (ft_free(res), 6);
	return (ft_free(res), 0);
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
