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

static const t_fnamed	*load_tests01(void)
{
	static t_fnamed	tb[] = {{"tok", ts_strtok}, {"split", ts_split},
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

// merge t_fnamed* from 2 blocks... dw, it's a bit ugly but it works
t_module	*str_tests(void)
{
	int						i;
	const t_fnamed			*funcs = load_tests01();
	const t_mod_constructor	sbm[] = {stris_tests, NULL};
	t_module				*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "str", "general str module.");
	while (funcs[i].name)
	{
		add_test_f(args, funcs[i].test, funcs[i].name);
		i++;
	}
	i = 0;
	while (sbm[i])
	{
		add_submodule(args, sbm[i++]());
	}
	return (args);
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
