/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_putdbl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/16 18:08:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/16 18:08:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_math.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__put_tests.h"

#include <fcntl.h>
#include <stddef.h>
#include <unistd.h>
#include <math.h>

static int	bad_fd_tests(void)
{
	if (ft_putdbl_fd(42.0, 999999) != -1)
		return (1);
	if (ft_putdbl_fd(.02, 999999) != -1)
		return (2);
	if (ft_putdbl_fd(.0, 999999) != -1)
		return (3);
	if (ft_putdbl_fd(0, 999999) != -1)
		return (4);
	return (EXIT_SUCCESS);
}

static int	putdbl_to_file(const double *dbl, size_t nb, int fd)
{
	size_t	i;

	i = 0;
	while (i < nb)
	{
		if (ft_putdbl_fd(dbl[i], fd) == -1)
			return (i);
		if (++i < nb)
			ft_putstr_fd(", ", fd);
	}
	return (EXIT_SUCCESS);
}

int	tsp_putdbl_fd(void)
{
	const double	dbl[] = {INFINITY_D, -INFINITY_D, -NAN, 6.23, 42, -6.23,
		-42};
	const char		*expected = "inf, -inf, nan, 6.230000, 42.000000,"
		" -6.230000, -42.000000";
	const char		*file_name = "putendl.txt";
	int				fd;
	char			*res;

	fd = open_test_file((char **)&file_name);
	if (putdbl_to_file(dbl, sizeof(dbl) / sizeof(dbl[0]), fd))
		return (destroy_test_file(fd, file_name), 1);
	fd = (close(fd), open(file_name, O_RDONLY));
	res = ft_fd_to_buff(fd);
	destroy_test_file(fd, file_name);
	ft_free((t_any) file_name);
	if (ft_strcmp(expected, res) != 0)
		return (1);
	return (ft_free(res), bad_fd_tests());
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
