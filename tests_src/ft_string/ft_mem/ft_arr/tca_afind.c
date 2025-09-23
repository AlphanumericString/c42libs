/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_afind.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "ft_string.h"
#include "tests/str__mem_tests.h"

#include <string.h>

int	tca_afind(void)
{
	const int	*arr[] = {
		(int *)1, (int *)2, (int *)3, (int *)4, (int *)5,
		(int *)6, (int *)1, (int *)2, NULL};
	t_const_arr	found;
	const int	*empty_arr[] = {NULL};

	found = ft_afind((t_const_arr)arr, (const void *)2);
	if (!found || *found != (const void *)2 || found[1] != (const void *)3)
		return (1);
	if (ft_afind((t_const_arr)arr, (const void *)42) != NULL
		|| ft_afind((t_const_arr) empty_arr, (const void *)42) != NULL
		|| ft_afind((t_const_arr) NULL, (const void *)42) != NULL
		|| ft_afind((t_const_arr)arr, NULL) != NULL)
		return (2);
	return (EXIT_SUCCESS);
}

int	tca_afindwith(void)
{
	const int	*empty_arr[] = {NULL};
	t_arr		str_arr;
	t_const_arr	elem;

	str_arr = (t_arr)ft_split("hello|42|!", '|');
	elem = ft_afind_with((t_const_arr)str_arr, "42", (t_data_cmp)ft_strcmp);
	if (!elem || elem[0] != str_arr[1] || ft_strcmp(elem[0], "42") != 0)
		return (ft_afree((void **)str_arr), 1);
	if (ft_afind_with((t_const_arr)str_arr, "no", (t_data_cmp)ft_strcmp)
		|| ft_afind_with((t_const_arr)str_arr, NULL, (t_data_cmp)ft_strcmp)
		|| ft_afind_with((t_const_arr) NULL, "42", (t_data_cmp)ft_strcmp)
		|| ft_afind_with((t_const_arr)str_arr, "42", NULL)
		|| ft_afind_with((t_const_arr)empty_arr, "42", (t_data_cmp)ft_strcmp)
		|| ft_afind_with((t_const_arr)empty_arr, NULL, (t_data_cmp)ft_strcmp)
		|| ft_afind_with((t_const_arr)empty_arr, NULL, NULL))
		return (ft_afree((void **)str_arr), 2);
	return (ft_afree((void **)str_arr), 0);
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
