/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_insert_sn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:45 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tstring.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"
#include <stdlib.h>

static int	mt_string_insert_sn(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from("World! < of magic > ");
	talloc_set_failpoint(0);
	ft_string_insert_s_n(str, str2, -1, 5);
	ft_string_insert_s_n(str, str2, -1, 20);
	talloc_set_failpoint(fp);
	if (ft_string_cmp(str, "Hello") != 0 || str->length != 5)
		return (ft_string_destroy(&str), ft_string_destroy(&str2), 1);
	ft_string_destroy(&str2);
	ft_string_destroy(&str);
	return (EXIT_SUCCESS);
}

int	test_string_insert_sn(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World!!!!");
	ft_string_insert_s_n(str, str2, 0, 5);
	if (ft_string_cmp(str, " WorlHello") != 0)
		return (ft_string_destroy(&str), ft_string_destroy(&str2), 1);
	if (str->length != 10 || str->capacity < 10)
		return (ft_string_destroy(&str), ft_string_destroy(&str2), 2);
	ft_string_insert_s_n(str, str2, 99, 1);
	if (ft_string_cmp(str, " WorlHello ") != 0)
		return (ft_string_destroy(&str), ft_string_destroy(&str2), 3);
	if (str->length != 11 || str->capacity < 11)
		return (ft_string_destroy(&str), ft_string_destroy(&str2), 4);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	return (mt_string_insert_sn());
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
