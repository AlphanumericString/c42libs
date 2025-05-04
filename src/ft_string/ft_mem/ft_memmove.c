/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 14:14:49 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/06 23:15:53 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stddef.h>

static	void	*byte_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (dest > src)
		while (n--)
			((unsigned char *)dest)[n] = ((unsigned char *)src)[n];
	else
		while (i++ < n)
			((unsigned char *)dest)[i - 1] = ((unsigned char *)src)[i - 1];
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const void	*ret = dest;

	if (dest == src || !n || !dest || !src)
		return ((void *)ret);
	return (byte_memcpy(dest, src, n));
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
