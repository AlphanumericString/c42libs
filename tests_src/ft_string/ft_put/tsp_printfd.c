/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_printfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:53:34 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/06 18:53:34 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>

#include "ft_mem.h"
#include "ft_string.h"
#include "tests/str__put_tests.h"
#include "tests/fixtures.h"

static int	error_cases(int fd, const char *file)
{
	const int	malicious_fd = 14;
	int			ret;

	ret = EXIT_SUCCESS;
	if (ft_print_fd(-1, "tests") != -1
		|| ft_print_fd(fd, NULL) != -1
		|| ft_print_fd(99999, "tests") != -1
		|| ft_print_fd(malicious_fd, "toto %d", 42) != -1)
		ret = EXIT_FAILURE;
	destroy_test_file(fd, file);
	ft_free((t_any)file);
	return (ret);
}

static void	fill_the_file(int fd)
{
	const int	var = 42;
	const float	v_f_sml = .0032;
	const float	v_f_big = 3200.0;

	ft_print_fd(fd, "test_toto\n");
	ft_print_fd(fd, "test %c, %d, %u, %i\n", var, var, var, var);
	ft_print_fd(fd, "%c%y%X%%%x\n", (long)var, (long)var, (long)var, (long)var);
	ft_print_fd(fd, "%f, %f, %f, %f\n", 42.000042f, INFINITY, -INFINITY, NAN);
	ft_print_fd(fd, "%F, %F, %F, %F\n", 42.000042f, INFINITY, -INFINITY, NAN);
	ft_print_fd(fd, "%e, %e, %e, %e\n", 42.000042f, INFINITY, -INFINITY, NAN);
	ft_print_fd(fd, "%E, %E, %E, %E\n", 42.000042f, INFINITY, -INFINITY, NAN);
	errno = 0;
	ft_print_fd(fd, "%m\n");
	errno = 999;
	ft_print_fd(fd, "%m\n");
	errno = EFAULT;
	ft_print_fd(fd, "%m\n%o\t%s%s", 42, "hey\n", NULL);
	ft_print_fd(fd, "%p\t%p\n", (t_any)0xDEADBEEF, NULL);
	ft_print_fd(fd, "%e\t%E\n%e\t%E\n", v_f_sml, v_f_sml, -v_f_sml, -v_f_sml);
	ft_print_fd(fd, "%e\t%E\n%e\t%E\n", v_f_big, v_f_big, -v_f_big, -v_f_big);
	ft_print_fd(fd, "%");
}

int	tsp_printfd(void)
{
	const char	*file = "ft_print_fd";
	int			fd;
	char		*ret;
	const char	*expected = "test_toto\ntest *, 42, 42, 42\n*%y2A%2a\n"
		"42.000042, inf, -inf, nan\n42.000042, INF, -INF, NAN\n"
		"4.200004e+01, inf, -inf, nan\n4.200004E+01, INF, -INF, NAN\n"
		"Success\nUnknown error\nBad address\n"
		"52\they\n(null)0xdeadbeef\t(nil)\n"
		"3.200000e-03\t3.200000E-03\n-3.200000e-03\t-3.200000E-03\n"
		"3.200000e+03\t3.200000E+03\n-3.200000e+03\t-3.200000E+03\n"
		"%";

	fd = open_test_file((char **)&file);
	fill_the_file(fd);
	fd = (close(fd), open(file, O_RDONLY));
	ret = ft_fd_to_buff(fd);
	if (!ret || ft_strcmp(expected, ret) != 0)
		return (ft_free(ret), EXIT_FAILURE);
	return (ft_free(ret), error_cases(fd, file));
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
