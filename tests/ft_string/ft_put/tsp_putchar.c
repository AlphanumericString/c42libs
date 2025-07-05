/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 16:01:41 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:19:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_char.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "tests/str__put_tests.h"

static int	test_bad_fd(char *file)
{
	const int	fd = -1;

	if (ft_putchar_fd('a', fd) != -1)
		return (11);
	if (ft_putchar_fd('\n', fd) != -1)
		return (12);
	ft_free(file);
	return (0);
}

int	tsp_putchar(void)
{
	const char	*file = "ft_putchar";
	char		buf[256];
	char		c;
	int			fd;
	int			ret;

	c = 0;
	fd = open_test_file((char **)&file);
	if (fd < 0)
		return (1);
	while ((unsigned char)c < 255)
		if (ft_putchar_fd(c++, fd) == -1)
			return (2);
	fd = (close(fd), open(file, O_RDONLY));
	if (fd < 0)
		return (3);
	ret = read(fd, buf, 256);
	if (ret != 255)
		return (4);
	buf[255] = 0;
	while (ret--)
		if (buf[ret] != --c)
			return (5);
	return (destroy_test_file(fd, (char *)file), test_bad_fd((char *)file));
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
