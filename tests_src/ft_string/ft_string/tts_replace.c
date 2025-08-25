/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:21:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_replace(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;
	const char	*src = "Hello there, how the Hell are you?";

	str = ft_string_from(src);
	talloc_set_failpoint(0);
	ft_string_replace(str, "Hell", "Heaven");
	talloc_set_failpoint(fp);
	if (ft_string_cmp(str, src) != 0 || str->length != ft_strlen(src))
		return (1);
	ft_string_destroy(&str);
	return (EXIT_SUCCESS);
}

int	test_string_replace(void)
{
	t_string	*str;
	t_string	str2;

	str = ft_string_from("Hello worlds!");
	ft_string_replace(str, "worlds", "Worlds");
	if (ft_string_cmp(str, "Hello Worlds!"))
		return (1);
	ft_string_append(str, " Worlds!");
	ft_string_replace(str, "Worlds", "earth");
	if (ft_string_cmp(str, "Hello earth! earth!"))
		return (2);
	ft_string_destroy(&str);
	ft_string_replace(NULL, "string1", "string2");
	ft_bzero(&str2, sizeof(str2));
	ft_string_replace(&str2, "string1", "string2");
	return (mt_string_replace());
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
