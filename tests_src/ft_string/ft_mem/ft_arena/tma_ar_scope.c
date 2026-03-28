/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tma_ar_scope.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antigravity <antigravity@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 15:52:29 by antigravity       #+#    #+#             */
/*   Updated: 2026/03/28 15:52:29 by antigravity      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "ft_allocator__dev.h"
#include "tests/str__mem_tests.h"
#include <stddef.h>

// check with valgrind for double-frees / leaks
// -> leak on ptr1 ->
//		scope-end leaks
// -> double free on ptr2 ->
//		extract fails to remove value
// -> leak on ptr3 ->
//		bad route if not in set
// -> double free on ptr4 ->
//		bad accumulation on ptr allocation
int	tma_ar_scope(void)
{
	void					*ptr1 __attribute__((unused));
	void					*ptr2;
	void					*ptr3 __attribute__((unused));
	void					*ptr4 __attribute__((unused));

	ptr3 = ft_malloc(32);
	ptr4 = ft_malloc(32);
	ft_ar_scope_start();
	ptr1 = ft_malloc(128);
	ft_ar_scope_start();
	ptr2 = ft_malloc(256);
	ft_ar_extract_ptr(ptr2);
	ft_free(ptr3);
	ft_ar_scope_end();
	ft_free(ptr4);
	ft_free(ptr2);
	ft_ar_scope_end();
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
