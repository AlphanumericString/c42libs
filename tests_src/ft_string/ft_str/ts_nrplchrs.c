/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_rpl_chrs.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/16 20:44:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"

int	ts_nrplchrs(void)
{
	const char	*src = "aabbccddeeff - ffeeddccbbaa";
	char		res[128];

	ft_strlcpy(res, src, sizeof(res));
	ft_strnrpl_chrs(res, 14, "abc", "xz");
	if (ft_strcmp(res, "xxzzxxddeeff - ffeeddccbbaa") != 0)
		return (1);
	ft_strlcpy(res, src, sizeof(res));
	ft_strnrpl_chrs(res, 0, "abc", "xz");
	ft_strnrpl_chrs(res, 14, "abc", NULL);
	ft_strnrpl_chrs(res, 14, "", "xz");
	ft_strnrpl_chrs(res, 14, NULL, "xz");
	ft_strnrpl_chrs(NULL, 14, "abc", "xz");
	ft_strnrpl_chrs(NULL, -1, "def", "123");
	if (ft_strcmp(res, src) != 0)
		return (2);
	if (ft_strcmp(ft_strnrpl_chrs(res, -1, "abc", ""), "") != 0
		|| ft_strcmp(res, "") != 0
		|| ft_strcmp(res + 6, "ddeeff - ffeedd") != 0)
		return (3);
	ft_strlcpy(res, src, sizeof(res));
	if (ft_strcmp(ft_strnrpl_chrs(res, 1, "a", ""), "") != 0
		|| ft_strcmp(res + 1, src + 1) != 0)
		return (4);
	return (EXIT_SUCCESS);
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
