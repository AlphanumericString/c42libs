/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_insert_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:43 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

int	test_string_insert_c(void)
{
	t_string	*str;

	str = ft_string_from("Hello");
	ft_string_insert_c(str, ' ', 0);
	if (ft_string_cmp(str, " Hello") != 0)
		return (1);
	if (str->length != 6 || str->capacity < 6)
		return (2);
	ft_string_insert_c(str, '!', 99);
	if (ft_string_cmp(str, " Hello!") != 0)
		return (3);
	if (str->length != 7 || str->capacity < 7)
		return (4);
	ft_string_destroy(&str);
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
