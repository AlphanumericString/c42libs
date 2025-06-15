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

#include "ft_string.h"

#include <stddef.h>
#include <stdio.h>

static bool	is_sorted(void *array, size_t nmb, size_t size,
		int (*cmp)(const void *, const void *))
{
	size_t	i;

	i = 1;
	while (i < nmb)
	{
		if (cmp(array + (i - 1) * size, array + i * size) > 0)
			return (false);
		i++;
	}
	return (true);
}

static void	ft_qsort_swap(void *array, size_t size, size_t left, size_t right)
{
	void	*tmp;

	tmp = ft_calloc(1, size);
	ft_memcpy(tmp, array + left * size, size);
	ft_memcpy(array + left * size, array + right * size, size);
	ft_memcpy(array + right * size, tmp, size);
	ft_free(tmp);
}

/*
** PSEUDO CODE
**
** qsort :
** 1. check if error in args or if array is already sorted
** 2. set left and right to first and last index
** 3. while you didn't find a swap target (left < right)
**	3.1 increase left  while you find an object smaller than index 0
**  3.2 decrease right while you find an object greater than index 0
**  3.3 swap left and right
** 4. swap 0 and right
** 5. qsort left part
** 6. qsort right part
**
*/

void	ft_qsort(void *array, size_t nmb, size_t size,
		int (*cmp)(const void *, const void *))
{
	size_t	left;
	size_t	right;

	if (nmb < 2 || size < 1 || cmp == NULL || array == NULL || is_sorted
		(array, nmb, size, cmp))
		return ;
	left = 0;
	right = nmb - 1;
	while (left < right)
	{
		while (left < nmb && cmp(array + left * size, array) <= 0)
			left++;
		while (right > 0 && cmp(array + right * size, array) > 0)
			right--;
		if (left < right)
			ft_qsort_swap(array, size, left, right);
	}
	ft_qsort_swap(array, size, 0, right);
	if (is_sorted(array, nmb, size, cmp))
		return ;
	ft_qsort(array, right, size, cmp);
	ft_qsort(array + (right + 1) * size, nmb - right - 1, size, cmp);
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
