/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_fd_to_buff.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 16:15:20 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 14:53:13 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_string.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"

static int	base_case(void)
{
	char	buff[100];
	char	*ret;
	int		fd;

	ft_bzero(buff, 100);
	ft_strlcat(buff, "Hello World\n\n\n\n\tv\vjkldqskjfsldfjsmldfkj\n", 100);
	fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return (1);
	write(fd, buff, ft_strlen(buff));
	close(fd);
	fd = open(TESTS_FPREFIX "test_fd_to_buff.txt", O_RDONLY | O_CREAT);
	if (fd < 0)
		return (2);
	ret = ft_fd_to_buff(fd);
	if (ft_strcmp(ret, buff) != 0)
		return (3);
	destroy_test_file(fd, TESTS_FPREFIX "test_fd_to_buff.txt");
	return (ft_free(ret), 0);
}

// semi uncheckable case on errors with the check for read in the loop
// without using either a wraper for read or a secondary thread to invalidate
// the fd while the function is reading
static int	error_case(void)
{
	char	*ret;
	int		bad_fd;
	int		malice_fd;

	bad_fd = -1;
	ret = ft_fd_to_buff(bad_fd);
	if (ret)
		return (1);
	malice_fd = 999;
	ret = ft_fd_to_buff(malice_fd);
	if (ret)
		return (3);
	return (0);
}

int	test_fd_to_buff(void)
{
	int	ret;

	ret = base_case();
	if (ret != 0)
		return (ret);
	ret = error_case();
	if (ret != 0)
		return (ret + 10);
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
