/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_append_n.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:05 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tstring.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_append_n(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;

	str = ft_string_from("Hello");
	talloc_set_failpoint(0);
	ft_string_append_n(str, " World", 5);
	talloc_set_failpoint(fp);
	if (ft_string_cmp(str, "Hello") != 0)
		return (ft_string_destroy(&str), 1);
	return (ft_string_destroy(&str), EXIT_SUCCESS);
}

int	test_string_append_n(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_append_n(str, " World", 5);
	if (ft_string_cmp(str, "Hello Worl") != 0)
		return (ft_string_destroy(&str), 1);
	if (str->length != 10)
		return (ft_string_destroy(&str), 2);
	if (str->capacity < 10)
		return (ft_string_destroy(&str), 3);
	ft_string_destroy(&str);
	str = ft_string_from("hi");
	ft_string_append_n(str, "i", 1);
	if (ft_string_cmp(str, "hii") != 0)
		return (ft_string_destroy(&str), 4);
	if (str->length != 3 || str->capacity < 3)
		return (ft_string_destroy(&str), 5);
	ft_string_destroy(&str);
	ft_string_append_n(NULL, "i", 1);
	ft_string_append_n(str, NULL, 1);
	return (mt_string_append_n());
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
