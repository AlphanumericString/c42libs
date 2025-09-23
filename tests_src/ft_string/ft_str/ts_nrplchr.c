/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_nrplchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/18 11:28:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_nrplchr(void)
{
	const char	*src = "Hello World!";
	char		res[128];

	ft_strlcpy(res, src, sizeof(res));
	ft_strnrpl_chr(res, 6, 'o', 'a');
	if (ft_strcmp(res, "Hella World!") != 0)
		return (1);
	ft_strlcpy(res, src, sizeof(res));
	ft_strnrpl_chr(res, 3, 'o', 'a');
	ft_strnrpl_chr(res, 0, 'o', 'a');
	if (ft_strcmp(res, src) != 0)
		return (2);
	ft_strnrpl_chr(res, 9999, 'o', '\0');
	if (ft_strcmp(res, "Hell") != 0 || ft_strcmp(res + 5, " W") != 0
		|| ft_strcmp(res + 8, "rld!") != 0)
		return (3);
	ft_strlcpy(res, src, sizeof(res));
	ft_strnrpl_chr(res, -1, 'o', '\0');
	if (ft_strcmp(res, "Hell") != 0 || ft_strcmp(res + 5, " W") != 0
		|| ft_strcmp(res + 8, "rld!") != 0)
		return (4);
	return (ft_strnrpl_chr(NULL, -1, 'o', '\0'), EXIT_SUCCESS);
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
