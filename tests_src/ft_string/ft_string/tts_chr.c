/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_chr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 15:57:50 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:37 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ft_tstring.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"

int	test_string_chr(void)
{
	t_string	*str;
	const char	c[] = "z!H@\0";
	char		*ptr_exp[sizeof(c) / sizeof(c[0])];
	size_t		i;

	str = ft_string_from("Hello world this is zod!");
	i = 0;
	while (i < sizeof(c) / sizeof(c[0]))
	{
		ptr_exp[i] = ft_strchr(str->str, c[i]);
		if (ft_string_chr(str, c[i]) != ptr_exp[i])
			return (ft_string_destroy(&str), i + 1);
		i++;
	}
	return (ft_string_destroy(&str), EXIT_SUCCESS);
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
