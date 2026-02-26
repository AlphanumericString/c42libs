/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   targp_printopts.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 21:48:42 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/19 21:48:42 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_args.h"
#include "ft_mem.h"
#include "ft_string.h"
#include "internal/args_helper.h"
#include "tests/args_tests.h"
#include "tests/argp_tests.h"
#include "types/ft_args_types.h"

#include <unistd.h>

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
	{"long", 'l', set_long, FT_AT_LONG | FT_AS_NEXT_ARG, "hij"},
	{NULL, 0, set_digit, FT_AT_NBR | FT_AS_NEXT_ARG, "abc"},
	{NULL, 0, NULL, 0, NULL}
	};

	return ((t_opt *)opts);
}

#define DESC_SIZE	1024

// ppe - pipe_errout
int	targ_printopts(void)
{
	int			ppe[2];
	t_usr		test;
	const t_opt	*opts;
	char		err_desc[DESC_SIZE];
	const char	*desc = "\t--digit <number>\t-d <number>\n" \
"\t\tabc\n\t--int <int>\t-i <int>\n\t\tdfg\n" \
"\t--hex=[hexadecimal]\t-h=[hexadecimal]\n\t\tklm\n" \
"\t--hex2=<hexadecimal>\t-2=<hexadecimal>\n\t\tnop\n" \
"\t--oct [octal]\t-o [octal]\n\t\tqrs\n\t--oct2 [octal]\n\t\tqrs\n" \
"\t-3 [octal]\n\t\tqrs\n\t--oct4 [octal]\t-4 [octal]\n" \
"\t--long <long>\t-l <long>\n\t\thij\n";

	ft_bzero(&test, sizeof(t_usr));
	ft_set_opt_list(get_test_topt());
	opts = ft_get_opt_list();
	(pipe(ppe), dup2(ppe[1], STDERR_FILENO));
	ft_print_fopts(opts, STDERR_FILENO);
	ft_bzero(err_desc, DESC_SIZE);
	read(ppe[0], &err_desc, DESC_SIZE);
	if (ft_strcmp(err_desc, desc) != 0)
		return (dup2(STDERR_FILENO, ppe[1]), close(ppe[0]), close(ppe[1]), 1);
	return (dup2(STDERR_FILENO, ppe[1]), close(ppe[0]), close(ppe[1]), 0);
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
