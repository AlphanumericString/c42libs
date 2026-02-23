/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targ_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 01:13:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:02:46 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "types/ft_args_types.h"
#include "tests/args_tests.h"
#include "ft_mem.h"

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>

#define F1 "Error: pname: Short option `-d' : Invalid argument (type check).\n"
#define F2 "Error: pname: Option `--int' : Missing argument.\n"
#define F3 "Error: pname: Option `--long' : Missing argument.\n"
#define F4 "Error: pname: Short option `-l' : Missing argument.\n"

// short hand for norming
#define E_S EXIT_SUCCESS

static t_opt	*get_test_topt(void)
{
	static t_opt	opts[] = {
	{"digit", 'd', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "abc"},
	{"int", 'i', set_int, FT_AT_INT | FT_AS_NEXT_ARG, "dfg"},
	{"long", 'l', set_long, FT_AT_LONG | FT_AS_NEXT_ARG, "hij"},
	{"hex", 'h', set_hex, FT_AH_MAYBE | FT_AT_HEX | FT_AS_EQSIGN, "klm"},
	{"hex2", '2', set_hex2, FT_AH_MAYBE | FT_AT_HEX | FT_AS_EQSIGN, "nop"},
	{"oct", 'o', set_oct, FT_AH_MAYBE | FT_AT_OCT | FT_AS_NEXT_ARG, "qrs"},
	{NULL, 0, NULL, 0, NULL}
	};

	return ((t_opt *)opts);
}

static int	do_bad_calls(void)
{
	t_usr		test;
	int			i;
	const char	*bad_type_args[] = {"pname", "-d", "a42", "--int", "420",
		"--hex=0xDEAD", "--hex2", "-o", "0o31", "--", "toto", NULL};
	const char	*bad_missing_args[][3] = { {"pname", "--int", NULL},
		{"pname", "--long", NULL}, {"pname", "-l", NULL},
	};

	i = 0;
	ft_bzero(&test, sizeof(t_usr));
	if (ft_parse_args(NULL, &test) == EXIT_SUCCESS)
		return (1);
	if (ft_parse_args(bad_type_args, &test) == EXIT_SUCCESS)
		return (1);
	while (i < 3) {
		if (ft_parse_args(bad_missing_args[i++], &test) == EXIT_SUCCESS)
			return (1);
	}
	return (EXIT_SUCCESS);
}

#define BUFF_SIZE 4096

static int file_cmp(int fd, const char *expected)
{
	char	buff[BUFF_SIZE + 1];
	ssize_t	i;
	size_t	j;

	i = BUFF_SIZE;
	j = 0;
	while (i == BUFF_SIZE)
	{
		i = read(fd, buff, BUFF_SIZE);
		if (i < 0)
			return (1);
		buff[i] = 0;
		if (ft_strncmp(buff, expected + (j++ * BUFF_SIZE), i) != 0)
			return (1);
	}
	return (EXIT_SUCCESS);
}

// TODO: tests: parse args until "general args"
// TODO: tests: parse args until w/o val until EOL

int	targ_parse(void)
{
	t_usr		test;
	int			_ppe[2];
	const char	*args[] = {"pname", "-d", "42", "--int", "420",
		"--hex=0xDEAD", "--hex2", "-o", "0o31", "--", "toto", NULL};

	(pipe(_ppe), dup2(_ppe[1], STDERR_FILENO));
	if (ft_parse_args(args, &test) == EXIT_SUCCESS)
		return (1);
	ft_bzero(&test, sizeof(t_usr));
	ft_set_opt_list(get_test_topt());
	if (ft_parse_args(args, NULL) == EXIT_SUCCESS)
		return (2);
	if (ft_parse_args(args, &test) != EXIT_SUCCESS)
		return (close(_ppe[0]), close(_ppe[1]), 3);
	if (test.nbr != 42 || test.i_nbr != 420 || test.hex != 0xDEAD
		|| test.hex2 != 0xDEADBEEF || test.oct != 25 || ft_get_nbparg() != 10)
		return ((close(_ppe[0]), close(_ppe[1]), 4));
	if (do_bad_calls() != E_S || file_cmp(_ppe[0], F1 F2 F3 F4) != E_S)
		return ((close(_ppe[0]), close(_ppe[1]), 5));
	return (dup2(STDERR_FILENO, _ppe[1]), close(_ppe[0]), close(_ppe[1]), E_S);
}

#undef F1
#undef F2
#undef F3
#undef F4

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
