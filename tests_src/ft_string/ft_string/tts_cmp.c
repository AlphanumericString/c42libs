/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:34:36 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_tstring.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

int	test_string_cmp(void)
{
	t_string	*str;

	str = ft_string_from("Hello World");
	if (ft_string_cmp(str, "Hello World") != 0)
		return (1);
	if (ft_string_cmp(str, "Hello Warld!") != 'o' - 'a')
		return (2);
	if (ft_string_cmp(str, "Hello Wprld!") != 'o' - 'p')
		return (3);
	if (ft_string_cmp(str, "Hello World!") != '\0' - '!')
		return (4);
	if (ft_string_cmp(str, "Hell") != 'o' - '\0')
		return (5);
	ft_string_destroy(&str);
	return (EXIT_SUCCESS);
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
