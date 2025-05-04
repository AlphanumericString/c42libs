/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_str_isvalid.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 08:10:32 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/29 00:22:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests__all_modules_tests.h"

static int	string_validator(int c)
{
	return (c == 'a' || c == 'b' || c == 'c');
}

int	test_str_isvalid(void)
{
	if (ft_str_isvalid("abc", string_validator) != 1 || \
	ft_str_isvalid("abcabc", string_validator) != 1 || \
	ft_str_isvalid("aabbcc", string_validator) != 1)
		return (1);
	if (ft_str_isvalid("abd", string_validator) != 0 || ft_str_isvalid("bap", \
	string_validator) != 0 || ft_str_isvalid("ck", string_validator) != 0)
		return (2);
	if (ft_str_isvalid("", string_validator) != 0 || \
	ft_str_isvalid(NULL, string_validator) != false)
		return (3);
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
