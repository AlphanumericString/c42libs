/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_aclear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "tests/tests.h"
#include "tests/str__mem_tests.h"

#include <stdlib.h>

int	tca_aclear(void)
{
	int			*arr[42];
	const int	*arr_2[] = {
		(int *)1, (int *)2, (int *)3, (int *)4, (int *)5, NULL};

	arr[0] = NULL;
	ft_acat((t_iconst_arr)arr, (t_const_arr)arr_2);
	ft_aclear((t_iconst_arr)arr);
	if (ft_alen((t_const_arr)arr) != 0)
		return (1);
	ft_aclear((t_iconst_arr) NULL);
	arr[2] = (int *)42;
	ft_aclear((t_iconst_arr)arr);
	if (ft_alen((t_const_arr)arr) != 0 || arr[2] != (int *)42)
		return (2);
	return (0);
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
