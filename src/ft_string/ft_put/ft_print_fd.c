/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_fd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 02:37:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:11:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/print.h"
#include "ft_string.h"

#include <unistd.h>

// keep error as last please
static const t_processor	*table_holder(void)
{
	static const t_processor	processors[] = {
	{STRING_PROCESSOR, 's', string_processor},
	{CHAR_PROCESSOR, 'c', char_processor},
	{INT_PROCESSOR, 'd', int_processor},
	{INT_PROCESSOR, 'i', int_processor},
	{UINT_PROCESSOR, 'u', uint_processor},
	{HEX_PROCESSOR, 'x', hex_processor},
	{HEX_UPPER_PROCESSOR, 'X', hex_upper_processor},
	{OCTAL_PROCESSOR, 'o', octal_processor},
	{PTR_PROCESSOR, 'p', ptr_processor},
	{FLOAT_PROCESSOR, 'f', flt_processor},
	{FLOAT_UPPER_PROCESSOR, 'F', flt_upper_processor},
	{EXP_PROCESSOR, 'e', exp_processor},
	{EXP_UPPER_PROCESSOR, 'E', exp_upper_processor},
	{ERRNO_PROCESSOR, 'm', errno_processor},
	{META_PROCESSOR, '%', meta_processor},
	{ERROR, '\0', NULL}
	};

	return ((const t_processor *)processors);
}

// lines:
// if (!processors[i].func | (processors[i].type == ERROR))
// 	return (-1);
// should never be reached, but can be if a new symbol is added to
//	FT__PRINTF_META_CHAR and his processor isn't in the table...
//	This is a safety check
static int	lc_process_vaa(char c, va_list args, int fd)
{
	size_t				i;
	const t_processor	*processors = table_holder();
	const char			bad_spe[3] = {FT__PRINTF_META_CHAR, c, '\0'};

	i = 0;
	if (!c || !ft_strchr(FT__PRINTF_CONVERTION_SPECIFIERS, c))
		return (write(fd, bad_spe, 1 + (c != 0)));
	while (processors[i].link != c)
	{
		if (!processors[i].func | (processors[i].type == ERROR))
			return (-1);
		i++;
	}
	return (processors[i].func(args, fd));
}

int	ft_vaprint_fd(int fd, const char *str, va_list args)
{
	char			*pos;
	size_t			total;
	ssize_t			ret;

	if (!str || fd < 0 || fd > MAX_FD)
		return (-1);
	if (!ft_strchr(str, FT__PRINTF_META_CHAR))
		return (ft_putstr_fd(str, fd));
	total = 0;
	pos = ft_strchr(str, FT__PRINTF_META_CHAR);
	while (pos)
	{
		ret = write(fd, str, pos - str);
		if (ret < 0 || str[ret] != FT__PRINTF_META_CHAR)
			return (-1);
		total += ret;
		ret = lc_process_vaa(str[ret + 1], args, fd);
		if (ret <= 0)
			return (-1);
		total += ret;
		str = pos + 1 + (pos[1] != 0);
		pos = ft_strchr(str, FT__PRINTF_META_CHAR);
	}
	return (ft_putstr_fd(str, fd) + total);
}

int	ft_print_fd(int fd, const char *str, ...)
{
	va_list	args;
	int		result;

	va_start(args, str);
	result = ft_vaprint_fd(fd, str, args);
	va_end(args);
	return (result);
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
