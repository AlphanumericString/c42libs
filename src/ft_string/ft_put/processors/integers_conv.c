/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:40:28 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:08:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "internal/print.h"
#include "ft_string.h"
#include "ft_mem.h"

int	hex_processor(va_list args, int fd)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (ft_putunbr_base_fd(value, FT_HEXBASE, fd));
}

int	hex_upper_processor(va_list args, int fd)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (ft_putunbr_base_fd(value, FT_HEXBASE_CAP, fd));
}

int	octal_processor(va_list args, int fd)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (ft_putunbr_base_fd(value, FT_OCTBASE, fd));
}

int	ptr_processor(va_list args, int fd)
{
	char	res[64];
	void	*value;

	value = (void *)va_arg(args, unsigned long long);
	if (!value)
		return (ft_putstr_fd("(nil)", fd));
	ft_bzero(res, sizeof(res) / sizeof(res[0]));
	ft_strlcpy(res, "0x", sizeof(res) / sizeof(res[0]));
	ft_stopa_base((size_t)value, FT_HEXBASE, (&res[0]) + 2, 64 - 2);
	return (ft_putstr_fd(res, fd));
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
