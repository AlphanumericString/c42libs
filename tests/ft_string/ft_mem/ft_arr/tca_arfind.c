/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_arfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_string.h"
#include "tests/tests.h"
#include "tests/str__mem_tests.h"

#include <stdio.h>
#include <string.h>

int	tca_arfind(void)
{
	const int	*empty_arr[] = {NULL};
	const int	*arr[] = {
		(int *)1, (int *)2, (int *)3, (int *)4, (int *)5,
		(int *)6, (int *)1, (int *)2, NULL};
	int			*found;

	found = (int *)ft_arfind((t_const_arr)arr, (const void *)2);
	if (!found || found != (int *)2)
		return (1);
	if (ft_arfind((t_const_arr)arr, (const void *)42)
		|| ft_arfind((t_const_arr)empty_arr, (const void *)42)
		|| ft_arfind((t_const_arr) NULL, (const void *)42)
		|| ft_arfind((t_const_arr)arr, NULL)
		|| ft_arfind((t_const_arr) NULL, NULL))
		return (2);
	return (0);
}

int	tca_arfindwith(void)
{
	const int	*empty_arr[] = {NULL};
	t_arr		str_arr;
	const void	*elem;

	str_arr = (t_arr)ft_split("42|hello|42|!", '|');
	elem = ft_arfind_with((t_const_arr)str_arr, "42", (t_data_cmp)ft_strcmp);
	if (!elem || elem != str_arr[2] || ft_strcmp(elem, "42") != 0)
		return (ft_afree((void **)str_arr), 1);
	if (ft_arfind_with((t_const_arr)str_arr, "no", (t_data_cmp)ft_strcmp)
		|| ft_arfind_with((t_const_arr)str_arr, NULL, (t_data_cmp)ft_strcmp)
		|| ft_arfind_with((t_const_arr) NULL, "42", (t_data_cmp)ft_strcmp)
		|| ft_arfind_with((t_const_arr)str_arr, "42", NULL)
		|| ft_arfind_with((t_const_arr)empty_arr, "42", (t_data_cmp)ft_strcmp)
		|| ft_arfind_with((t_const_arr)empty_arr, NULL, (t_data_cmp)ft_strcmp)
		|| ft_arfind_with((t_const_arr)empty_arr, NULL, NULL))
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
