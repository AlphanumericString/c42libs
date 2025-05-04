/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:32:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/14 00:32:21 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string_types.h"
#include "ft_string.h"

static int	ft_strchr_index(const char *from, char c)
{
	int	i;

	i = 0;
	if (!from)
		return (-1);
	while (from[i] && from[i] != c)
		i++;
	if (from[i] == c)
		return (i);
	return (-1);
}

static int	mvstr(char *str, int nb, char delim)
{
	size_t	off;

	if (ft_strchr_index(str, delim) != -1)
		nb++;
	off = 0;
	while (off != BUFFER_SIZE)
	{
		if (off + nb < BUFFER_SIZE && str[off + nb])
			str[off] = str[off + nb];
		else
			str[off] = 0;
		off++;
	}
	return (0);
}

static int	split_from(char **dst, char *from, int pos, char delim)
{
	char	*ret;
	size_t	or_len;
	size_t	len;
	size_t	i;

	or_len = 0;
	if (*dst)
		or_len += ft_strlen(*dst);
	len = or_len + pos + 1;
	ret = ft_malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (-1);
	ret[len] = 0;
	i = 0;
	while (i != len)
	{
		if (i < or_len)
			ret[i] = (*dst)[i];
		else
			ret[i] = from[i - or_len];
		i++;
	}
	if (*dst)
		ft_free(*dst);
	return (*dst = ret, (mvstr(from, pos, delim) || 0));
}

char	*ft_gnl(int fd)
{
	static char	loc_buff[1024][BUFFER_SIZE + 1] = {0};
	char		*ret;
	int			rep;

	ret = NULL;
	while (ft_strchr_index(loc_buff[fd], '\n') == -1)
	{
		if (loc_buff[fd][0] && \
		split_from(&ret, loc_buff[fd], ft_strlen(loc_buff[fd]), '\n'))
			return (NULL);
		rep = read(fd, loc_buff[fd], BUFFER_SIZE);
		if (rep <= 0)
			return (ret);
		loc_buff[fd][rep] = 0;
		if (rep != BUFFER_SIZE)
			break ;
	}
	rep = ft_strchr_index(loc_buff[fd], '\n');
	if (rep == -1)
		rep = ft_strlen(loc_buff[fd]);
	if (split_from(&ret, loc_buff[fd], rep, '\n'))
		return (NULL);
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
