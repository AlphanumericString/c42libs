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
#include "unistd.h"
#include <stddef.h>

// FT_AT_INT = 1 << 4,	// todo: maybe add uint ?
// FT_AT_NBR = 3 << 4,
// FT_AT_LONG = 2 << 4,
// FT_AT_HEX = 4 << 4,
//
// FT_AT_OCT = 5 << 4,
// FT_AT_STR = 6 << 4,
//
// FT_AT_FNAME = 7 << 4,
// FT_AT_BOOL = 8 << 4,
// FT_AT_FLOAT = 9 << 4,
// FT_AT_DOUBLE = 10 << 4, // same checks - idk diff in range w flts
// FT_AT_ALPHANUM = 11 << 4,
// FT_AT_CUSTOM = 12 << 4, // keep last defined (used in code)

#define PREDICATE "Error: pname: "

#define E_S1 "Short option `-d' : Invalid argument (type check).\n"
#define E_S2 "Option `--int' : Missing argument.\n"
#define E_S3 "Option `--long' : Missing argument.\n"
#define E_S4 "Short option `-l' : Missing argument.\n"

// {"str", 's', set_str, FT_AT_STR, ""},
// {"file", 'f', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, ""},
// {"bool", 'b', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, ""},
// {"float", 'f', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, ""},
// {"double", '2', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, ""},
// {"alnum", 'a', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, ""},
// {"custom", 'c', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, ""},

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

static int	targp_err(int err_fd, const char **args_to_test,
				const char *err_str)
{
	t_usr		test;
	const char	*err;
	char		str[256];

	if (ft_parse_args(args_to_test, &test) == EXIT_SUCCESS)
		return (5);
	if (!err_str)
		return (0);
	err = ft_gnl(err_fd);
	ft_strlcpy(str, PREDICATE, sizeof(str));
	ft_strlcat(str, err_str, sizeof(str));
	if (!err || ft_strcmp(err, str) != 0)
		return (6);
	ft_free_clear((void *)&err);
	return (0);
}

int	targ_parse(void)
{
	t_usr		test;
	int			_ppe[2];
	const char	*args[] = {"pname", "-d", "42", "--int", "420",
		"--hex=0xDEAD", "--hex2", "-o", "0o31", "--", "toto", NULL};
	const char	*args_2[] = {"pname", "-d", "a42", "--int", "420",
		"--hex=0xDEAD", "--hex2", "-o", "0o31", "--", "toto", NULL};

	ft_bzero(&test, sizeof(t_usr));
	ft_set_opt_list(get_test_topt());
	if (ft_get_opt_list() != get_test_topt())
		return (1);
	(pipe(_ppe), dup2(_ppe[1], STDERR_FILENO));
	if (ft_parse_args(args, &test) != EXIT_SUCCESS)
		return (close(_ppe[0]), close(_ppe[1]), 2);
	if (test.nbr != 42 || test.i_nbr != 420 || test.hex != 0xDEAD
		|| test.hex2 != 0xDEADBEEF || test.oct != 25 || ft_get_nbparg() != 10)
		return ((close(_ppe[0]), close(_ppe[1]), 3));
	if (targp_err(_ppe[0], NULL, NULL) || targp_err(_ppe[0], args_2, E_S1)
		|| targp_err(_ppe[0], (const char *[]){"pname", "--int", NULL}, E_S2)
		|| targp_err(_ppe[0], (const char *[]){"pname", "--long", NULL}, E_S3)
		|| targp_err(_ppe[0], (const char *[]){"pname", "-l", NULL}, E_S4))
		return ((close(_ppe[0]), close(_ppe[1]), 5));
	return (dup2(STDERR_FILENO, _ppe[1]), close(_ppe[0]), close(_ppe[1]), 0);
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
