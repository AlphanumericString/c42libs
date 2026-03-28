/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tma_ar_scend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:26:49 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/28 16:26:49 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_defs.h"
#include "internal/ft_ar_scope__dev.h"
#include "tests/str__mem_tests.h"
#include "ft_arena.h"

int	tma_ar_scend(void)
{
	const t_allocator_group	prev = ft_get_allocator(NULL);

	if ((*ft_get_ar_state()).scopes != NULL)
		return (1);
	(ft_ar_scope_end(), ft_ar_scope_end());
	if ((*ft_get_ar_state()).scopes
		|| ft_get_allocator(NULL).calloc_fn != prev.calloc_fn)
		return (2);
	ft_ar_scope_endall();
	if ((*ft_get_ar_state()).scopes)
		return (3);
	(ft_ar_scope_start(), ft_ar_scope_start());
	if ((*ft_get_ar_state()).scopes == NULL
		|| ft_get_allocator(NULL).calloc_fn == prev.calloc_fn)
		return (ft_ar_scope_endall(), 4);
	ft_ar_scope_endall();
	if ((*ft_get_ar_state()).scopes
		|| ft_get_allocator(NULL).calloc_fn != prev.calloc_fn)
		return (5);
	(ft_ar_scope_start(), ft_ar_scope_start());
	(ft_ar_scope_end(), ft_ar_scope_end());
	if ((*ft_get_ar_state()).scopes
		|| ft_get_allocator(NULL).calloc_fn != prev.calloc_fn)
		return (ft_ar_scope_endall(), 6);
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
