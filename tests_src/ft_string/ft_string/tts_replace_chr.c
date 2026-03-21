/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_replace_chr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 06:21:48 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:50 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tstring.h"
#include "types/ft_string_types.h"
#include "tests/str__t_str_test.h"
#include <stdlib.h>

int	test_string_replace_chr(void)
{
	t_string	*str;
	t_string	str2;

	str = ft_string_from("Hello worlds!");
	ft_string_rpl_chr(str, 'o', 'O');
	ft_string_rpl_chr(str, 'z', 'Z');
	if (ft_string_cmp(str, "HellO wOrlds!"))
		return (ft_string_destroy(&str), 1);
	ft_string_destroy(&str);
	ft_string_rpl_chr(NULL, 'o', 'O');
	str2 = (t_string){0};
	ft_string_rpl_chr(&str2, 'o', '0');
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
