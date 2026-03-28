/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tma_ar_scstart.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 16:28:41 by bgoulard          #+#    #+#             */
/*   Updated: 2026/03/28 16:28:41 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arena.h"
#include "ft_list.h"
#include "ft_mem.h"
#include "internal/ft_ar_scope__dev.h"
#include "tests/str__mem_tests.h"

// TODO: tm_cases -> alloc fail

static int	err_cases(void)
{
	char *p;

	ft_ar_scope_start();
	p = ft_calloc(32, -1);
	ft_ar_scope_end();
	if (p != NULL)
		return (1 + 32);
	return (0);
}

static int	many_alloc_case(void)
{
	void	*p[16];
	void	*z[16];
	int		i;

	ft_ar_scope_start();
	i = 0;
	while (i < 16)
		p[i++] = ft_malloc(32);
	i = 0;
	while (i < 16)
		if (p[i++] == NULL)
			return (ft_ar_scope_endall(), i + 8);
	ft_free(p[8]);
	ft_free(p[14]);
	ft_ar_scope_start();
	i = 0;
	while (i < 16)
		z[i++] = ft_calloc(32, 1);
	i = 0;
	while (i < 16)
		if (p[i++] == NULL)
			return (ft_ar_scope_endall(), i + 16 + 8);
	ft_ar_scope_endall();
	return (err_cases());
}

int	tma_ar_scstart(void)
{
	const t_allocator_group	prv = ft_get_allocator(NULL);

	if (ft_get_ar_state()->scopes != NULL
		|| ft_get_ar_state()->underlying.calloc_fn != 0)
		return (1);
	ft_ar_scope_start();
	if (ft_get_ar_state()->scopes == NULL
		|| ft_memcmp(&ft_get_ar_state()->underlying, &prv,
			sizeof(t_allocator_group)) != 0)
		return (ft_ar_scope_endall(), 2);
	if (ft_dl_size(ft_get_ar_state()->scopes) != 1)
		return (ft_ar_scope_endall(), 3);
	ft_ar_scope_start();
	if (ft_dl_size(ft_get_ar_state()->scopes) != 2)
		return (ft_ar_scope_endall(), 4);
	return (ft_ar_scope_endall(), many_alloc_case());
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
