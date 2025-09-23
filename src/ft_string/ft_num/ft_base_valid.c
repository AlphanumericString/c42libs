/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_valid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgoulard <bgoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 00:54:23 by bgoulard          #+#    #+#             */
/*   Updated: 2025/04/14 00:57:15 by bgoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_char.h"
#include "ft_defs.h"
#include "ft_mem.h"
#include "ft_string.h"
#include <stddef.h>
#include <limits.h>

// prev:
//  base[1]
//   base[2->n] == base[1] ?    - n - 2 checks
//	...
//	base[n - 1]
//	 base[n] == base[n-1] ?		- n - (n-1) checks
//	aka:
//		O(n^2)
//
// ---previous worst case: baselen == ascii table
// 256(strlen) + 32 385(loop) => 32 640
// new worst case:
// 256(strlen) + 4(checks on base lenght) + 256 (loop) => 516
//
// ---most likely case:10
// prev:
// 10(strlen) + 36 => 46
// new:
// 10(strlen) + 4 + 10 => 24

static bool	is_common_base(const char *base, size_t len)
{
	if ((len == 2 && !ft_strcmp(base, FT_BINBASE))
		|| (len == 10 && !ft_strcmp(base, FT_DECBASE))
		|| (len == 16 && !ft_strcmp(base, FT_HEXBASE))
		|| (len == 16 && !ft_strcmp(base, FT_HEXBASE_CAP)))
		return (true);
	return (false);
}

bool	ft_base_valid(const char *base)
{
	bool				arr[256];
	const unsigned char	*b_u = (const unsigned char *)base;
	int					i;
	size_t				len;

	i = 0;
	ft_bzero(arr, 255);
	if (!base)
		return (false);
	len = ft_strnlen(base, 257);
	if (len < 2 || len > UCHAR_MAX)
		return (false);
	if (is_common_base(base, len))
		return (true);
	while (b_u[i])
	{
		if (arr[b_u[i]] != false || !ft_isalnum(base[i]))
			return (false);
		arr[b_u[i++]] = true;
	}
	return (true);
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
