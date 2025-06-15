/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_perror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 08:04:30 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/29 10:32:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_errno.h"
#include "ft_string.h"

#include "tests/tests__all_modules_tests.h"
#include "tests/tests.h"

#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

static void	write_lines(void)
{
	errno = EPERM;
	ft_perror("toto");
	errno = EISCONN;
	ft_perror("titi");
	errno = ETIMEDOUT;
	ft_perror(NULL);
	errno = ELIBEXEC;
	ft_perror(NULL);
	errno = 9999;
	ft_perror(NULL);
}

int	test_perror(void)
{
	const char	*expected[] = {"toto: Operation not permitted\n", \
"titi: Transport endpoint is already connected\n", "Connection timed out\n", \
"Cannot exec a shared library directly\n", "Unkown error\n"};
	char		*rd_buff;
	char		*file;
	int			fd;
	size_t		i;

	file = "perror";
	fd = open_test_file(&file);
	dup2(fd, STDERR_FILENO);
	write_lines();
	fd = (close(fd), open(file, O_RDWR));
	i = 0;
	while (i < sizeof(expected) / sizeof(expected[0]))
	{
		rd_buff = ft_gnl(fd);
		if (ft_strcmp(rd_buff, expected[i++]))
			return (i);
		ft_free_clear((void **)&rd_buff);
	}
	destroy_test_file(fd, file);
	free(file);
	return (0);
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
