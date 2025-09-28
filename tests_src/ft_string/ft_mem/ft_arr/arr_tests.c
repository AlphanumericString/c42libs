/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arr_tests.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 12:49:35 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/05 12:49:35 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/str__mem_tests.h"
#include "tests/tests.h"

static const t_fnamed	*tca_tests(void)
{
	static const t_fnamed	tests[] = {
	{"aapply", tca_aapply}, {"anapply", tca_anapply},
	{"acat", tca_acat}, {"alcat", tca_alcat},
	{"aclear", tca_aclear},
	{"acmp", tca_acmp}, {"ancmp", tca_ancmp},
	{"acmpwith", tca_acmpwith}, {"ancmpwith", tca_ancmpwith},
	{"acpy", tca_acpy}, {"alcpy", tca_alcpy},
	{"adup", tca_adup}, {"andup", tca_andup},
	{"afind", tca_afind}, {"afindwith", tca_afindwith},
	{"arfind", tca_arfind}, {"arfindwith", tca_arfindwith},
	{"afree", tca_afree}, {"alen", tca_alen},
	{"amap", tca_amap}, {"anmap", tca_anmap},
	{"arev", tca_arev}, {"anrev", tca_anrev},
	{"atr", tca_atr}, {"antr", tca_antr},
	{"anfree", tca_anfree},
	{NULL, NULL}};

	return (tests);
}

t_module	*arr_module_tests(void)
{
	size_t			i;
	const t_fnamed	*funcs = tca_tests();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "carr", "c-array functions module.");
	while (funcs[i].name)
	{
		add_test_f(args, funcs[i].test, funcs[i].name);
		i++;
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
