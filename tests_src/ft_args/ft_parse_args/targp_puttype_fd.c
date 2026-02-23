/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targp_puttype_fd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 23:21:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/19 23:21:52 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "tests/fixtures.h"
#include "tests/args_tests.h"

#include <unistd.h>
#include <fcntl.h>

#define S_ALP1	" [alphanumeric] <alphanumeric>"
#define S_ALP2	"=[alphanumeric]=<alphanumeric>\n"

#define S_USP	" [unspecified] <unspecified>=[unspecified]=<unspecified>\n"
#define S_INT	" [int] <int>=[int]=<int>\n"
#define S_LNG	" [long] <long>=[long]=<long>\n"
#define S_NMB	" [number] <number>=[number]=<number>\n"
#define S_HEX	" [hexadecimal] <hexadecimal>=[hexadecimal]=<hexadecimal>\n"
#define S_OCT	" [octal] <octal>=[octal]=<octal>\n"
#define S_STR	" [string] <string>=[string]=<string>\n"
#define S_FNM	" [file name] <file name>=[file name]=<file name>\n"
#define S_BOL	" [boolean] <boolean>=[boolean]=<boolean>\n"
#define S_FLT	" [float] <float>=[float]=<float>\n"
#define S_DBL	" [double] <double>=[double]=<double>\n"
// #define S_ALP	S_ALP1 S_ALP2
#define S_CST	" [custom] <custom>=[custom]=<custom>\n"
#define S_UKN	" [unknown] <unknown>=[unknown]=<unknown>\n"
#define S_BAD_AH	" <int> [int] ?int?\n"
#define S_BAD_AS	" [int]=[int]?[int]?[int]\n"

// put_type_fd(0 | FT_AS_NEXT_ARG | FT_AT_INT, fd); // AH_NO
// put_type_fd(1 | FT_AS_NEXT_ARG | FT_AT_INT, fd); // AH_YES
// put_type_fd(2 | FT_AS_NEXT_ARG | FT_AT_INT, fd); // AH_MAYBE
// put_type_fd(3 | FT_AS_NEXT_ARG | FT_AT_INT, fd); // reserved spot

static void	put_bad_arg_handl(int fd)
{
	put_type_fd(0 | FT_AS_NEXT_ARG | FT_AT_INT, fd);
	put_type_fd(1 | FT_AS_NEXT_ARG | FT_AT_INT, fd);
	put_type_fd(2 | FT_AS_NEXT_ARG | FT_AT_INT, fd);
	put_type_fd(3 | FT_AS_NEXT_ARG | FT_AT_INT, fd);
	ft_print_fd(fd, "\n");
}

static void	put_bad_arg_spacer(int fd)
{
	put_type_fd(FT_AH_MAYBE | 0 << 2 | FT_AT_INT, fd);
	put_type_fd(FT_AH_MAYBE | 1 << 2 | FT_AT_INT, fd);
	put_type_fd(FT_AH_MAYBE | 2 << 2 | FT_AT_INT, fd);
	put_type_fd(FT_AH_MAYBE | 3 << 2 | FT_AT_INT, fd);
	ft_print_fd(fd, "\n");
}

static void	put_arg_type(int fd)
{
	int			i;
	const int	step = 1 << 4;

	i = 0;
	while (i < 14)
	{
		put_type_fd(FT_AH_MAYBE | FT_AS_NEXT_ARG | (i * step), fd);
		put_type_fd(FT_AH_YES | FT_AS_NEXT_ARG | (i * step), fd);
		put_type_fd(FT_AH_NO | FT_AS_NEXT_ARG | (i * step), fd);
		put_type_fd(FT_AH_MAYBE | FT_AS_EQSIGN | (i * step), fd);
		put_type_fd(FT_AH_YES | FT_AS_EQSIGN | (i * step), fd);
		put_type_fd(FT_AH_NO | FT_AS_EQSIGN | (i * step), fd);
		ft_putstr_fd("\n", fd);
		i++;
	}
}

static int	file_cmp(const char *file_name)
{
	int			fd;
	char		buff[4096];
	const char	*expe = S_USP S_INT S_LNG S_NMB S_HEX S_OCT S_STR S_FNM \
S_BOL S_FLT S_DBL S_ALP1 S_ALP2 S_CST S_UKN S_BAD_AH S_BAD_AS;

	fd = open(file_name, O_RDONLY);
	ft_bzero(buff, sizeof(buff));
	read(fd, buff, sizeof(buff));
	if (ft_strcmp(buff, expe))
		return (destroy_test_file(fd, file_name), EXIT_FAILURE);
	return (destroy_test_file(fd, file_name), EXIT_SUCCESS);
}

int	targ_puttype_fd(void)
{
	char	*file;
	int		fd;
	int		tmp;

	file = "put_type_fd";
	fd = open_test_file(&file);
	put_arg_type(fd);
	put_bad_arg_handl(fd);
	put_bad_arg_spacer(fd);
	close(fd);
	tmp = file_cmp(file);
	ft_free(file);
	return (tmp);
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
