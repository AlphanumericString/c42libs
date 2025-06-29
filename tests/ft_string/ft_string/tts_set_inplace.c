/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_set_inplace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:56:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

int	test_string_set_inplace(void)
{
	t_string	*str;
	char		*src;
	const char	*res;

	src = ft_strdup("Hello world this is zod!");
	str = ft_string_new(0);
	ft_string_set_inplace(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (1);
	src = ft_strdup("Hello world this is zod!");
	ft_free(str->str);
	str->str = NULL;
	ft_string_set_inplace(str, src);
	res = ft_string_get(str);
	if (ft_strcmp(src, res) != 0)
		return (2);
	return (ft_string_destroy(&str), 0);
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
