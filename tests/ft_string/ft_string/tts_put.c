/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tts_put.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 12:45:09 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:08:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>

#include "ft_string.h"
#include "tests/tests.h"
#include "tests/tests__all_modules_tests.h"
#include "unistd.h"

static int	normal_cases(void)
{
	t_string	*str;
	const char	*src;
	char		*res;
	int			fd;
	const char	*file = TESTS_FPREFIX "test_string_put.txt";

	src = "Hello world this is zod!";
	str = ft_string_from(src);
	fd = open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		return (1);
	ft_string_put(str, fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (2);
	res = ft_fd_to_buff(fd);
	destroy_test_file(fd, file);
	if (ft_strcmp(src, res) != 0)
		return (3);
	return (ft_free(res), ft_string_destroy(&str), 0);
}

static int	error_case(void)
{
	t_string	*str;
	const int	fd = -1;

	str = ft_string_from("Hello");
	if (ft_string_put(str, fd) != -1)
		return (1);
	if (ft_string_put(NULL, STDOUT_FILENO) != -1)
		return (2);
	ft_free_clear((void **)&str->str);
	if (ft_string_put(str, STDOUT_FILENO) != -1)
		return (3);
	str->str = NULL;
	str->length = 0;
	if (ft_string_put(str, STDOUT_FILENO) != 0)
		return (4);
	return (ft_string_destroy(&str), 0);
}

int	test_string_put(void)
{
	int	ret;

	ret = normal_cases();
	if (ret)
		return (ret);
	ret = error_case();
	if (ret)
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
