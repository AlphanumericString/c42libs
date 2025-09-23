/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 11:13:01 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 13:19:51 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__put_tests.h"

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <unistd.h>

static int	nb_to_file(const int *nbs, size_t size, const char *file_name,
				const char *base)
{
	int		fd;
	size_t	i;

	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	if (fd < 0)
		return (-1);
	i = 0;
	while (i < size)
	{
		ft_putnbr_base_fd(nbs[i], base, fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
	close(fd);
	return (EXIT_SUCCESS);
}

static int	file_cmp(const char *file_name, const char *expected)
{
	int		fd;
	char	buff[200];

	fd = open(file_name, O_RDONLY);
	ft_bzero(buff, sizeof(buff));
	read(fd, buff, sizeof(buff));
	if (ft_strncmp(buff, expected, sizeof(buff)))
		return (destroy_test_file(fd, file_name), EXIT_FAILURE);
	return (destroy_test_file(fd, file_name), EXIT_SUCCESS);
}

static int	test_positives(void)
{
	const int	cases[] = {0, 1, 9, 10, 99, 100, 999, 1000, 9999, 10000,
		INT_MAX};
	const char	*expected = "0\n1\n9\n10\n99\n100\n999\n1000\n9999\n10000\n"
		"2147483647\n";
	const char	*file_name = TESTS_FPREFIX "putnbr.txt";

	nb_to_file(cases, sizeof(cases) / sizeof(cases[0]), file_name, FT_DECBASE);
	return (file_cmp(file_name, expected));
}

static int	test_negatives(void)
{
	const int	nbs[] = {-1, -9, -10, -99, -100, -999, -1000, -9999, -10000,
		INT_MIN};
	const char	*exp = "-1\n-9\n-10\n-99\n-100\n-999\n-1000\n-9999\n-10000\n"
		"-2147483648\n";
	const char	*file_name = TESTS_FPREFIX "putnbr.txt";

	nb_to_file(nbs, sizeof(nbs) / sizeof(nbs[0]), file_name, FT_DECBASE);
	return (file_cmp(file_name, exp));
}

int	tsp_putnbr_base(void)
{
	const int	unopen_fd = 8;

	if (test_positives() != 0)
		return (1);
	if (test_negatives() != 0)
		return (2);
	if (ft_putnbr_base_fd(42, FT_DECBASE, -3) != -1
		|| ft_putnbr_base_fd(42, FT_DECBASE, 999) != -1
		|| ft_putnbr_base_fd(42, FT_DECBASE, unopen_fd) != -1)
		return (3);
	if (ft_putnbr_base_fd(42, NULL, 1) != -1
		|| ft_putnbr_base_fd(42, "", 1) != -1
		|| ft_putnbr_base_fd(42, "+abc", 1) != -1
		|| ft_putnbr_base_fd(42, "01234567890", 1) != -1)
		return (4);
	return (EXIT_SUCCESS);
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
