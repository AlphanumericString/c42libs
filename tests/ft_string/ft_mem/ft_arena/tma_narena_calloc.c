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
#include "ft_string.h"
#include "tests/str__mem_tests.h"
#include "tests/tests.h"

static int	mt_narena_calloc(void)
{
	const int	fp = *talloc_get_failpoint();
	char		*ptr;

	talloc_set_failpoint(0);
	ptr = ft_narena_calloc(FT_NARENA_MAX / 3, 42, 1);
	if (ptr)
		return (1 + 10);
	talloc_set_failpoint(fp);
	return (0);
}

int	tma_narena_calloc(void)
{
	void	*ptr;

	if (ft_narena_calloc(FT_NARENA_MAX + 1, 42, 1) != NULL
		|| ft_narena_calloc(-1, 42, 1) != NULL)
		return (1);
	ptr = ft_narena_calloc(FT_NARENA_MAX / 2, 42, 1);
	if (!ptr || ft_narena_belongs(FT_NARENA_MAX / 2, ptr) != true)
		return (2);
	ft_strlcpy(ptr, "toto", 42);
	if (ft_strcmp(ptr, "toto"))
		return (3);
	ft_narena_free(FT_NARENA_MAX / 2);
	return (mt_narena_calloc());
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
