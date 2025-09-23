/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_to_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:56 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "ft_tstring.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

static int	mt_string_to_str(void)
{
	const int	fp = *talloc_get_failpoint();
	t_string	*str;
	char		*cstr;

	str = ft_string_from("hiii");
	talloc_set_failpoint(0);
	cstr = ft_string_to_str(str);
	talloc_set_failpoint(fp);
	ft_string_destroy(&str);
	if (cstr)
		return (1);
	return (EXIT_SUCCESS);
}

int	test_string_to_str(void)
{
	t_string	*str;
	char		*cstr;

	str = ft_string_from("Hello World");
	cstr = ft_string_to_str(str);
	if (ft_strcmp(cstr, "Hello World") != 0)
		return (1);
	ft_string_destroy(&str);
	ft_free(cstr);
	return (mt_string_to_str());
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
