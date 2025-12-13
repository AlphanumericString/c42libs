/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_aaloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 08:41:27 by bgoulard          #+#    #+#             */
/*   Updated: 2025/12/13 21:26:03 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/fixtures.h"
#include "tests/str__mem_tests.h"

static int	mt_aaloc(void)
{
	const int	fp = *talloc_get_failpoint();
	t_arr		a;

	talloc_set_failpoint(0);
	a = ft_aalloc(12, 12, 12);
	talloc_set_failpoint(fp);
	if (a != NULL)
		return (ft_afree(a), 3);
	talloc_set_failpoint(*talloc_get_currentpoint() + 1);
	a = ft_aalloc(12, 12, 12);
	talloc_set_failpoint(fp);
	if (a != NULL)
		return (ft_afree(a), 4);
	return (EXIT_SUCCESS);
}

int	tca_aaloc(void)
{
	const char	*str31 = "1234567890123456789012345678901";
	char		**a;

	a = (char **)ft_aalloc(3, 32, sizeof(char));
	if (!a || !a[0] || !a[1] || !a[2] || a[3] != NULL)
		return (1);
	ft_strlcpy(a[0], str31, 32);
	ft_strlcpy(a[1], str31, 32);
	ft_strlcpy(a[2], str31, 32);
	if (ft_strcmp(a[0], str31) || ft_strcmp(a[1], str31)
		|| ft_strcmp(a[2], str31))
		return (ft_afree((void **)a), 2);
	return (ft_afree((t_arr)a), mt_aaloc());
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
