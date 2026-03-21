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

/*
 * sorrted list:

{"append_c", ts_append_c},
{"capitalize", ts_capitalize},
{"chr_null", ts_chr_null},
{"chr", ts_chr},
{"clen", ts_clen},
{"cmp", ts_cmp},
{"cnb", ts_cnb},
{"cspn", ts_cspn},
{"dup", ts_dup},
{"end_with", ts_end_with},
{"gnl_r", ts_gnl_r},
{"gnl", ts_gnl},
{"iteri", ts_iteri},
{"join", ts_join},
{"justify_inplace", ts_justify_inplace},
{"justify_nospace", ts_justify_nospace},
{"lcat", ts_lcat},
{"lcpy", ts_lcpy},
{"len", ts_len},
{"lower", ts_lower},
{"mapi", ts_mapi},
{"ncapitalize", ts_ncapitalize},
{"nchr", ts_nchr},
{"nclen", ts_nclen},
{"ncmp", ts_ncmp},
{"ncnb", ts_ncnb},
{"ndup", ts_ndup},
{"nlower", ts_nlower},
{"nrchr", ts_nrchr},
{"nrcmp", ts_nrcmp},
{"nrev", ts_nrev},
{"nrmdup", ts_nrmdup},
{"nrplchrs", ts_nrplchrs},
{"nrplchr", ts_nrplchr},
{"nstr", ts_nstr},
{"nupper", ts_nupper},
{"nwcapitalize", ts_nwcapitalize},
{"rchr", ts_rchr},
{"rev", ts_rev},
{"rmdup_spaceall", ts_rmdup_spaceall},
{"rmdup_space", ts_rmdup_space},
{"rmdup", ts_rmdup},
{"rplchrs", ts_rplchrs},
{"rplchr", ts_rplchr},
{"rpl", ts_rpl},
{"splits", ts_splits},
{"split", ts_split},
{"spn", ts_spn},
{"start_with", ts_start_with},
{"str", ts_str},
{"substr", ts_substr},
{"tok_r", ts_tok_r},
{"tok", ts_tok},
{"trim_inplace", ts_trim_inplace},
{"trim", ts_trim},
{"upper", ts_upper},

*/

static const t_fnamed	*load_tests01(void)
{
	static t_fnamed	tb[] = {{"append_c", ts_append_c},
	{"capitalize", ts_capitalize}, {"chr_null", ts_chr_null}, {"chr", ts_chr},
	{"clen", ts_clen}, {"cmp", ts_cmp}, {"cnb", ts_cnb}, {"cspn", ts_cspn},
	{"dup", ts_dup}, {"end_with", ts_end_with}, {"gnl_r", ts_gnl_r},
	{"gnl", ts_gnl}, {"iteri", ts_iteri}, {"join", ts_join},
	{"justify_inplace", ts_justify_inplace},
	{"justify_nospace", ts_justify_nospace}, {"lcat", ts_lcat},
	{"lcpy", ts_lcpy}, {"len", ts_len}, {"lower", ts_lower}, {"mapi", ts_mapi},
	{"ncapitalize", ts_ncapitalize}, {"nchr", ts_nchr}, {"nclen", ts_nclen},
	{"ncmp", ts_ncmp}, {"ncnb", ts_ncnb}, {"ndup", ts_ndup},
	{"nlower", ts_nlower}, {"nrchr", ts_nrchr}, {"nrcmp", ts_nrcmp},
	{"nrev", ts_nrev}, {"nrmdup", ts_nrmdup}, {"nrplchrs", ts_nrplchrs},
	{"nrplchr", ts_nrplchr}, {"nstr", ts_nstr}, {"nupper", ts_nupper},
	{"nwcapitalize", ts_nwcapitalize}, {"rchr", ts_rchr}, {"rev", ts_rev},
	{"rmdup_spaceall", ts_rmdup_spaceall}, {"rmdup_space", ts_rmdup_space},
	{"rmdup", ts_rmdup}, {"rplchrs", ts_rplchrs}, {"rplchr", ts_rplchr},
	{"rpl", ts_rpl}, {"splits", ts_splits}, {"split", ts_split},
	{"spn", ts_spn}, {"start_with", ts_start_with}, {"str", ts_str},
	{"substr", ts_substr}, {"tok_r", ts_tok_r}, {"tok", ts_tok},
	{"trim_inplace", ts_trim_inplace}, {"trim", ts_trim}, {"upper", ts_upper},
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
