/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_substr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tstring.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_sub(void)
{
	t_string	*str;
	t_string	*sub;
	const int	fp = *talloc_get_failpoint();

	str = ft_string_from("Hello world");
	talloc_set_failpoint(0);
	sub = ft_string_substr(str, 0, -1);
	talloc_set_failpoint(fp);
	ft_string_destroy(&str);
	if (sub)
		return (ft_string_destroy(&sub), 1);
	return (EXIT_SUCCESS);
}

int	test_string_substr(void)
{
	t_string	*str;
	t_string	*sub;

	str = ft_string_from("Hello World");
	sub = ft_string_substr(str, 0, 5);
	if (!sub || ft_strcmp(sub->str, "Hello") != 0 || sub->length != 5
		|| sub->capacity < 5)
		return (ft_string_destroy(&str), ft_string_destroy(&sub), 1);
	ft_string_destroy(&sub);
	sub = ft_string_substr(str, 99, 100);
	if (sub)
		return (ft_string_destroy(&str), 2);
	sub = ft_string_substr(str, 0, -1);
	if (ft_string_cmpstr(str, sub) != 0)
		return (ft_string_destroy(&str), ft_string_destroy(&sub), 3);
	ft_string_destroy(&sub);
	sub = ft_string_substr(NULL, 0, 100);
	if (sub)
		return (ft_string_destroy(&str), 4);
	return (ft_string_destroy(&str), mt_string_sub());
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
