/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:31:15 by bgoulard          #+#    #+#             */
/*   Updated: 2025/05/25 19:47:39 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "ft_algorithms.h"

void	ft_qsort(void *data, size_t nmb, size_t size, t_data_cmp c)
{
	size_t	left;
	size_t	right;

	if (nmb < 2 || size < 1 || !c || !data || ft_is_sorted(data, nmb, size, c))
		return ;
	left = 0;
	right = nmb - 1;
	while (left < right)
	{
		while (left < nmb && c(data + left * size, data) <= 0)
			left++;
		while (right > 0 && c(data + right * size, data) > 0)
			right--;
		if (left < right)
			ft_swap(data + left * size, data + right * size, size);
	}
	ft_swap(data, data + right * size, size);
	ft_qsort(data, right, size, c);
	ft_qsort(data + (right + 1) * size, nmb - right - 1, size, c);
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
