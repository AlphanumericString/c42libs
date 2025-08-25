/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_set_n.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:57:59 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__t_str_test.h"

static int	mt_string_set_n(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;

	str = ft_string_new(6);
	talloc_set_failpoint(0);
	ft_string_set_n(str, "this is a long zod message", 20);
	if (str->capacity != 6 || str->length != 0)
		return (talloc_set_failpoint(fp), 1);
	ft_string_set_n(str, "this", 4);
	if (str->capacity != 6 || str->length != 4
		|| ft_string_cmp(str, "this") != 0)
		return (talloc_set_failpoint(fp), 2);
	talloc_set_failpoint(fp);
	ft_string_destroy(&str);
	return (EXIT_SUCCESS);
}

int	test_string_set_n(void)
{
	t_string	*str;
	const char	*src = "Hello world this is zod!";

	str = ft_string_new(0);
	ft_string_set_n(str, src, 5);
	if (ft_strcmp("Hello", ft_string_get(str)) != 0)
		return (1);
	ft_string_set_n(str, NULL, 9);
	ft_string_set_n(NULL, src, 9);
	ft_string_set_n(str, src, 9999999999);
	return (ft_string_destroy(&str), mt_string_set_n());
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
