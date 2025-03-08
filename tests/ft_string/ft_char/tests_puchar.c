/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_puchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/01/28 11:43:04 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "tests/tests.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int	test_ft_putchar(void)
{
	const char	*file;
	char		buf[256];
	char		c;
	int			fd;
	int			ret;

	file = "ft_putchar";
	c = 0;
	fd = open_test_file((char **)&file);
	if (fd < 0)
		return (1);
	while ((unsigned char)c < 255)
		ft_putchar_fd(c++, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (2);
	ret = read(fd, buf, 256);
	if (ret != 255)
		return (3);
	buf[255] = 0;
	while (ret--)
		if (buf[ret] != --c)
			return (4);
	return (destroy_test_file(fd, (char *)file), free((char *)file), 0);
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
