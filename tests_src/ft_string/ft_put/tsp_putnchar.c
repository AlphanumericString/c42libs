/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_putnchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 22:37:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:19:54 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

#include "ft_mem.h"
#include "ft_char.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__put_tests.h"

static int	test_bad_fd(char *file)
{
	const int	fd = -1;

	if (ft_putnchar_fd('a', fd, 1) != -1)
		return (11);
	if (ft_putnchar_fd('\n', fd, 12) != -1)
		return (12);
	if (ft_putnchar_fd('a', fd, 0) != 0)
		return (13);
	ft_free(file);
	return (EXIT_SUCCESS);
}

int	tsp_putnchar(void)
{
	const char	*f = "ft_putchar";
	char		buf[256 * 3];
	char		c;
	int			fd;
	int			ret;

	c = 0;
	fd = open_test_file((char **)&f);
	if (fd < 0)
		return (1);
	while ((unsigned char)c < 255)
		if (ft_putnchar_fd(c++, fd, 3) == -1)
			return (destroy_test_file(fd, (char *)f), ft_free((char *)f), 2);
	fd = (close(fd), open(f, O_RDONLY));
	if (fd < 0)
		return (destroy_test_file(fd, (char *)f), ft_free((char *)f), 3);
	ret = read(fd, buf, 256 * 3);
	if (ret != 255 * 3)
		return (destroy_test_file(fd, (char *)f), ft_free((char *)f), 4);
	buf[255 * 3] = 0;
	while (ret--)
		if (buf[ret] != (char)(ret / 3))
			return (destroy_test_file(fd, (char *)f), ft_free((char *)f), 5);
	return (destroy_test_file(fd, (char *)f), test_bad_fd((char *)f));
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
