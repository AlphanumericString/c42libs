/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 12:15:12 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 23:13:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>
#include <limits.h>
#include <stdio.h>

static void	*sword_memchr(const void *s, int c, size_t n)
{
	char		*casted;
	size_t		i;
	const char	target = (char)c;

	casted = (char *)s;
	i = 0;
	while (n != i)
	{
		if (casted[i] == target)
			return (casted + i);
		i++;
	}
	return (NULL);
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	if (c < 0 || c > UCHAR_MAX || !s)
		return (NULL);
	return (sword_memchr(s, c, n));
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
