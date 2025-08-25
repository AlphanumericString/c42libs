/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tm_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 14:58:16 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/29 14:06:22 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_math.h"
#include "sys/types.h"
#include "tests/math_tests.h"

int	tm_nbrlen(void)
{
	const int	nbrs[] = {0, -9, 42, -42, 666, 2147483647, -2147483648};
	const int	lens[] = {1, 2, 2, 3, 3, 10, 11};
	size_t		i;

	i = 0;
	while (i < sizeof(nbrs) / sizeof(nbrs[0]))
	{
		if (ft_nbrlen((ssize_t)nbrs[i]) != lens[i])
			return (i + 1);
		i++;
	}
	return (0);
}

int	tm_unbrlen_base(void)
{
	const int		bases[4] = {10, 2, 5, 16};
	const ssize_t	nbrs[5] = {0, 23, 42, 666, 2147483647};
	const int		lens[4][5] = {{1, 2, 2, 3, 10},
	{1, 5, 6, 10, 31}, {1, 2, 3, 5, 14},
	{1, 2, 2, 3, 8}};
	size_t			i;
	size_t			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 5)
		{
			if (ft_unbrlen_base((ssize_t)nbrs[i], bases[j]) != lens[j][i])
				return (i + 1 + j * 10);
			i++;
		}
		j++;
	}
	return (0);
}

int	tm_nbrlen_base(void)
{
	const int		bases[4] = {10, 2, 5, 16};
	const int		nbrs[7] = {0, -9, 42, -42, 666, 2147483647, -2147483648};
	const int		lens[4][7] = {{1, 2, 2, 3, 3, 10, 11},
	{1, 5, 6, 7, 10, 31, 33}, {1, 3, 3, 4, 5, 14, 15},
	{1, 2, 2, 3, 3, 8, 9}};
	size_t			i;
	size_t			j;

	j = 0;
	while (j < 4)
	{
		i = 0;
		while (i < 7)
		{
			if (ft_nbrlen_base((ssize_t)nbrs[i], bases[j]) != lens[j][i])
				return (i + 1 + j * 10);
			i++;
		}
		j++;
	}
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
