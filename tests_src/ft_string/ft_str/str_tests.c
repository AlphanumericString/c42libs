/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 13:39:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/15 02:43:02 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "tests/str__str_tests.h"
#include "tests/tests.h"
#include <stddef.h>

static const t_test	*load_tests01(void)
{
	static t_test	tb[] = {{"tok", ts_strtok}, {"split", ts_split},
	{"splits", ts_splits}, {"chr", ts_strchr}, {"dup", ts_strdup},
	{"iteri", ts_striteri}, {"join", ts_strjoin}, {"lcat", ts_strlcat},
	{"lcpy", ts_strlcpy}, {"len", ts_strlen}, {"mapi", ts_strmapi},
	{"cmp", ts_strcmp}, {"ncmp", ts_strncmp}, {"ndup", ts_strndup},
	{"nstr", ts_strnstr}, {"rchr", ts_strrchr}, {"trim", ts_strtrim},
	{"substr", ts_substr}, {"replace", ts_str_replace},
	{"replace_chr", ts_str_replace_chr},
	{"gnl", ts_gnl}, {"clen", ts_strclen},
	{"cnb", ts_strcnb}, {"cspn", ts_strcspn},
	{"end_with", ts_strend_with}, {"start_with", ts_strstart_with},
	{"spn", ts_strspn}, {"append_c", ts_strappend_c},
	{"rev", ts_strrev}, {NULL, NULL}};

	return (tb);
}

// merge t_test* from 2 blocks... dw, it's a bit ugly but it works
int	str_tests(int depth)
{
	int				collect;
	const t_module	sb[] = {
	{"str_is", "sis", stris_tests, 0},
	{NULL, NULL, NULL, 0}};
	const t_test	*tests = load_tests01();

	collect = 0;
	run_test(tests, &collect, depth);
	return (collect + run_module(sb[0], depth));
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
