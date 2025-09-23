/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_putendl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:19:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__put_tests.h"

static int	error_cases(int fd, const char *const f_name)
{
	int		bread;
	char	buff[100];

	fd = open(f_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (ft_putendl_fd(NULL, fd) != -1)
		return (destroy_test_file(fd, f_name), 1);
	fd = (close(fd), open(f_name, O_RDONLY));
	bread = read(fd, buff, 100);
	if (bread != 0)
		return (destroy_test_file(fd, f_name), 2);
	destroy_test_file(fd, f_name);
	fd = -1;
	if (ft_putendl_fd("bad fd", fd) != -1)
		return (3);
	return (EXIT_SUCCESS);
}

int	tsp_putendl(void)
{
	const char	*str;
	int			fd;
	char		buff[100];
	int			bread;
	const char	file_name[] = TESTS_FPREFIX "putendl.txt";

	str = "Hello World!";
	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (ft_putendl_fd(str, fd) != (int)(ft_strlen(str) + 1))
		return (close(fd), 1);
	fd = (close(fd), open(file_name, O_RDONLY));
	bread = read(fd, buff, 100);
	if (bread < 0 || ft_strncmp(buff, str, ft_strlen(str)) != 0
		|| buff[ft_strlen(str)] != '\n')
		return (2);
	destroy_test_file(fd, file_name);
	return (error_cases(fd, file_name));
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
