/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 23:14:51 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 23:33:12 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <unistd.h>

// Thechnicaly the if around the write statement is not needed as the
//   previous call to putstr_fd already checks for successfull writes,
//   but as a global IO space I prefer to check for errors in the write
//   if someone / some program touched it. (probably unnecessary)
int	ft_putendl_fd(const char *s, int fd)
{
	int	ret;

	ret = ft_putstr_fd(s, fd);
	if (ret < 0)
		return (ret);
	if (write(fd, "\n", 1) < 0)
		return (-1);
	return (ret + 1);
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
