/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_trim.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:50:18 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:37:05 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

void	ft_string_trim(t_string *str)
{
	return (ft_string_trimstr(str, " \t\n"));
}

void	ft_string_trim_chr(t_string *str, char c)
{
	const char	to_trim[2] = {c, '\0'};

	return (ft_string_trimstr(str, (char *)to_trim));
}

// placing the null terminator at the end of the string
// because str->str is not reset after.
void	ft_string_trimstr(t_string *str, const char *to_trim)
{
	size_t	rpad;
	size_t	lpad;

	lpad = 0;
	if (!to_trim || !str || !str->str || str->length == 0)
		return ;
	while (ft_strchr(to_trim, str->str[lpad]) && lpad < str->length)
		lpad++;
	rpad = str->length - 1;
	while (ft_strchr(to_trim, str->str[rpad]) && rpad > 0)
		rpad--;
	if (rpad < lpad)
		return (ft_bzero(str->str, str->length),
			ft_bzero(&str->length, sizeof(str->length)));
	ft_memmove(str->str, str->str + lpad, rpad - lpad + 1);
	str->length = rpad - lpad + 1;
	str->str[str->length] = '\0';
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
