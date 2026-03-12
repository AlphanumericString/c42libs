/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_tests.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 08:30:25 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/11 01:32:11 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"
#include "tests/vector_tests.h"

// TODO: maybe add iterators for :{max min last first} {get} ?

// static const t_fnamed	tests[] = {
// {"acmp", tv_acmp},
// {"add", tv_add},
// {"advance", tv_advance},
// {"ancmp", tv_ancmp},
// {"apply", tv_apply},
// {"at", tv_at},
// {"cat", tv_cat},
// {"clear", tv_clear},
// {"cmp", tv_cmp},
// {"collect", tv_collect},
// {"convert_alloc_array", tv_convert_alloc_array},
// {"create", tv_create},
// {"delete", tv_delete},
// {"destroy", tv_destroy},
// {"dup", tv_dup},
// {"filter-out", tv_filterout},
// {"filter", tv_filter},
// {"findget", tv_findget},
// {"find", tv_find},
// {"fold", tv_fold},
// {"from_array", tv_from_array},
// {"from_size", tv_from_size},
// {"get", tv_get},
// {"iconvert_allocarray", tv_iconvert_allocarray},
// {"ifrom_array", tv_ifrom_array},
// {"init", tv_init},
// {"insert", tv_insert},
// {"inuse", tv_inuse},
// {"map", tv_map},
// {"nadd", tv_nadd},
// {"napply", tv_napply},
// {"ncat", tv_ncat},
// {"ncmp", tv_ncmp},
// {"ncollect_r", tv_ncollect_r},
// {"ncollect", tv_ncollect},
// {"new", tv_new},
// {"nfold_mltp", tv_nfold_mltp},
// {"nfold_r_mltp", tv_nfold_r_mltp},
// {"nfold_r", tv_nfold_r},
// {"nfold", tv_nfold},
// {"ninsert", tv_ninsert},
// {"nmap", tv_nmap},
// {"nremove", tv_nremove},
// {"nrev", tv_nrev},
// {"nset", tv_nset},
// {"nsort", tv_nsort},
// {"nswap", tv_nswap},
// {"pop", tv_pop},
// {"remove", tv_remove},
// {"reserve", tv_reserve},
// {"reverse", tv_reverse},
// {"set", tv_set},
// {"shift", tv_shift},
// {"shrink_min", tv_shrink_min},
// {"shrink", tv_shrink},
// {"sort", tv_sort},
// {"swap", tv_swap},
// {"to_array", tv_to_array},
// {"wipe", tv_wipe},
// {NULL, NULL}
// };

/*

*/
static const t_fnamed	*tv_tests(void)
{
	static const t_fnamed	tests[] = {
	{"acmp", tv_acmp}, {"add", tv_add}, {"advance", tv_advance},
	{"ancmp", tv_ancmp}, {"apply", tv_apply}, {"at", tv_at}, {"cat", tv_cat},
	{"clear", tv_clear}, {"cmp", tv_cmp}, {"collect", tv_collect},
	{"convert_alloc_array", tv_convert_alloc_array}, {"create", tv_create},
	{"delete", tv_delete}, {"destroy", tv_destroy}, {"dup", tv_dup},
	{"filter-out", tv_filterout}, {"filter", tv_filter},
	{"findget", tv_findget}, {"find", tv_find}, {"fold", tv_fold},
	{"from_array", tv_from_array}, {"from_size", tv_from_size},
	{"get", tv_get}, {"iconvert_allocarray", tv_iconvert_allocarray},
	{"ifrom_array", tv_ifrom_array}, {"init", tv_init}, {"insert", tv_insert},
	{"inuse", tv_inuse}, {"map", tv_map}, {"nadd", tv_nadd},
	{"napply", tv_napply}, {"ncat", tv_ncat}, {"ncmp", tv_ncmp},
	{"ncollect_r", tv_ncollect_r}, {"ncollect", tv_ncollect}, {"new", tv_new},
	{"nfold_mltp", tv_nfold_mltp}, {"nfold_r_mltp", tv_nfold_r_mltp},
	{"nfold_r", tv_nfold_r}, {"nfold", tv_nfold}, {"ninsert", tv_ninsert},
	{"nmap", tv_nmap}, {"nremove", tv_nremove}, {"nrev", tv_nrev},
	{"nset", tv_nset}, {"nsort", tv_nsort}, {"nswap", tv_nswap},
	{"pop", tv_pop}, {"remove", tv_remove}, {"reserve", tv_reserve},
	{NULL, NULL}
	};

	return (tests);
}

static const t_fnamed	*tv_tests02(void)
{
	static const t_fnamed	tests[] = {
	{"reverse", tv_reverse}, {"set", tv_set}, {"shift", tv_shift},
	{"shrink_min", tv_shrink_min}, {"shrink", tv_shrink}, {"sort", tv_sort},
	{"swap", tv_swap}, {"to_array", tv_to_array}, {"wipe", tv_wipe},
	{NULL, NULL}
	};

	return (tests);
}

t_module	*tests_vector(void)
{
	int				i;
	const t_fnamed	*funcs = tv_tests();
	const t_fnamed	*funcs2 = tv_tests02();
	t_module		*args;

	i = 0;
	args = ft_calloc(sizeof(*args), 1);
	init_module(args, "vector", "vectors module.");
	while (funcs[i].name)
	{
		add_test_f(args, funcs[i].test, funcs[i].name);
		i++;
	}
	i = 0;
	while (funcs2[i].name)
	{
		add_test_f(args, funcs2[i].test, funcs2[i].name);
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
