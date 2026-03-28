/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmal_calloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/16 16:59:43 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:36 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "types/ft_allocator_types.h"
#include "tests/str__mem_tests.h"

int	tmal_calloc(void)
{
	const t_allocator_group	prev = ft_get_allocator(NULL);
	t_allocator_group		group_test;

	ft_set_ft_alloc();
	group_test = ft_get_allocator(NULL);
	if (group_test.calloc_fn != &ft_memimpl_calloc)
		return (ft_get_allocator(&prev), 1);
	ft_get_allocator(&prev);
	return (EXIT_SUCCESS);
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
