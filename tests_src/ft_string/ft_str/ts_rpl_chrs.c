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

int	ts_rplchrs(void)
{
	const char	*src = "aabbccddeeff - ffeeddccbbaa";
	char		res[100];

	ft_strlcpy(res, src, sizeof(res));
	ft_strrpl_chrs(res, "abc", "xz");
	if (ft_strcmp(res, "xxzzxxddeeff - ffeeddxxzzxx") != 0)
		return (1);
	ft_strlcpy(res, "Hello World!", sizeof(res));
	ft_strrpl_chrs(res, "o", "\0");
	if (ft_strcmp(res, "Hell") != 0 || ft_strcmp(res + 5, " W") != 0
		|| ft_strcmp(res + 8, "rld!") != 0)
		return (2);
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
