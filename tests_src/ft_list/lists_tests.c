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

#include "tests/tests.h"

static const t_module	*tl_modules(void)
{
	static const t_module	md[] = {
	{"simply linked lists", "sll", tests_linked_list_all, 0},
	{"doubly linked lists", "dll", tests_doubly_linked_list_all, 0},
	{"circular linked lists", "cll", tests_circular_linked_list_all, 0},
	{NULL, NULL, NULL, 0},
	};

	return (md);
}

int	tests_lists(int depth)
{
	size_t			i;
	int				collect;
	const t_module	*modules = tl_modules();

	i = 0;
	collect = 0;
	while (modules[i].test)
		collect += run_module(modules[i++], depth);
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
