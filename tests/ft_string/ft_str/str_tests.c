/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/16 16:43:27 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tests/str__str_tests.h"
#include "tests/tests.h"
#include <stddef.h>

static const t_test	*load_tests01(void)
{
	static t_test	tb[] = {{"putstr", test_putstr}, {"putendl", test_putendl},
	{"putnbr", test_putnbr}, {"itoa", test_itoa}, {"utoa", test_utoa}, \
	{"itoa_base", test_itoa_base}, {"atoi", test_atoi}, {"atoi_base", \
	test_atoi_base}, {"tok", test_strtok}, {"split", test_split},
	{"splits", tests_splits}, {"chr", test_strchr}, {"dup", test_strdup}, \
	{"iteri", test_striteri}, {"join", test_strjoin}, {"lcat", test_strlcat}, \
	{"lcpy", test_strlcpy}, {"len", test_strlen}, {"mapi", test_strmapi}, \
	{"cmp", test_strcmp}, {"ncmp", test_strncmp}, {"ndup", test_strndup}, \
	{"nstr", test_strnstr}, {"rchr", test_strrchr}, {"trim", test_strtrim}, \
	{"substr", test_substr}, {"replace", test_str_replace}, \
	{"replace_chr", test_str_replace_chr}, {"shift_args", test_shift_args}, \
	{"gnl", test_gnl}, {"atof", test_atof}, {"isalpha", test_str_isalpha}, \
	{"isbool", test_str_isbool}, {"alnum", test_str_isalnum}, \
	{"isdigit", test_str_isdigit}, {"isdouble", test_str_isdouble}, \
	{"ishex", test_str_ishex}, {"islong", test_str_islong}, \
	{"isnum", test_str_isnum}, {"isoct", test_str_isoct}, \
	{"isint", test_str_isint}, {"isfloat", test_str_isfloat}, \
	{"isvalid", test_str_isvalid}, {"clen", test_strclen}, \
	{"cnb", test_strcnb}, {"cspn", test_strcspn}, \
	{"end_with", test_strend_with}, {"start_with", test_strstart_with}, \
	{"spn", test_strspn}, {"append_c", test_strappend_c},
	{"rev", test_strrev}, {"perror", test_perror}, {NULL, NULL}};

	return (tb);
}

int	str_tests(void)
{
	int				collect;
	const t_test	*tests = load_tests01();

	collect = 0;
	run_test(tests, &collect);
	return (collect);
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
