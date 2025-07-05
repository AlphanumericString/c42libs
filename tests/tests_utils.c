/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 04:18:57 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/28 15:04:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/tests.h"
#include "ft_math.h"
#include "ft_char.h"

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

static void	print_test_name(int depth, const char *name, int mx_len)
{
	if (depth > VERBOSE)
		return ;
	while (depth--)
		ft_putstr_fd("\t", STDOUT_FILENO);
	ft_putnchar_fd(' ', STDOUT_FILENO, mx_len - ft_strlen(name));
	ft_putstr_fd(name, STDOUT_FILENO);
	ft_putchar_fd(' ', STDOUT_FILENO);
}

static int	run_t_test_fork(t_test test, int *collect, int mx_flen, int depth)
{
	int	ret;
	int	pid;

	pid = fork();
	if (pid == 0)
		exit(test.test());
	waitpid(pid, &ret, 0);
	if (depth > VERBOSE)
		return (*collect += ret, ret);
	print_test_name(depth, test.name, mx_flen);
	if (WIFEXITED(ret) && ret == 0)
		ft_putstr_fd("\033[32mOK \033[0m", STDOUT_FILENO);
	else
	{
		ft_putstr_fd("\033[31mKO\033[0m ret::", STDOUT_FILENO);
		if (WIFEXITED(ret))
			ft_putnbr_fd(WEXITSTATUS(ret), STDOUT_FILENO);
		else
			ft_putstr_fd("crash", STDOUT_FILENO);
	}
	ft_putstr_fd("\n", STDOUT_FILENO);
	*collect += ret;
	return (ret);
}

static int	run_t_test_nofork(t_test test, int *collect, int mx_flen, int depth)
{
	int	ret;

	if (depth > VERBOSE)
	{
		ret = test.test();
		return (*collect += ret, ret);
	}
	print_test_name(depth, test.name, mx_flen);
	ret = test.test();
	*collect += ret;
	if (ret != 0)
		ft_print_fd(STDOUT_FILENO, "\033[31mKO\033[0m ret::%d\n", ret);
	else
		ft_putstr_fd("\033[32mOK\033[0m\n", STDOUT_FILENO);
	return (ret);
}

int	run_test(const t_test *test, int *collect, int depth)
{
	const t_function_test_runner	f[2] = {run_t_test_nofork, run_t_test_fork};
	size_t							i;
	int								ret;
	int								sum;
	int								mx_flen;

	sum = 0;
	i = 0;
	mx_flen = 0;
	while (test[i].name)
		mx_flen = ft_max(mx_flen, ft_strlen(test[i++].name));
	i = 0;
	while (test[i].name)
	{
		ret = f[FORK_TESTS](test[i], &sum, mx_flen, depth);
		*collect += ret;
		sum += ret;
		i++;
	}
	return (sum);
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
