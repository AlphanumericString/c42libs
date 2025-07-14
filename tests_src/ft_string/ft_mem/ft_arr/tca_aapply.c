/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_aapply.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "ft_defs.h"
#include "tests/str__mem_tests.h"

#include <stdlib.h>

static void	add_one(void *data)
{
	int	*nb;

	nb = (int *)data;
	*nb = *nb + 1;
}

int	tca_aapply(void)
{
	int			arr_data[5];
	const int	*arr_real[] = {
		&arr_data[0], &arr_data[1], &arr_data[2],
		&arr_data[3], &arr_data[4], NULL};
	int			i;

	i = 0;
	while (i < 5)
	{
		arr_data[i] = i;
		i++;
	}
	ft_aapply((t_oconst_arr)arr_real, add_one);
	if (arr_data[0] != 1 || arr_data[1] != 2 || arr_data[2] != 3
		|| arr_data[3] != 4 || arr_data[4] != 5)
		return (1);
	ft_aapply((t_oconst_arr) NULL, add_one);
	return (ft_aapply((t_oconst_arr) arr_data, NULL), 0);
}

int	tca_anapply(void)
{
	int			arr_data[5];
	const int	*arr_real[] = {
		&arr_data[0], &arr_data[1], &arr_data[2],
		&arr_data[3], &arr_data[4], NULL};
	int			i;

	i = 0;
	while (i < 5)
	{
		arr_data[i] = i;
		i++;
	}
	ft_anapply((t_oconst_arr)arr_real, 12, add_one);
	if (arr_data[0] != 1 || arr_data[1] != 2 || arr_data[2] != 3
		|| arr_data[3] != 4 || arr_data[4] != 5)
		return (1);
	ft_anapply((t_oconst_arr)arr_real, 2, add_one);
	if (arr_data[0] != 2 || arr_data[1] != 3 || arr_data[2] != 3
		|| arr_data[3] != 4 || arr_data[4] != 5)
		return (2);
	return (ft_anapply((t_oconst_arr)arr_real, 0, add_one), ft_anapply(
			(t_oconst_arr) NULL, 42, add_one), ft_anapply((t_oconst_arr)
			arr_real, 2, NULL), 0);
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
