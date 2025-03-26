/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_strmapi.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:36:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <stdlib.h>
#include "tests/tests__all_modules_tests.h"

static char	local_mapi(unsigned int i, char c)
{
	(void)i;
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	test_strmapi(void)
{
	char	*str;
	char	*res;

	str = "Hello World!";
	res = ft_strmapi(str, &local_mapi);
	if (ft_strcmp(res, "hELLO wORLD!") != 0)
		return (1);
	ft_free(res);
	res = ft_strmapi(NULL, &local_mapi);
	if (res)
		return (2);
	res = ft_strmapi(str, NULL);
	if (res)
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
