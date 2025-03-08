/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fd_to_buff.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 19:52:02 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:30:40 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_string.h"
#include "ft_string_types.h"

char	*ft_fd_to_buff(int fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*file;
	char	*prev;
	ssize_t	ret;

	if (fd == -1)
		return (NULL);
	file = NULL;
	ret = read(fd, buff, BUFFER_SIZE);
	if (ret == -1)
		return (NULL);
	buff[ret] = '\0';
	file = ft_strdup(buff);
	while (ret == BUFFER_SIZE)
	{
		ret = read(fd, buff, BUFFER_SIZE);
		if (ret == -1)
			return (ft_free((void **)&file), NULL);
		buff[ret] = '\0';
		prev = file;
		file = ft_strjoin(file, buff);
		ft_free(prev);
	}
	return (file);
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
