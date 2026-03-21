/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tstring.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_resize(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;
	size_t		prev_cap;

	str = ft_string_from("Hello");
	prev_cap = ft_string_cap(str);
	talloc_set_failpoint(0);
	ft_string_resize(str, 32);
	talloc_set_failpoint(fp);
	if (ft_string_cmp(str, "Hello") != 0 || str->length != 5
		|| str->capacity != prev_cap)
		return (ft_string_destroy(&str), 1);
	ft_string_destroy(&str);
	return (EXIT_SUCCESS);
}

int	test_string_resize(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_resize(str, 42);
	if (ft_string_cmp(str, "Hello") != 0)
		return (ft_string_destroy(&str), 1);
	if (str->length != 5)
		return (ft_string_destroy(&str), 2);
	if (str->capacity < 42)
		return (ft_string_destroy(&str), 3);
	ft_string_resize(str, 4);
	if (str->capacity < 42)
		return (ft_string_destroy(&str), 4);
	ft_string_destroy(&str);
	ft_string_resize(NULL, -1);
	return (mt_string_resize());
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
