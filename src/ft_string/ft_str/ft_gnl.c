/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:32:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 14:47:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "types/ft_string_types.h"
#include "ft_string.h"

#include <stddef.h>
#include <unistd.h>

static char	*extract_to(char **dst, char *from, char delim)
{
	int		pos;
	char	*ret;
	size_t	or_len;
	size_t	len;

	pos = ft_strclen(from, delim);
	or_len = 0;
	if (*dst)
		or_len = ft_strlen(*dst);
	len = or_len + pos + 1;
	ret = ft_calloc(sizeof(char), len + 1);
	if (!ret)
		return (ret);
	ft_strlcpy(ret, *dst, len);
	ft_strlcpy(ret + or_len, from, len - or_len + 1);
	pos += (ft_strchr(from, delim) != NULL);
	ft_memmove(from, from + pos, BUFFER_SIZE - pos);
	ft_bzero(from + BUFFER_SIZE - pos, pos);
	if (*dst)
		ft_free(*dst);
	return (*dst = ret, ret);
}

char	*ft_gnl(int fd)
{
	static char	s_buff[1024][BUFFER_SIZE] = {0};
	char		*ret;
	int			rep;

	ret = NULL;
	rep = BUFFER_SIZE;
	while (ft_strchr(s_buff[fd], '\n') == NULL && rep == BUFFER_SIZE)
	{
		if (s_buff[fd][0] && !extract_to(&ret, s_buff[fd], '\n'))
			return (NULL);
		rep = read(fd, s_buff[fd], BUFFER_SIZE);
		if (rep <= 0)
			return (ret);
		s_buff[fd][rep] = 0;
	}
	ret = extract_to(&ret, s_buff[fd], '\n');
	return (ret);
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
