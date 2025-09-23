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

#include "ft_mem.h"
#include "tests/str__str_tests.h"
#include "tests/tests.h"
#include <stddef.h>

static const t_fnamed	*load_tests01(void)
{
	static t_fnamed	tb[] = {{"tok", ts_tok}, {"split", ts_split},
	{"splits", ts_splits}, {"nchr", ts_nchr}, {"chr", ts_chr}, {"dup", ts_dup},
	{"iteri", ts_iteri}, {"join", ts_join}, {"lcat", ts_lcat},
	{"lcpy", ts_lcpy}, {"len", ts_len}, {"mapi", ts_mapi}, {"tok_r", ts_tok_r},
	{"cmp", ts_cmp}, {"nrcmp", ts_nrcmp}, {"ncmp", ts_ncmp}, {"ndup", ts_ndup},
	{"str", ts_str}, {"nstr", ts_nstr}, {"rchr", ts_rchr},
	{"chr_null", ts_chr_null}, {"trim", ts_trim},
	{"trim_inplace", ts_trim_inplace}, {"substr", ts_substr}, {"rpl", ts_rpl},
	{"rplchr", ts_rplchr}, {"rplchrs", ts_rplchrs}, {"gnl", ts_gnl},
	{"nrplchr", ts_nrplchr}, {"nrplchrs", ts_nrplchrs},
	{"nclen", ts_nclen}, {"clen", ts_clen}, {"ncnb", ts_ncnb}, {"cnb", ts_cnb},
	{"cspn", ts_cspn}, {"end_with", ts_end_with},
	{"start_with", ts_start_with}, {"spn", ts_spn}, {"append_c", ts_append_c},
	{"rev", ts_rev}, {"upper", ts_upper}, {"nupper", ts_nupper},
	{"lower", ts_lower}, {"nlower", ts_nlower},
	{"justify_inplace", ts_justify_inplace},
	{"justify_nospace", ts_justify_nospace}, {"ncapitalize", ts_ncapitalize},
	{"capitalize", ts_capitalize}, {"nwcapitalize", ts_nwcapitalize},
	{"rmdup", ts_rmdup}, {"nrmdup", ts_nrmdup},
	{"rmdup_spaceall", ts_rmdup_spaceall}, {"rmdup_space", ts_rmdup_space},
	{"nrev", ts_nrev}, {"nrchr", ts_nrchr},
	{NULL, NULL}};

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
		add_submodule(args, sbm[i++]());
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
