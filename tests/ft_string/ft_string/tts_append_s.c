/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_append_s.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:56:56 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:20 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "types/ft_string_types.h"
#include "tests/tests__all_modules_tests.h"

int	test_string_append_s(void)
{
	t_string	*str;
	t_string	*str2;

	str = ft_string_from("Hello");
	str2 = ft_string_from(" World");
	ft_string_append_s(str, str2);
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (str->length != 11)
		return (2);
	if (str->capacity < 11)
		return (3);
	ft_string_destroy(&str);
	ft_string_destroy(&str2);
	str = ft_string_from("hi");
	str2 = ft_string_from("i");
	ft_string_append_s(str, str2);
	if (ft_string_cmp(str, "hii") != 0)
		return (4);
	if (str->length != 3 || str->capacity < 3)
		return (5);
	return (ft_string_destroy(&str), ft_string_destroy(&str2), 0);
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
