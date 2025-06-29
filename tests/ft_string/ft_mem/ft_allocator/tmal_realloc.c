/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmal_realloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:59:52 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:44 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "tests/tests__all_modules_tests.h"

static void	reset_allocator(const t_allocator_group prev)
{
	t_allocator_group	*group_test;

	group_test = ft_get_allocator();
	group_test->ptr_free = prev.ptr_free;
	group_test->ptr_alloc = prev.ptr_alloc;
	group_test->ptr_calloc = prev.ptr_calloc;
	group_test->ptr_realloc = prev.ptr_realloc;
	group_test->ptr_reallocarray = prev.ptr_reallocarray;
}

int	tmal_realloc(void)
{
	const t_allocator_group	prev = *ft_get_allocator();
	t_allocator_group		*group_test;
	char					*str;

	ft_set_ft_alloc();
	group_test = ft_get_allocator();
	if (group_test->ptr_realloc != &ft_memimpl_realloc)
		return (1);
	str = ft_calloc(10, sizeof(char));
	str[4] = '4';
	str[5] = '2';
	str = ft_realloc(str, 20 * sizeof(char));
	if (!str || str[4] != '4' || str[5] != '2')
		return (3);
	ft_free(str);
	reset_allocator(prev);
	return (0);
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
