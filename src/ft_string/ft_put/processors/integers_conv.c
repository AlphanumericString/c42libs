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

#include "internal/print.h"
#include "ft_string.h"

int	hex_processor(va_list args, int fd)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (ft_putunbr_base_fd(value, "0123456789abcdef", fd));
}

int	hex_upper_processor(va_list args, int fd)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (ft_putunbr_base_fd(value, "0123456789ABCDEF", fd));
}

int	octal_processor(va_list args, int fd)
{
	unsigned int	value;

	value = va_arg(args, unsigned int);
	return (ft_putunbr_base_fd(value, "01234567", fd));
}

int	ptr_processor(va_list args, int fd)
{
	void	*value;
	int		predicate;

	value = (void *)va_arg(args, unsigned long long);
	if (!value)
		return (ft_putstr_fd("(nil)", fd));
	predicate = ft_putstr_fd("0x", fd);
	if (predicate <= 0)
		return (predicate);
	return (ft_putunbr_base_fd((size_t)value, \
"0123456789abcdef", fd) + predicate);
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
