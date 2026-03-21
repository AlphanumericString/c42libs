/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/06 19:40:06 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include <stdlib.h>
#include "tests/fixtures.h"
#include "tests/str__str_tests.h"

static char	local_mapi(unsigned int i, char c)
{
	if (i == 5)
		return ('5');
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

static int	mt_tsstrmapi(void)
{
	const int	fp = *talloc_get_failpoint();
	const char	*str = "Hello World!";
	char		*res;

	talloc_set_failpoint(0);
	res = ft_strmapi(str, &local_mapi);
	talloc_set_failpoint(fp);
	if (res != NULL)
		return (1);
	return (EXIT_SUCCESS);
}

int	ts_mapi(void)
{
	const char	*str = "Hello World!";
	char		*res;

	res = ft_strmapi(str, &local_mapi);
	if (ft_strcmp(res, "hELLO5wORLD!") != 0)
		return (ft_free(res), 1);
	ft_free(res);
	if (ft_strmapi(NULL, &local_mapi))
		return (2);
	if (ft_strmapi(str, NULL))
		return (3);
	return (mt_tsstrmapi());
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
