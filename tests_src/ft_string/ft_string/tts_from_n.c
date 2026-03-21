/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_from_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tstring.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_from_n(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;

	talloc_set_failpoint(0);
	str = ft_string_from_n("Hello there!", 5);
	talloc_set_failpoint(fp);
	if (str != NULL)
		return (ft_string_destroy(&str), 1);
	return (EXIT_SUCCESS);
}

int	test_string_from_n(void)
{
	t_string	*str;

	str = ft_string_from_n("Hello World", 5);
	if (ft_string_cmp(str, "Hello") != 0)
		return (ft_string_destroy(&str), 1);
	if (str->length != 5 || str->capacity < 5)
		return (ft_string_destroy(&str), 2);
	ft_string_destroy(&str);
	str = ft_string_from_n(NULL, 5);
	if (str->length != 0 || str->capacity < 1)
		return (ft_string_destroy(&str), 3);
	ft_string_destroy(&str);
	str = ft_string_from_n("Hello World", 0);
	if (str->length != 0 || str->capacity < 1)
		return (ft_string_destroy(&str), 4);
	return (ft_string_destroy(&str), mt_string_from_n());
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
