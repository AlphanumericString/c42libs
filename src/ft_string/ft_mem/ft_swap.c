/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 11:34:29 by bgoulard          #+#    #+#             */
/*   Updated: 2025/03/26 15:23:38 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include <stddef.h>

// NOTE: might be needing a xor_ibyteop for better optimization
// but it's "fiiine" and im topping out the limit of 5 functions per file

static void	*xor_nbyteop(void *_dst, const void *_src, size_t n)
{
	unsigned char		*dst;
	const unsigned char	*src;
	size_t				i;

	i = 0;
	dst = _dst;
	src = _src;
	while (i < n)
	{
		dst[i] ^= src[i];
		i++;
	}
	return (_dst);
}

// NOTE: this function cannot handle overlapping memory areas
// xor swap is by definition not safe for overlapping memory areas
static void	*xor_nst(void *_dst, const void *_src, size_t n)
{
	size_t			*dst;
	const size_t	*src;
	const size_t	s_size = sizeof(*src);
	size_t			i;

	if ((size_t)_dst % s_size != (size_t)_src % s_size || n < s_size)
		return (xor_nbyteop(_dst, _src, n), _dst);
	i = 0;
	while ((size_t)(_dst + i) % s_size)
	{
		xor_nbyteop((char *)_dst + i, (char *)_src + i, 1);
		i++;
	}
	n -= i;
	dst = _dst + i;
	src = _src + i;
	i = 0;
	while (i < (n / s_size))
	{
		dst[i] ^= src[i];
		i++;
	}
	i = i * s_size + (size_t)dst - (size_t)_dst;
	return (xor_nbyteop(_dst + i, _src + i, n % s_size), _dst);
}

void	ft_swap_ptr(void **a, void **b)
{
	void	*tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_swap_xor(void *a, void *b, size_t size)
{
	if (!a || !b)
		return ;
	xor_nst(a, b, size);
	xor_nst(b, a, size);
	xor_nst(a, b, size);
}

void	ft_swap(void *a, void *b, size_t size)
{
	char	medium_buffer[FT_STD_BUF_SIZE];
	void	*tmp;

	tmp = medium_buffer;
	if (!a || !b || a == b || size == 0)
		return ;
	if (!(a + size > b && a < b + size))
		return (ft_swap_xor(a, b, size), (void)0);
	if (size > FT_STD_BUF_SIZE)
		tmp = ft_malloc(size);
	if (!tmp)
		return ;
	ft_memcpy(tmp, a, size);
	ft_memcpy(a, b, size);
	ft_memcpy(b, tmp, size);
	if (size > FT_STD_BUF_SIZE)
		ft_free(tmp);
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
