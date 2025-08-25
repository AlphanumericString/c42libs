/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:10:14 by bgoulard          #+#    #+#             */
/*   Updated: 2025/07/03 01:10:14 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_defs.h"
#include "ft_arr.h"

void	ft_acpy(t_iconst_arr dst, t_const_arr src)
{
	size_t	i;

	if (!dst || !src)
		return ((void) 0);
	i = 0;
	dst[i] = NULL;
	while (src[i])
	{
		dst[i + 1] = NULL;
		dst[i] = src[i];
		i++;
	}
	return ((void)i);
}

// TODO: make AS-Safe ?pushing NULL before the copy if size > 0
void	ft_alcpy(t_iconst_arr dst, size_t size, t_const_arr src)
{
	size_t	src_len;
	size_t	dst_len;

	if (!dst)
		return ((void) size);
	if (!src)
		return ((void) ft_alen(dst));
	if (!size)
		return ((void) ft_alen(src));
	src_len = ft_alen(src);
	dst_len = 0;
	while (dst_len < size - 1 && src[dst_len])
	{
		dst[dst_len] = src[dst_len];
		dst_len++;
	}
	dst[dst_len] = NULL;
	return ((void)src_len);
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
