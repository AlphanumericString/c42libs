/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aalloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 23:44:47 by bgoulard          #+#    #+#             */
/*   Updated: 2025/09/07 23:44:47 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_allocator__dev.h"
#include "ft_arr.h"
#include <stddef.h>

void	**ft_aalloc(size_t row, size_t col, size_t cell_size)
{
	void	**arr;
	size_t	i;

	arr = ft_calloc(row + 1, sizeof(void *));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < row)
	{
		arr[i] = ft_calloc(col, cell_size);
		if (!arr[i])
			return (ft_afree(arr), NULL);
		i++;
	}
	return (arr);
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
