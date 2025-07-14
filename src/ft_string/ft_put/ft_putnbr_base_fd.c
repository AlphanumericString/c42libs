/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 09:08:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/11 01:44:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "types/ft_string_types.h"
#include "ft_string.h"

#include <limits.h>
#include <unistd.h>

int	ft_putunbr_base_fd(size_t nb, const char *base, int fd)
{
	char	*s;
	int		ret;

	s = ft_stoa_base(nb, base);
	if (!s || fd < 0 || fd > MAX_FD)
		return (-1);
	ret = ft_putstr_fd(s, fd);
	return (ft_free(s), ret);
}

int	ft_putnbr_base_fd(ssize_t nb, const char *base, int fd)
{
	char	*s;
	int		ret;

	s = ft_sstoa_base(nb, base);
	if (!s || fd < 0 || fd > MAX_FD)
		return (-1);
	ret = ft_putstr_fd(s, fd);
	return (ft_free(s), ret);
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
