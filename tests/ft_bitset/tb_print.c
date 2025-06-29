/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tb_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 04:00:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/20 04:01:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fcntl.h"
#include "ft_bitset.h"
#include "ft_string.h"
#include "tests/bitset_tests.h"
#include "tests/tests.h"
#include "types/ft_bitset_types.h"
#include <unistd.h>

static void	loc_print_to_fd(int fd)
{
	t_bitset	*bs;

	bs = ft_bs_new(8);
	ft_bs_set_raw(bs, 0, 0b01000111);
	ft_bs_print(bs, fd);
	(ft_bs_free(&bs), ft_putendl_fd("", fd));
	bs = ft_bs_new(16);
	(ft_bs_set_raw(bs, 1, 0xFF), ft_bs_set_raw(bs, 0, 0x00));
	ft_bs_print(bs, fd);
	(ft_bs_print(NULL, -1), ft_bs_print(NULL, fd));
	ft_bs_free_inner(bs);
	ft_bs_print(bs, fd);
	ft_bs_free(&bs);
	ft_bs_print(bs, fd);
}

int	tb_print(void)
{
	const char	file_name[] = TESTS_FPREFIX "bs_print.txt";
	const char	*expecteds = ""
		"false, true, false, false, false, true, true, true\n\n"
		"true, true, true, true, true, true, true, true\n"
		"false, false, false, false, false, false, false, false\n";
	int			fd;
	char		buff[512];

	fd = open(file_name, O_RDWR | O_CREAT | O_TRUNC, 0666);
	loc_print_to_fd(fd);
	close(fd);
	fd = open(file_name, O_RDONLY);
	ft_bzero(buff, (sizeof buff / sizeof buff[0]));
	if (read(fd, buff, (sizeof buff / sizeof buff[0]) - 1) < 0
		|| ft_strcmp(buff, expecteds))
		return (destroy_test_file(fd, file_name), 1);
	return (destroy_test_file(fd, file_name), 0);
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
