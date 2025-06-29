/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:19:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_strtrim(void)
{
	const char	*str_ugly = "  Hello World!  ";
	const char	*str_ugly_front = "  Hello World!";
	char		*res[7];

	res[0] = ft_strtrim(ft_strchr(str_ugly, 'H'), " ");
	res[1] = ft_strtrim(str_ugly, " ");
	res[2] = ft_strtrim(str_ugly_front, " ");
	res[3] = ft_strtrim(str_ugly, " !Wd");
	res[4] = ft_strtrim(str_ugly, NULL);
	res[5] = ft_strtrim("   ", " ");
	res[6] = ft_strtrim(NULL, " ");
	if (ft_strcmp(res[0], "Hello World!") != 0 || ft_strcmp(res[1], \
"Hello World!") != 0 || ft_strcmp(res[2], "Hello World!") != 0 || \
ft_strcmp(res[3], "Hello Worl") != 0 || ft_strcmp(res[4], str_ugly) \
!= 0 || ft_strcmp(res[5], "") != 0 || res[6])
		return (1);
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
