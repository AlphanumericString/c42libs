/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extentions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 23:40:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:07:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "internal/print.h"
#include "ft_string.h"
#include <errno.h>

#ifdef errno

int	errno_processor(va_list args, int fd)
{
	const char	*str;

	(void)args;
	str = ft_strerror(errno);
	if (!str)
		str = "Unknown error";
	return (ft_putstr_fd(str, fd));
}

#else

int	errno_processor(va_list args, int fd)
{
	(void)args;
	return (ft_putstr_fd("No errno support", fd));
}

#endif
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
