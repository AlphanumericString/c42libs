/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_adup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "tests/str__mem_tests.h"

#include <stdlib.h>
#include <string.h>

static int	mt_adup(void)
{
	const int		fp = *talloc_get_failpoint();
	t_iconst_arr	dst;
	const char		*src[] = {(void *)"a", (void *)"b", (void *)"c", NULL};

	talloc_set_failpoint(0);
	dst = ft_adup((t_const_arr)src);
	talloc_set_failpoint(fp);
	if (dst)
		return (10);
	return (0);
}

static int	mt_andup(void)
{
	const int		fp = *talloc_get_failpoint();
	t_iconst_arr	dst;
	const char		*src[] = {(void *)"a", (void *)"b", (void *)"c", NULL};

	talloc_set_failpoint(0);
	dst = ft_andup((t_const_arr)src, 42);
	talloc_set_failpoint(fp);
	if (dst)
		return (10);
	return (0);
}

int	tca_adup(void)
{
	const char		*arr1[] = {"Hello", "World", "42", NULL};
	t_iconst_arr	dup;

	dup = ft_adup((t_const_arr)arr1);
	if (!dup || ft_alen((t_const_arr)dup) != 3)
		return (1);
	ft_free((t_any)dup);
	dup = ft_adup((t_const_arr) NULL);
	if (dup)
		return (2);
	return (mt_adup());
}

int	tca_andup(void)
{
	const char		*arr1[] = {"Hello", "World", "42", NULL};
	t_iconst_arr	dup;

	dup = ft_andup((t_const_arr)arr1, 42);
	if (!dup || ft_alen((t_const_arr)dup) != 3 || ft_acmp(dup, (t_any)arr1))
		return (1);
	ft_free((t_any)dup);
	dup = ft_andup((t_const_arr)arr1, 1);
	if (!dup || ft_alen((t_const_arr)dup) != 1
		|| ft_strcmp(dup[0], arr1[0]) || dup[1] != NULL)
		return (2);
	ft_free((t_any)dup);
	if (ft_andup((t_const_arr) NULL, 0) != NULL)
		return (3);
	return (mt_andup());
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
