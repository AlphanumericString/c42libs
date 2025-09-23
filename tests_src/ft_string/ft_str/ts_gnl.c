/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ts_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:07:59 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <assert.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include "tests/str__str_tests.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "types/ft_string_types.h"

static int	write_lines(const char **lines, size_t n)
{
	size_t	i;
	int		fd;

	fd = open(TESTS_FPREFIX "gnl.txt", O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		write(fd, lines[i], ft_strlen(lines[i]));
		i++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}

static const char	**return_lines(size_t *n)
{
	static const char	*test_lines[] = {
		"Hello World!\n",
		"This is Zod!\n",
		"Zod shall henceforth be the new earth emperor. Prepare yourself "
		"earthilings to the terrible rule of zod the space warrior and self "
		"proclaimed emperor of the gallaxy. this is a really long line btw... "
		"i sure hope gnl will parse it............................\n",
		"Goodbye World!\n",
	};

	*n = sizeof(test_lines) / sizeof(test_lines[0]);
	return (test_lines);
}

static int	mt_gnl(int fd, const char **tl, int lc)
{
	int			ret;
	char		*line;
	const int	fp = *talloc_get_failpoint();

	(void)tl;
	(void)lc;
	ret = 0;
	fd = (close(fd), open(TESTS_FPREFIX "gnl.txt", O_RDONLY));
	talloc_set_failpoint(0);
	line = ft_gnl(fd);
	if (line != NULL)
		ret = 1;
	talloc_set_failpoint(fp);
	destroy_test_file(fd, TESTS_FPREFIX "gnl.txt");
	return (ret);
}

int	ts_gnl(void)
{
	int			fd;
	char		*line;
	size_t		i;
	size_t		lines_count;
	const char	**test_lines = return_lines(&lines_count);

	line = NULL;
	if (write_lines(test_lines, lines_count) < 0)
		return (1);
	fd = open(TESTS_FPREFIX "gnl.txt", O_RDONLY);
	i = 0;
	while (i < lines_count)
	{
		line = ft_gnl(fd);
		if (ft_strcmp(line, test_lines[i++]) != 0)
			return (i + 1);
		ft_free(line);
	}
	line = ft_gnl(fd);
	if (line)
		return (2);
	return (mt_gnl(fd, test_lines, lines_count));
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
