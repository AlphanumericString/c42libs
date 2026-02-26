/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targp_disploaded.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 11:31:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/21 11:31:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "tests/argp_tests.h"
#include "tests/args_tests.h"
#include "tests/fixtures.h"
#include "types/ft_args_types.h"

#include <unistd.h>
#include <fcntl.h>

static t_opt	*get_test_topt(void)
{
	static t_opt	opts[] = {
	{"digit", 'd', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "abc"},
	{"int", 'i', set_int, FT_AT_INT | FT_AS_NEXT_ARG, "dfg"},
	{"hex", 'h', set_hex, FT_AH_MAYBE | FT_AT_HEX | FT_AS_EQSIGN, "klm"},
	{"hex2", '2', set_hex2, FT_AH_YES | FT_AT_HEX | FT_AS_EQSIGN, "nop"},
	{"oct", 'o', set_oct, FT_AH_MAYBE | FT_AT_OCT | FT_AS_NEXT_ARG, "qrs"},
	{"oct2", 0, set_oct, FT_AH_MAYBE | FT_AT_OCT | FT_AS_NEXT_ARG, "qrs"},
	{NULL, '3', set_oct, FT_AH_MAYBE | FT_AT_OCT | FT_AS_NEXT_ARG, "qrs"},
	{"oct4", '4', set_oct, FT_AH_MAYBE | FT_AT_OCT | FT_AS_NEXT_ARG, NULL},
	{NULL, 0, set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "zzz"},
	{"long", 'l', set_long, FT_AT_LONG | FT_AS_NEXT_ARG, "hij"},
	{NULL, 0, NULL, 0, NULL}
	};

	return ((t_opt *)opts);
}

#define HA0 "a.out:\na.out:\n\t--digit <number>\t-d <number>\n\t\tabc\n"
#define HA1 "\t--int <int>\t-i <int>\n\t\tdfg\n\t--hex=[hexadecimal]"
#define HA2 "\t-h=[hexadecimal]\n\t\tklm\n\t--hex2=<hexadecimal>"
#define HA3 "\t-2=<hexadecimal>\n\t\tnop\n\t--oct [octal]"
#define HA4 "\t-o [octal]\n\t\tqrs\n\t--oct2 [octal]\n\t\tqrs\n\t"
#define HA5 "-3 [octal]\n\t\tqrs\n\t--oct4 [octal]\t-4 [octal]\n"
#define HA6 "\t--long <long>\t-l <long>\n\t\thij\n"

int	targ_disploaded(void)
{
	t_opt	*ls;
	char	*file;
	int		fd;
	char	buffer[1024];

	file = "disploaded";
	fd = open_test_file(&file);
	ls = get_test_topt();
	ft_set_progname("a.out");
	disp_loaded(fd);
	ft_set_opt_list(ls);
	disp_loaded(fd);
	fd = (close(fd), open(file, O_RDONLY));
	ft_bzero(buffer, 1024);
	read(fd, buffer, 1024);
	(close(fd), ft_free(file));
	if (ft_strcmp(buffer, HA0 HA1 HA2 HA3 HA4 HA5 HA6) != 0)
		return (1);
	return (EXIT_SUCCESS);
}

#undef HA0
#undef HA1
#undef HA2
#undef HA3
#undef HA4
#undef HA5
#undef HA6
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
