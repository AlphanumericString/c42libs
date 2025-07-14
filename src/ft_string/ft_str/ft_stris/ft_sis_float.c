/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sis_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 15:45:19 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 03:30:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

#include "ft_string.h"
#include "ft_char.h"

// IEEE 754
// should:								!TODO
// parse string, enter mantissa + exp
// -> "3.14e+00" 3.14 - 00
// check the log10 size ... etc
//
// quite the annoyance
//
// here we just check for:
// '[ \t]*\d*(\.\d+)?([eE][+-]?\d*)?'
// 0 or more  spaces caharaters (\t ' ' ...)
// any of one '+' '-'
// 0 or more  digits
// 0 or more of the group	. followed by digits
//
//
static void	loc_skip_digits(bool *nums, size_t *i, const char *str)
{
	while (ft_isdigit(str[*i]))
		(*i)++;
	if (nums)
		*nums = true;
}

static bool	skip_start(const char *str, size_t *i)
{
	if (!str || !*str)
		return (false);
	while (ft_isspace(str[*i]))
		++(*i);
	if (str[*i] && ft_strchr("+-", str[*i]))
		(*i)++;
	return (true);
}

static bool	ft_str_isfloat_format(const char *str)
{
	size_t	i;
	bool	nums;

	i = 0;
	nums = false;
	if (skip_start(str, &i) == false)
		return (false);
	if (ft_isdigit(str[i]))
		loc_skip_digits(&nums, &i, str);
	if (str[i] == '.' && ft_isdigit(str[i + 1]))
	{
		i++;
		loc_skip_digits(&nums, &i, str);
	}
	if (str[i] && ft_strchr("eE", str[i]) && i > 0)
	{
		i++;
		if (str[i] && !ft_strchr("+-", str[i]) && !ft_isdigit(str[i]))
			return (false);
		i++;
		loc_skip_digits(NULL, &i, str);
	}
	return (nums && str[i] == '\0');
}

bool	ft_str_isfloat(const char *str)
{
	return (ft_str_isfloat_format(str));
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
