/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 14:54:11 by bgoulard          #+#    #+#             */
/*   Updated: 2025/06/16 16:02:57 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_arr.h"
#include <stddef.h>

void	ft_acat(t_iconst_arr ar_dst, t_const_arr ar_src)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_alen(ar_dst);
	while (ar_src[i])
		ar_dst[j++] = ar_src[i++];
	ar_dst[j] = NULL;
	return ((void) i);
}

void	ft_alcat(t_iconst_arr dst, size_t size, t_const_arr src)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	if (!size || !dst)
		return ((void) 0);
	if (!src)
		return ((void) ft_alen(dst));
	dst_len = ft_alen(dst);
	src_len = ft_alen(src);
	if (dst_len >= size)
		return ((void)(size + src_len));
	i = 0;
	while (src[i] && dst_len + i < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = NULL;
	return ((void)(dst_len + src_len));
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
