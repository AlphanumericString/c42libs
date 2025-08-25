/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:10:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:09 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

static int	base_cases(void)
{
	const char	*str = "Hello World!";
	char		*res;
	size_t		size;
	int			ret;

	size = 15;
	res = ft_calloc(sizeof(char), size);
	ret = ft_strlcpy(res, str, size);
	if (ft_strcmp(res, "Hello World!") != 0 || ret != 12)
		return (1);
	ft_free(res);
	res = malloc(sizeof(char) * size);
	ret = ft_strlcpy(res, "This is zod!", size);
	if (ft_strcmp(res, "This is zod!") != 0 || ret != 12)
		return (2);
	return (ft_free(res), 0);
}

static int	error_cases(void)
{
	char	*res;
	size_t	size;
	int		ret;

	size = 15;
	res = ft_calloc(sizeof(char), size);
	ret = ft_strlcpy(res, "This is too large!", size);
	if (ft_strncmp(res, "This is too large!", size - 1) != 0 || ret != (int)
		ft_strlen("This is too large!"))
		return (3);
	ft_free(res);
	res = ft_calloc(sizeof(char), 1);
	ret = ft_strlcpy(res, "Hello World!", 0);
	if (ft_strcmp(res, "") != 0 || ret != 12)
		return (4);
	ret = ft_strlcpy(res, NULL, 42);
	if (ft_strcmp(res, "") != 0 || ret != 0)
		return (5);
	ret = ft_strlcpy(NULL, "Hello World!", 42);
	if (ret != 42)
		return (6);
	return (ft_free(res), 0);
}

int	ts_strlcpy(void)
{
	int	ret;

	ret = base_cases();
	if (ret != 0)
		return (ret);
	ret = error_cases();
	if (ret != 0)
		return (ret + 10);
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
