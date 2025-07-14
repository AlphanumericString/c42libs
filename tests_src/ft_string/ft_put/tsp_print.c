/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tsp_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 18:52:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/06 18:52:16 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__put_tests.h"
#include "tests/fixtures.h"

int	tsp_print(void)
{
	const char	*file = __func__;
	int			fd;
	const char	*exp = "test\n";
	char		*ret;

	fd = open_test_file((t_any) & file);
	dup2(fd, STDOUT_FILENO);
	ft_print("test\n");
	fd = (close(fd), open(file, O_RDONLY));
	ret = ft_fd_to_buff(fd);
	if (!ret || ft_strcmp(ret, exp))
		return (destroy_test_file(fd, file), ft_free((t_any)file),
			ft_free(ret), 1);
	return (destroy_test_file(fd, file), ft_free((t_any)file),
		ft_free(ret), 0);
}

int	tsp_print_err(void)
{
	const char	*file = __func__;
	int			fd;
	const char	*exp = "test\n";
	char		*ret;

	fd = open_test_file((t_any) & file);
	dup2(fd, STDERR_FILENO);
	ft_print_err("test\n");
	fd = (close(fd), open(file, O_RDONLY));
	ret = ft_fd_to_buff(fd);
	if (!ret || ft_strcmp(ret, exp))
		return (destroy_test_file(fd, file), ft_free((t_any)file),
			ft_free(ret), 1);
	return (destroy_test_file(fd, file), ft_free((t_any)file),
		ft_free(ret), 0);
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
