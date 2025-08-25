/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_from_sn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_from_sn(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;
	t_string	*str_src;

	str_src = ft_string_from("Hello there!");
	talloc_set_failpoint(0);
	str = ft_string_from_s_n(str_src, 4);
	talloc_set_failpoint(fp);
	ft_string_destroy(&str_src);
	if (str != NULL)
		return (1);
	return (EXIT_SUCCESS);
}

int	test_string_from_sn(void)
{
	t_string	*str;
	t_string	*str_src;

	str_src = ft_string_from("Hello World");
	str = ft_string_from_s_n(str_src, 5);
	if (ft_string_cmp(str, "Hello") != 0)
		return (1);
	if (str->length != 5)
		return (2);
	if (str->capacity < 5)
		return (3);
	ft_string_destroy(&str);
	str = ft_string_from_s_n(NULL, 5);
	if (str->length != 0 || str->capacity < 1)
		return (4);
	ft_string_destroy(&str);
	str = ft_string_from_s_n(str_src, 0);
	if (str->length != 0 || str->capacity < 1)
		return (5);
	return (ft_string_destroy(&str), ft_string_destroy(&str_src),
		mt_string_from_sn());
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
