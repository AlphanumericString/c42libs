/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_print_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/15 14:30:59 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 15:42:24 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/args_helper.h"
#include "ft_string.h"

static const char	*at_type_toa(enum e_arg_types type)
{
	static const char	*types[] = {
	[FT_AT_UNSPECIFIED] = "unspecified",
	[FT_AT_INT] = "int",
	[FT_AT_LONG] = "long",
	[FT_AT_NBR] = "number",
	[FT_AT_HEX] = "hexadecimal",
	[FT_AT_OCT] = "octal",
	[FT_AT_STR] = "string",
	[FT_AT_FNAME] = "file name",
	[FT_AT_BOOL] = "boolean",
	[FT_AT_FLOAT] = "float",
	[FT_AT_DOUBLE] = "double",
	[FT_AT_ALPHANUM] = "alphanumeric",
	[FT_AT_CUSTOM] = "custom",
	};

	if (type < FT_AT_UNSPECIFIED || type > FT_AT_CUSTOM)
		return ("unknown");
	return (types[type]);
}

void	put_type_fd(uint16_t type, int fd)
{
	const char	*at_type;
	char		sep;
	char		braces[3];

	if (!type)
		return ;
	at_type = at_type_toa(type & FT_AT_MASK);
	if ((type & FT_AS_MASK) == FT_AS_NEXT_ARG)
		sep = ' ';
	else if ((type & FT_AS_MASK) == FT_AS_EQSIGN)
		sep = '=';
	else
		sep = '?';
	if ((type & FT_AH_MASK) == FT_AH_YES)
		ft_strlcpy(braces, "<>", 3);
	else if ((type & FT_AH_MASK) == FT_AH_MAYBE)
		ft_strlcpy(braces, "[]", 3);
	else
		ft_strlcpy(braces, "??", 3);
	ft_print_fd(fd, "%c%c%s%c", sep, braces[0], at_type, braces[1]);
	return ;
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
