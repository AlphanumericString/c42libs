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
#include "ft_defs.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "internal/debug_defs.h"
#include "types/ft_args_types.h"
#include "tests/args_tests.h"
#include "unistd.h"
#include <stddef.h>

typedef struct s_usr {
	int				nbr;
	int				i_nbr;
	long			l_nbr;
	unsigned int	hex;
	unsigned int	hex2;
	unsigned int	oct;
	const char		*str;
	const char 		*fil;
	bool			boo;
	float			flo;
	double			dou;
	const char		*aln;
	void			*custom;
} t_usr;

static int	set_digit(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->nbr = ft_atoi(arg);
	return (0);
}

static int	set_int(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->i_nbr = ft_atoi(arg);
	return (0);
}

static int	set_long(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	my->l_nbr = ft_atol(arg);
	return (0);
}

static int	set_hex2(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	if (!arg)
		my->hex2 = 0xDEADBEEF;
	else
		my->hex2 = 0xCAFE;
	return (0);
}
static int	set_hex(void *user_struct, const char *arg)
{
	t_usr	*my;
	char	*tmp;

	my = user_struct;
	if (!arg)
		return (my->hex = 0xDEADBEEF, 0);
	if (arg[0] == '0' && arg[1] == 'x')
		tmp = ft_strdup(arg + 2);
	else
		tmp = ft_strdup(arg);
	ft_str_replace_chr(tmp, 'a', 'A'); // we really should add a function for that...
	ft_str_replace_chr(tmp, 'b', 'B');
	ft_str_replace_chr(tmp, 'c', 'C');
	ft_str_replace_chr(tmp, 'd', 'D');
	ft_str_replace_chr(tmp, 'e', 'E');
	ft_str_replace_chr(tmp, 'f', 'F');
	my->hex	= ft_atol_base(tmp, FT_HEXBASE_CAP);
	return (ft_free(tmp), 0);
}

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

static int	set_oct(void *user_struct, const char *arg)
{
	t_usr	*my;

	my = user_struct;
	if (arg && (arg[0] == '0' && (arg[1] == 'o' || arg[1] == 'O')))
			my->oct = ft_atoi_base(arg + 2, FT_OCTBASE);
	else if (arg)
			my->oct = ft_atoi_base(arg, FT_OCTBASE);
	else
		my->oct = 32;
	return (0);
}

int targ_parse(void)
{
	const t_opt	opts[] = {
	{"digit", 'd', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
	{"int", 'i', set_int, FT_AT_INT | FT_AS_NEXT_ARG, "sets an int in usr struct"},
	{"long", 'l', set_long, FT_AT_LONG | FT_AS_NEXT_ARG, "sets an long in usr struct"},
	{"hex", 'h', set_hex, FT_AH_MAYBE | FT_AT_HEX | FT_AS_EQSIGN, "sets hex in usr struct"},
	{"hex2", '2', set_hex2, FT_AH_MAYBE | FT_AT_HEX | FT_AS_EQSIGN, "sets hex2 in usr struct"},
	{"oct", 'o', set_oct, FT_AH_MAYBE | FT_AT_OCT | FT_AS_NEXT_ARG, "sets oct in usr struct"},
	// {"str", 's', set_str, FT_AT_STR, "sets str in usr struct"},
	// {"file", 'f', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
	// {"bool", 'b', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
	// {"float", 'f', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
	// {"double", '2', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
	// {"alnum", 'a', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
	// {"custom", 'c', set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "sets digit in usr struct"},
		{NULL, 0, NULL, 0, NULL}
	};
	t_usr		test;
	char		*err;
	int			ret;
	int			_pipe_err[2];
	const char	*args[] = {"progname", "-d", "42", "--int", "420",
		"--hex=0xDEAD", "--hex2", "-o", "0o31", "--", "toto", NULL};
	const char	*args_2[] = {"progname", "-d", "a42", "--int", "420",
		"--hex=0xDEAD", "--hex2", "-o", "0o31", "--", "toto", NULL};

	ft_bzero(&test, sizeof(t_usr));
	ft_set_opt_list(opts);
	if (ft_get_opt_list() != opts)
		return (1);
	pipe(_pipe_err);
	dup2(_pipe_err[1], STDERR_FILENO);
	ret = ft_parse_args(args, &test);
	if (ret != EXIT_SUCCESS)
		return (2);
	if (test.nbr != 42 || test.i_nbr != 420 || test.hex != 0xDEAD
		|| test.hex2 != 0xDEADBEEF || test.oct != 25)
		return (3);
	if (ft_get_nbparg() != 10)
		return (4);
	ret = ft_parse_args(args_2, &test);
	if (ret == EXIT_SUCCESS)
		return (5);
	err = ft_gnl(_pipe_err[0]);
	if (!err || !ft_strcmp(err, "Error: progname: Short option `-d' : Invalid argument (type check)"))
		return (6);
	ft_free_clear((void *)&err);
	ret = ft_parse_args((const char *[]){NULL}, &test);
	if (ret == EXIT_SUCCESS || ft_get_nbparg() != 0)
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 7));
	ret = ft_parse_args((const char *[]){"progname", "--int", NULL}, &test);
	if (ret != EXIT_FAILURE)
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 8));
	err = ft_gnl(_pipe_err[0]);
	if (!err || !ft_strcmp(err, "Error: progname: Long option `--int' : Missing argument"))
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 9));
	ft_free_clear((void *)&err);
	ret = ft_parse_args((const char *[]){"progname", "--long", NULL}, &test);
	if (ret != EXIT_FAILURE)
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 8));
	err = ft_gnl(_pipe_err[0]);
	if (!err || !ft_strcmp(err, "Error: progname: Long option `--long' : Missing argument"))
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 9));
	ft_free_clear((void *)&err);

	ret = ft_parse_args((const char *[]){"progname", "-l", NULL}, &test);
	if (ret != EXIT_FAILURE)
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 8));
	err = ft_gnl(_pipe_err[0]);
	if (!err || !ft_strcmp(err, "Error: progname: Short option `-l' : Missing argument"))
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 9));
	ret = ft_parse_args((const char *[]){"progname", "-o", NULL}, &test);
	if (ret != EXIT_FAILURE)
		return ((close(_pipe_err[0]), close(_pipe_err[1]), 8));


	dup2(STDERR_FILENO, _pipe_err[1]);
	ft_free(err);
	return (close(_pipe_err[0]), close(_pipe_err[1]), 0);
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
