/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tca_alen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/30 10:00:00 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/30 10:00:00 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include "tests/str__mem_tests.h"

int	tca_alen(void)
{
	const int	*arr[] = {NULL};
	const int	*ar2[] = {(int *)1, (int *)2, NULL};
	const char	*ar3[] = {"a", "b", "c", NULL};

	if (ft_alen((t_const_arr)arr)
		|| ft_alen(NULL)
		|| ft_alen((t_const_arr)ar2) != 2
		|| ft_alen((t_const_arr)ar3) != 3)
		return (1);
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
