/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tma_narena.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/29 13:42:22 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 13:52:55 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arena.h"
#include "tests/str__mem_tests.h"

int	tma_narena_belong(void)
{
	void		*ptr_1;
	void		*ptr_2;
	const void	*ptr_3 = (void *)0xDEADBEEF;

	ptr_1 = ft_narena_alloc(FT_NARENA_MAX - 1, 42);
	ptr_2 = ft_narena_alloc(FT_NARENA_MAX - 1, 42);
	if (ft_narena_belongs(FT_NARENA_MAX - 1, ptr_1) != true
		|| ft_narena_belongs(FT_NARENA_MAX - 1, ptr_2) != true
		|| ft_narena_belongs(FT_NARENA_MAX - 1, ptr_3) != false)
		return (ft_narena_free_all(), 1);
	if (ft_narena_belongs(FT_NARENA_MAX - 1, NULL) != false
		|| (ft_narena_belongs(0, ptr_2) != false && FT_NARENA_MAX > 0)
		|| ft_narena_belongs(FT_NARENA_MAX + 1, ptr_2) != false
		|| ft_narena_belongs(-1, ptr_2) != false)
		return (ft_narena_free_all(), 2);
	ft_narena_free_all();
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
