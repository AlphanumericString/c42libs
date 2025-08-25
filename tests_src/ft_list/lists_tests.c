/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lists_tests.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 12:57:26 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 12:57:26 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests.h"

t_module	*tests_lists(void)
{
	size_t					i;
	const t_mod_constructor	sbm[] = {
		tests_circular_linked_list_all,
		tests_linked_list_all,
		tests_doubly_linked_list_all,
		NULL
	};
	t_module				*module;

	i = 0;
	module = ft_calloc(sizeof(*module), 1);
	init_module(module, "lists", "lists modules.");
	while (sbm[i])
		add_submodule(module, sbm[i++]());
	return (module);
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
