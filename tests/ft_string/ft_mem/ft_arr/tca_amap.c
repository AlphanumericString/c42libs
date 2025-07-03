/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_amap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:50:17 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 01:54:17 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"
#include "tests/tests.h"
#include <string.h>

static int	mt_tcaamap(void)
{
	const char	*arr[] = {"hello", "world", "42", NULL};
	const int	fp = *talloc_get_failpoint();
	t_arr		result;

	talloc_set_failpoint(0);
	result = ft_amap((t_const_arr)arr, (t_data_tr)ft_strdup);
	talloc_set_failpoint(fp);
	if (result != NULL)
		return (1 + 10);
	return (0);
}

int	tca_amap(void)
{
	const char	*arr[] = {"hello", "world", "42", NULL};
	t_arr		result;

	result = ft_amap((t_const_arr)arr, (t_data_tr)ft_strdup);
	if (!result || ft_alen((t_const_arr)result) != 3
		|| ft_strcmp(result[0], "hello") != 0
		|| ft_strcmp(result[1], "world") != 0
		|| ft_strcmp(result[2], "42") != 0)
		return (ft_afree(result), 1);
	ft_afree(result);
	if (ft_amap(NULL, (t_data_tr)ft_strdup) != NULL
		|| ft_amap((t_const_arr)arr, NULL) != NULL)
		return (2);
	return (mt_tcaamap());
}

static int	mt_tcaanmap(void)
{
	const char	*arr[] = {"hello", "world", "42", NULL};
	const int	fp = *talloc_get_failpoint();
	t_arr		result;

	talloc_set_failpoint(0);
	result = ft_anmap((t_const_arr)arr, 1, (t_data_tr)ft_strdup);
	talloc_set_failpoint(fp);
	if (result != NULL)
		return (1 + 10);
	return (0);
}

int	tca_anmap(void)
{
	const char	*arr[] = {"hello", "world", "42", NULL};
	t_arr		result;

	result = ft_anmap((t_const_arr)arr, 42, (t_data_tr)ft_strdup);
	if (!result || ft_alen((t_const_arr)result) != 3
		|| ft_strcmp(result[0], "hello") != 0
		|| ft_strcmp(result[1], "world") != 0
		|| ft_strcmp(result[2], "42") != 0)
		return (ft_afree(result), 1);
	ft_afree(result);
	result = ft_anmap((t_const_arr)arr, 2, (t_data_tr)ft_strdup);
	if (!result || ft_alen((t_const_arr)result) != 2
		|| ft_strcmp(result[0], "hello") != 0
		|| ft_strcmp(result[1], "world") != 0)
		return (ft_afree(result), 2);
	if (ft_anmap(NULL, 1, (t_data_tr)ft_strdup) != NULL
		|| ft_anmap((t_const_arr)arr, 1, NULL) != NULL)
		return (2);
	ft_afree(result);
	result = ft_anmap((t_const_arr)arr, 0, (t_data_tr)ft_strdup);
	if (!result || ft_alen((t_const_arr)result) != 0)
		return (ft_afree(result), 3);
	return (ft_afree(result), mt_tcaanmap());
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
